#include <iostream>
#include "json.hpp"
#include "putItem.h"
#include "dataMatrixInput.h"
#include "findItemId.h"
#include <fstream>
#include "getFileContent.h" 
void checkCell();
void putItem(nlohmann::json& UserData){
 std::string GuildInventoryString= getFileContent("GildInventory.json");
 std::string UsersString= getFileContent("user.json");
   nlohmann::json GuildInventory=nlohmann::json::parse(GuildInventoryString);
   nlohmann::json Users=nlohmann::json::parse(UsersString);
 int column,row,count;
 int CellCount=0;
  int freeCell=0;
 dataMatrixInput(column,row,count);
 int countItem=count;
   int id=UserData["inventory"][column*7+row]["id"];
    if(id==0){
        std::cout<<"empty cell";
        return;
    }
    nlohmann::json item= findItemId(id);
    if(count> UserData["inventory"][column*7+row]["count"]){
        std::cout<<"you get so more plase get less";
        return;
    }
    for(int i=0;i<GuildInventory["inventory"].size();i++){
        for(int j=0;j<GuildInventory["inventory"][i].size();j++){
        
            if(GuildInventory["inventory"][i][j]["id"]==0){
                freeCell++;
                continue;
            }
        if(GuildInventory["inventory"][i][j]["id"]==id){
        if(GuildInventory["inventory"][i][j]["count"].get<int>()+count<=item["stack"].get<int>()){
            GuildInventory["inventory"][i][j][count]+=count;
            freeCell++;
            count=0;
            break;
        }else{
          CellCount+= item["stack"].get<int>()-GuildInventory["inventory"][i][j]["count"].get<int>();
        }
     }

    } 
    }
    if(freeCell==0 &&freeCell<count){
         std::cout<<"guild bank dont have free cell"<<std::endl;
  return;
    }
    if(freeCell>0&&count>0){


 for(int i=0;i<GuildInventory["inventory"].size();i++){ 
    if(count==0){
       break;
    }
        for(int j=0;j<GuildInventory["inventory"][i].size();j++){
            if(GuildInventory["inventory"][i][j]["id"]==0){
               continue;
            }

if(GuildInventory["inventory"][i][j]["id"]==id){
    if(GuildInventory["inventory"][i][j]["count"].get<int>()+count<=item["stack"]){
        
            GuildInventory["inventory"][i][j]["count"]=GuildInventory["inventory"][i][j]["count"].get<int>()+count;
            count=0;
            break;
        }else{
        int countFree=item["stack"].get<int>()-GuildInventory["inventory"][i][j]["count"].get<int>();
        
        count=count-countFree;
        GuildInventory["inventory"][i][j]["count"]=item["stack"].get<int>();
}

        }
        }
    }
}


if(count>0){
     for(int i=0;i<GuildInventory["inventory"].size();i++){
         if(count==0){
    break;
}
        for(int j=0;j<GuildInventory["inventory"][i].size();j++){
            
if(GuildInventory["inventory"][i][j]["id"].get<int>()==0){
    GuildInventory["inventory"][i][j]["id"]=id;
      GuildInventory["inventory"][i][j]["count"]=count;
      count=0;
      break;
}

        }}
}


if(UserData["inventory"][column*7+row]["count"].get<int>()-countItem==0){
    UserData["inventory"][column*7+row]["count"]=0;
    UserData["inventory"][column*7+row]["id"]=0;
}else{
     UserData["inventory"][column*7+row]["count"]=UserData["inventory"][column*7+row]["count"].get<int>()-countItem;
}
 std::ofstream file("GildInventory.json");
  if (file.is_open()) {
        file << GuildInventory.dump(5); 
        file.close(); 
    } 
   std::cout<<"user goi";
for(int i=0;i<Users[i].size();i++){
  if(!Users[i].is_null() && Users[i]["name"].get<std::string>()==UserData["name"].get<std::string>()){
     Users[i]["inventory"]=UserData["inventory"];
  break;
  }
}
 std::ofstream fileUser("user.json");
  if (fileUser.is_open()) {
        fileUser << Users.dump(5); 
        fileUser.close(); 
    } 
   


}