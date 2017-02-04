#include <iostream>
#include <base-logging/Logging.hpp>

#include "Model.hpp"

#include <yaml-cpp/yaml.h>
#include <fstream>


#include <boost/range/iterator_range.hpp>
#include <boost/lambda/bind.hpp>

using namespace std;
using namespace performance_map;
using namespace boost::filesystem;
using namespace boost::lambda;

Model::Model(const std::string & path)
{ 
    init(path);
};

void Model::init(const std::string & path)
{ 
    mPath  = path + SAMPLES_PATH;
    LOG_DEBUG_S << "[Model::init] Path: " << mPath;
    mPathByTask = path + SAMPLES_BYTASK_PATH;
    mPathIdsPerformance = path + IDS_PERFORMANCES_FILE; 
    if (boost::filesystem::exists(mPath))
    {
        reshapeAllConfigFiles();
        mNumConfigSets = countConfigSets();
        // TODO Count ConfigSets using the correct config files
    }
    else
    {
        LOG_DEBUG_S << "[Model::init] Unexistent path: " << mPath;
    }
};

int Model::countConfigSets()
{
    int numConfigs =  std::count_if(directory_iterator(mPathByTask), directory_iterator(), static_cast<bool(*)(const path&)>(is_regular_file));
    return numConfigs / NUM_TASKS;
}

std::vector<std::string> Model::getTasksNames()
{
    return { TASK_NAME_TF, TASK_NAME_MPL, TASK_NAME_TVT};
}


void Model::reshapeAllConfigFiles()
{
    int counter = 0;
    boost::filesystem::directory_iterator begin(mPath), end;
    for (auto i=begin; i!=end; i++)
    {
        boost::filesystem::path fe = i->path().extension();
        if (fe.string() == ".yml")
        {
            reshapeConfigFile(counter);
            counter++;
        }
    }
}

YAML::Node Model::getMaxPerformanceAndId(){
    double max = 0.0;
    YAML::Node resul;
    try 
    {
        YAML::Node ids_performances = YAML::LoadFile(mPathIdsPerformance.string());
        for (YAML::Node::const_iterator it=ids_performances.begin(); it!=ids_performances.end(); ++it){
            YAML::Node map = *it;
            double performance = map[PERFORMANCE_LABEL].as<double>();
            if (max < performance)
            {
                resul = map;
                max = performance;
            }
        }
    }
    catch (...)
    {
        LOG_ERROR_S << "[Model::getMaxPerformanceAndId] Unable to load file: " + mPathIdsPerformance.string();
        throw;
    }
    return resul;
}

void Model::reshapeConfigFile(int id)
{
    std::string filename = mPath.string() + "/" + std::to_string(id) + ".yml";
    try 
    {
        YAML::Node all_configs = YAML::LoadFile(filename);
        std::vector<std::string> tasks;
        for (YAML::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
            // find out the name of the tasks
            std::string key = it->first.as<std::string>();
            if ((key != ID_LABEL) and (key != OVERPASSED_LABEL))
            {
                // Key corresponds to a task. Improve the yml so that the tasks are stored as a list in its own dictionary entry
                tasks.push_back(it->first.as<std::string>());
                YAML::Node file_content;
                file_content[TASK_NAME_LABEL] = key;
                std::string taskType;
                if (key == TASK_NAME_TF)
                    taskType = "trajectory_follower::Task";
                if (key == TASK_NAME_MPL)
                    taskType = "motion_planning_libraries::Task";
                if (key == TASK_NAME_TVT)
                    taskType = "traversability::Simple";
                file_content[TASK_TYPE_LABEL] = taskType;
                file_content[SECTION_LABEL][id] = all_configs[key];
                // Check that the byTask dir exists and create if not
                if(!(boost::filesystem::exists(mPathByTask)))
                {
                    std::cout<<"The path " << mPath.string() +SAMPLES_BYTASK_PATH<< " doesn't Exists"<<std::endl;
                    if (boost::filesystem::create_directory(mPathByTask))
                        std::cout << "....Successfully Created !" << std::endl;
                    else
                        std::cout << "....Cannot be Created !" << std::endl;
                }
                std::string filename = mPathByTask.string()+"/"+key+"_"+std::to_string(id)+".yml";
                std::ofstream task_file (filename, std::ofstream::out);
                task_file << file_content;
                task_file.close();
            }
        }
    }
    catch (...)
    {
        LOG_ERROR_S << "[Model::reshapeConfigFile] Error loading yaml node from: " << filename;
        throw;
    }
}

std::vector<std::string> Model::getConfigPaths(int id)
{

    std::vector<std::string> result;
    std::vector<std::string> tasksNames = getTasksNames();
    for (auto it : tasksNames){
        std::string filename = mPathByTask.string()+"/"+it+"_"+std::to_string(id)+".yml";
        std::cout << "[Model::getConfigPaths] path :"<< filename << std::endl;
        result.push_back(filename);
    }
    return result;
}

ConfigSet Model::getBestConfig(){
    // Go through all the ids, select the one with highest performance and return the correspondent config set
    //int id = 0;
    //configmaps::ConfigMap map;
    //map = configmaps::ConfigMap::fromYamlFile("test.yml");
    //configmaps::ConfigVector::iterator it;
    //for(it=map["list"].begin(); it!=map["list"].end(); ++it) {
    //  printf("list entry: %s\n", it->getString().c_str());
    //}
    YAML::Node id_performance = getMaxPerformanceAndId();
    int id = id_performance[ID_LABEL].as<int>();
    ConfigSet result(id);
    std::cout <<"[Model::getBestConfig] before getConfigPaths " << std::endl;
    result.paths = getConfigPaths(id);
    std::cout <<"[Model::getBestConfig] result.paths[0] " << result.paths[0] << std::endl;
    return result;
}



double Model::getMaxPerformance(){
    YAML::Node best = getMaxPerformanceAndId();
    return best[PERFORMANCE_LABEL].as<double>();
}

void Model::storeConfigSet(const ConfigSet& configSet)
{
    mNumConfigSets++;

    // It should store the values in the correspondent files and set paths to those, but how are the values given?
    // I think that the config set should also contain a list of tasks and a list of parameters per task, this is given to the generator which sets this values. Or the generator is configured and the configSet just stores whatever the generator provides

}
