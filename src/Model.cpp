#include <iostream>
#include <base-logging/Logging.hpp>

#include "Model.hpp"

#include <yaml-cpp/yaml.h>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/lambda/bind.hpp>

using namespace std;
using namespace performance_map;
using namespace boost::filesystem;
using namespace boost::lambda;

Model::Model(const std::string & path)
{ 
    this->mPath = path;
    reshapeAllConfigFiles();
    mNumConfigSets = countConfigSets();
    // TODO Count ConfigSets using the correct config files
};

int Model::countConfigSets()
{
    path thePath = mPath + SAMPLES_BYTASK_PATH;
    int numConfigs =  std::count_if(directory_iterator(thePath), directory_iterator(), static_cast<bool(*)(const path&)>(is_regular_file));
    return numConfigs / NUM_TASKS;

}

std::vector<std::string> Model::getTasksNames()
{
    return { TASK_NAME_TF, TASK_NAME_MPL, TASK_NAME_TVT};
}


void Model::reshapeAllConfigFiles()
{
    boost::filesystem::path path(mPath + SAMPLES_PATH);
    int counter = 0;
    boost::filesystem::directory_iterator begin(path), end;
    for (auto i=begin; i!=end; i++)
    {
        boost::filesystem::path fe = i->path().extension();
        if (fe.string() == ".yml")
        {
            reshape_config_file(counter);
            counter++;
        }
    }
}

YAML::Node Model::get_max_performance_and_id(){
    double max = 0.0;
    YAML::Node resul;
    YAML::Node ids_performances;
    try 
    {
        ids_performances = YAML::LoadFile(mPath + IDS_PERFORMANCES_FILE);
    }
    catch (...)
    {
        LOG_ERROR_S << "Unable to load file: " + mPath + IDS_PERFORMANCES_FILE;
        throw;
    }
    for (YAML::Node::const_iterator it=ids_performances.begin(); it!=ids_performances.end(); ++it){
        YAML::Node map = *it;
        double performance = map[PERFORMANCE_LABEL].as<double>();
        if (max < performance)
        {
            resul = map;
            max = performance;
        }
    }
    return resul;
}



void Model::reshape_config_file(int id)
{
    YAML::Node all_configs = YAML::LoadFile(mPath + SAMPLES_PATH + "/" + std::to_string(id) + ".yml" );
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
            boost::filesystem::path dir(mPath+SAMPLES_BYTASK_PATH);
            if(!(boost::filesystem::exists(dir)))
            {
                std::cout<<"The path " << mPath +SAMPLES_BYTASK_PATH<< " doesn't Exists"<<std::endl;
                if (boost::filesystem::create_directory(dir))
                    std::cout << "....Successfully Created !" << std::endl;
                else
                    std::cout << "....Cannot be Created !" << std::endl;
            }
            std::string filename = mPath+SAMPLES_BYTASK_PATH+"/"+key+"_"+std::to_string(id)+".yml";
            std::ofstream task_file (filename, std::ofstream::out);
            task_file << file_content;
            task_file.close();
            //std::cout << "---- closed file with name " << filename << std::endl;
        }
    }
}

std::vector<std::string> Model::getConfigPaths(int id)
{

    std::vector<std::string> result;
    /*
    YAML::Node all_configs = YAML::LoadFile(mPath + SAMPLES_PATH + "/" + std::to_string(id) + ".yml" );
    for (YAML::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
        std::string key = it->first.as<std::string>();
        if ((key != ID_LABEL) and (key != OVERPASSED_LABEL))
        {
            std::string filename = mPath+SAMPLES_BYTASK_PATH+"/"+key+"_"+std::to_string(id)+".yml";
            result.push_back(filename);
        }
    }
    */
    std::vector<std::string> tasksNames = getTasksNames();
    for (auto it : tasksNames){
        std::string filename = mPath+SAMPLES_BYTASK_PATH+"/"+it+"_"+std::to_string(id)+".yml";
        std::cout << "[Model::getConfigPaths] path :"<< filename << std::endl;
        result.push_back(filename);
    }
    return result;
}

ConfigSet Model::get_best_config(){
    // Go through all the ids, select the one with highest performance and return the correspondent config set
    //int id = 0;
    //configmaps::ConfigMap map;
    //map = configmaps::ConfigMap::fromYamlFile("test.yml");
    //configmaps::ConfigVector::iterator it;
    //for(it=map["list"].begin(); it!=map["list"].end(); ++it) {
    //  printf("list entry: %s\n", it->getString().c_str());
    //}
    YAML::Node id_performance = get_max_performance_and_id();
    int id = id_performance[ID_LABEL].as<int>();
    ConfigSet result(id);
    std::cout <<"[Model::get_best_config] before get_config_paths " << std::endl;
    result.paths = getConfigPaths(id);
    std::cout <<"[Model::get_best_config] result.paths[0] " << result.paths[0] << std::endl;
    return result;
}



double Model::get_max_performance(){
    YAML::Node best = get_max_performance_and_id();
    return best[PERFORMANCE_LABEL].as<double>();
}

//bool Model::storeConfigSet(std::vector<std::string> configsPaths)
//{
//    mNumConfigSets++;
//
//
//
//}
void Model::storeConfigSet(const ConfigSet& configSet)
{
    mNumConfigSets++;

    // It should store the values in the correspondent files and set paths to those, but how are the values given?
    // I think that the config set should also contain a list of tasks and a list of parameters per task, this is given to the generator which sets this values. Or the generator is configured and the configSet just stores whatever the generator provides

}
