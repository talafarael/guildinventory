#include <iostream>
#include <string>
#include "json.hpp"
#include "checkUserTimeHunt.h"
#include "addDropAfterHunt.h"
#include "getFileContent.h"
#include "saveUser.h"
void addDropAfterHunt(nlohmann::json& UserData){
    if(UserData["huntDrop"][0]["id"]!=0){
        return;
    }
     int time= UserData["stateHunt"].get<int>();
     std::string itemString= getFileContent("itemDb.json");
     nlohmann::json itemData=nlohmann::json::parse(itemString);
     std::string type="dropped by mob";
     bool stateHunt= checkUserTimeHunt(time);
     if(!stateHunt){
        std::cout<<"you dont go to the hunter";
        return;
     }
int id=0;

while (id==0){
        int i=std::rand()%itemData["items"].size();
    if(itemData["items"][i]["obtainedBy"].get<std::string>()==type){


        bool chance=itemData["items"][i]["dropChance"].get<int>();
       if(chance*100>std::rand()%100){
        continue;
       }


        int countItem=itemData["items"][i]["stack"];
               if(countItem!=1){
            countItem= std::floor(countItem/3);
        }

UserData["huntDrop"][0]["id"]=itemData["items"][i]["id"];
UserData["huntDrop"][0]["count"]=countItem;
id=itemData["items"][i]["id"];
break;
     }
     }
    
     saveUser(UserData);


}