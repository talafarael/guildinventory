#include <iostream>
#include <fstream>
#include "getItemGuild.h"
#include <string>
#include "json.hpp"
#include "getFileContent.h" 
#include "findItemId.h"
#include "saveUser.h"
#include "dataMatrixInput.h"
#include "putItemIntoUser.h"
void getItemGuild(nlohmann::json& UserData){
    
   std::string GuildInventoryString= getFileContent("GildInventory.json");

  nlohmann::json GuildInventory=nlohmann::json::parse(GuildInventoryString);

    int freeCell;
    int freeCellCount=0;
    int column,row ,count;
    
   dataMatrixInput( column, row, count);
   int getCount=count;
    int id=GuildInventory["inventory"][column][row]["id"];
    if(id==0){
        std::cout<<"empty cell";
        return;
    }
    nlohmann::json item= findItemId(id);
    
    if(count> GuildInventory["inventory"][column][row]["count"]){
        std::cout<<"you get so more plase get less";
        return;
    }

putItemIntoUser(UserData, id, count,  freeCell, freeCellCount);





GuildInventory["inventory"][column][row]["count"]=GuildInventory["inventory"][column][row]["count"].get<int>()-getCount;
if(GuildInventory["inventory"][column][row]["count"]==0){
GuildInventory["inventory"][column][row]["id"]=0;
}

 std::ofstream file("GildInventory.json");
  if (file.is_open()) {
        file << GuildInventory.dump(5); 
        file.close(); 
    } 


   saveUser(UserData);
}