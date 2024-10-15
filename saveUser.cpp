#include <iostream>
#include "json.hpp"
#include <fstream>
#include "saveUser.h"
#include "getFileContent.h" 
#include "findItemId.h"
void saveUser(nlohmann::json& UserData){
       std::string UsersString= getFileContent("user.json");
 

   nlohmann::json Users=nlohmann::json::parse(UsersString);
    for(int i=0;i<Users[i].size();i++){
  if(!Users[i].is_null() && Users[i]["name"].get<std::string>()==UserData["name"].get<std::string>()){
     Users[i]["inventory"]=UserData["inventory"];
      Users[i]["gold"]=UserData["gold"];
      Users[i]["stateHunt"]= UserData["stateHunt"];
     Users[i]["huntDrop"][0]["id"]=UserData["huntDrop"][0]["id"];
Users[i]["huntDrop"][0]["count"]= UserData["huntDrop"][0]["count"];
Users[i]["stateHunt"]=UserData["stateHunt"];
  break;
  }
}
 std::ofstream fileUser("user.json");
  if (fileUser.is_open()) {
        fileUser << Users.dump(5); 
        fileUser.close(); 
    } 
}