#include <iostream>
#include <fstream>
#include "getItemGuild.h"
#include <string>
#include "json.hpp"
#include "getFileContent.h" 
#include "findItemId.h"
#include "dataMatrixInput.h"
void getItemGuild(nlohmann::json& UserData){
    
   std::string GuildInventoryString= getFileContent("GildInventory.json");
      std::string UsersString= getFileContent("user.json");
  nlohmann::json GuildInventory=nlohmann::json::parse(GuildInventoryString);
  // std::cout<<UsersString;
   nlohmann::json Users=nlohmann::json::parse(UsersString);
    int freeCell;
    int freeCellCount;
    int column,row ,count;
    
   dataMatrixInput( column, row, count);
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
         std::cout<<item<<std::endl;
    for(int i=0;i<UserData["inventory"].size();i++){
      int cell= UserData["inventory"][i]["id"];

      if(cell==0){
        freeCell++;
      }

      if(cell==item["id"]){
       if(UserData["inventory"][i]["count"]<item["stack"]){

  freeCellCount+= item["stack"].get<int>() - UserData["inventory"][i]["count"].get<int>();

          }
      }
}
if(freeCellCount<count&&freeCell==0){
  std::cout<<"you dont have free cell"<<std::endl;
  return;
} 

if(freeCellCount>0){
  std::cout<<"filling in free cells";
for(int i=0;i<UserData["inventory"].size();i++){
    int cell= UserData["inventory"][i]["id"];
    if(count==0){
      break;
    }
    if(cell==item["id"]){
      if(UserData["inventory"][i]["count"]>=item["stack"].get<int>()){
        // если заполнена яччейка
      continue;
      }
      
      if(UserData["inventory"][i]["count"].get<int>()+count<=item["stack"].get<int>()){
          UserData["inventory"][i]["count"]=UserData["inventory"][i]["count"].get<int>()+count;
         GuildInventory["inventory"][column][row]["count"]=GuildInventory["inventory"][column][row]["count"].get<int>()-count;
        count =0;
        break;
      }else{
        int  freeCount= item["stack"].get<int>() - UserData["inventory"][i]["count"].get<int>();
        count =count -freeCount;
        GuildInventory["inventory"][column][row]["count"]=GuildInventory["inventory"][column][row]["count"].get<int>()-freeCount;;
        UserData["inventory"][i]["count"]=item["stack"].get<int>();
      }
    }
}
}
if(count>0){
for(int i=0;i<UserData["inventory"].size();i++){
     int cell= UserData["inventory"][i]["id"];
   if(cell==0){
     UserData["inventory"][i]["id"]=id;
      UserData["inventory"][i]["count"]=count;
      GuildInventory["inventory"][column][row]["count"]=GuildInventory["inventory"][column][row]["count"].get<int>()-count;
      count=0;
      break;
}
}  
}
if(GuildInventory["inventory"][column][row]["count"]==0){
GuildInventory["inventory"][column][row]["id"]=0;
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