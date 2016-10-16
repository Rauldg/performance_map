#include "Controller.cpp"
#include <iostream>

#include <configmaps/ConfigData.h>

using namespace std;
using namespace performance_map;
using namespace configmaps;

ConfigSet Model::get_best_config(){
    // Go through all the ids, select the one with highest performance and return the correspondent config set
    int id = 0;
    //configmaps::ConfigMap map;
    //map = configmaps::ConfigMap::fromYamlFile("test.yml");
    //configmaps::ConfigVector::iterator it;
    //for(it=map["list"].begin(); it!=map["list"].end(); ++it) {
    //  printf("list entry: %s\n", it->getString().c_str());
    //}

    ConfigSet result(id);
    return result;
}

double Model::get_max_performance(){
    double max = 0.0;
    configmaps::ConfigMap map;
    map = configmaps::ConfigMap::fromYamlFile(path + "/bpms/bpm.yml");
    configmaps::ConfigVector::iterator it;
    
    /*
    // Returns empty dictionary
    configmaps::ConfigMap map0 = map["bmp"][0];
    map0.toYamlFile("map0.yml");

    // Fails on runtime
    configmaps::ConfigMap bmp = map["bmp"];
    bmp.toYamlFile("bmp.yml");
    */

    //double performance0 = map0[0]["performance"];
    //printf("Performance: %f\n", performance0);
    
    printf("Executed ");

    double performance = 0.8;
    int id = 12;

    configmaps::ConfigMap testMap;
    testMap["id"] = id;
    testMap["performance"] = performance;

    configmaps::ConfigVector testVector;
    testVector.append(testMap);

    testVector.toYamlFile("testVector.yml");

    configmaps::ConfigMap testMap2;
    testMap2 = testVector[0];
    printf("Test Map 2 id: %d\n", (int)testMap2["id"] );
    printf("Test Map 2 performance: %f\n", (double)testMap2["performance"] );


    for(it=map["bpm"].begin(); it!=map["bpm"].end(); ++it) {
      ConfigVector * bpm = it->getOrCreateVector();
      configmaps::ConfigVector::iterator itv;
      ////for(itv=map["bpm"]["performance"].begin(); itv!=bpm["bpm"]["performance"].end(); ++itv) {

      for(itv=bpm->begin(); itv!=bpm->end(); ++itv) {
          ConfigVector * tuples = itv->getOrCreateVector();
          int i = 0;

          configmaps::ConfigVector::iterator itt;
          for(itt=tuples->begin(); itt!=tuples->end(); ++itt) {
               ConfigMap individual;
               individual = tuples[i][0];
               i++;
               printf("Individual id: %d\n", (int)individual["id"] );
               int id_aux = individual.get("id", -1);
               std::string id_aux_s = individual.get("id", (std::string)"empty");

               printf("Individual id: %d\n", id_aux );
               printf("Individual id: %s\n", id_aux_s.c_str());
               printf("Individual performance: %f\n", (double)individual["performance"] );
              //ConfigVector * foo = itt->getOrCreateVector();
              //foo -> toYamlFile("foo_"+std::to_string(i)+"_"+".yml");
              //ConfigItem * configItem = &itt;
              //printf("Performance: %s\n", itt->getString().c_str());
          }

          //ConfigMap individual;
          //individual = bpm[i][0];
          //i++;
          //printf("Individual id: %d\n", (int)individual["id"] );
          //printf("Individual performance: %f\n", (double)individual["performance"] );
          //ConfigVector * tuple = itv->getOrCreateVector();
          //tuple -> toYamlFile("tuple_"+std::to_string(i)+"_"+".yml");
          //i++;
          


          //for(itt=tuple->begin(); itt!=tuple->end(); ++itt) {
          //    ConfigVector * foo = itt->getOrCreateVector();
          //    foo -> toYamlFile("foo_"+std::to_string(i)+"_"+".yml");
          //    //ConfigItem * configItem = &itt;
          //    //printf("Performance: %s\n", itt->getString().c_str());
          //}
          //ConfigItem * item = tuple[0]; // Seems to be a ConfigVector too? This says item is of wrong type
          
          //printf("Performance: %s\n", *tuple[0].c_str());
          //printf("Performance: %f\n", performance);
          
          
      //    ConfigMap * tuple = itv->();
      //    double performance = *tuple["performance"];
      //    //printf("Performance: %s\n", itv->getString().c_str());
      //    //printf("Performance: %f\n", performance.c_str());


      //  //double performance = *tuple["performance"];
      //  //v2 -> toYamlFile("v2_test_configmaps_"+std::to_string(i)+"_"+std::to_string(j)+".yml");
      //  //printf("list entry: %s\n", itv->getString().c_str());
      //  //printf("list entry: %s\n", it->getString().c_str());
      }
      //bpm -> toYamlFile("vector_test_configmaps"+std::to_string(i)+".yml");
    }
    return max;
}
