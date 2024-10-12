#include <iostream>
#include "getItemGuild.h"
#include <string>
#include "json.hpp"
#include "getFileContent.h" 
#include "findItemId.h"
void getItemGuild(nlohmann::json& UserData){
    
   std::string GuildInventoryString= getFileContent("GildInventory.json");
  nlohmann::json GuildInventory=nlohmann::json::parse(GuildInventoryString);
  int freeCell;
    int row;
    int column;
    int count;
    std::cout<<"plese enter Row:";
    std::cin>>row;
    std::cout<<"plese enter Column:";
    std::cin>>column;
    std::cout<<"enter count";
    std::cin>>count;
    int id=GuildInventory["inventory"][row][column]["id"];
    if(id==0){
        std::cout<<"empty cell";
        return;
    }
    nlohmann::json item= findItemId(id);
    std::cout<<UserData;
    if(count> GuildInventory["inventory"][row][column]["count"]){
        std::cout<<"you get so more plase get less";
        return;
    }
    for(int i=0;i<UserData["inventory"].size();i++){
      int cell= UserData["inventory"][i]["id"];
      if(cell==0){
        freeCell++;
      }
      if(cell==item["id"]){
        std::cout<<UserData["inventory"][i];
        std::cout<<item;
        //   if(UserData["inventory"][i]["count"]==item["count"]){

        //   }
      }
    }


   
}