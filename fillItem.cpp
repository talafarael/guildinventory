#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>  
#include <ctime>   
#include "fillItem.h"
#include "json.hpp" 
#include "getFileContent.h"
#include <ctime>
void filllItem(std::string& type,int count,std::string& file){
std::string jsonString= getFileContent(file);
std::string itemString= getFileContent("itemDb.json");
nlohmann::json itemData=nlohmann::json::parse(itemString);
    if(jsonString.empty()){
    nlohmann::json newInventory = {{"inventory", nlohmann::json::array()},{"time",0}};
   jsonString = newInventory.dump();
    }
nlohmann::json json=nlohmann::json::parse(jsonString);
int y=0;
while(y<=count){
    int i=std::rand()%itemData["items"].size();
    if(itemData["items"][i]["obtainedBy"].get<std::string>()==type){
       
        int countItem=itemData["items"][i]["stack"];
       
        if(countItem!=1){
            countItem= std::floor(countItem/3);
        }
       
json["inventory"][y]["count"]=countItem;
json["inventory"][y]["id"]=itemData["items"][i]["id"];
++y;

    } 
}

    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
json["time"]=start_time;
 std::ofstream files(file);
  files<<json.dump(5);
 

  files.close();

}