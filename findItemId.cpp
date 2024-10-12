#include <iostream>
#include <string>
#include "findItemId.h"
#include "json.hpp"
#include "getFileContent.h"

nlohmann::json findItemId(int& id){
   std::string ItemData= getFileContent("itemDb.json");
   nlohmann::json ItemDb=nlohmann::json::parse(ItemData);
    nlohmann::json item;
    for(int i=0;i<ItemDb["items"].size();i++){
        if(ItemDb["items"][i]["id"]==id){
            item=ItemDb["items"][i];
        }
    }
    return item;
}