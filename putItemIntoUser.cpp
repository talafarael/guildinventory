#include <iostream>
#include "putItemIntoUser.h"
#include "json.hpp"
#include "findItemId.h"

bool checkpossibilityPut(nlohmann::json& UserData, const nlohmann::json& item, int& count, int& freeCell, int& freeCellCount) ;

void putItemIntoUser(nlohmann::json& UserData,int& id,int& count,  int& freeCell, int& freeCellCount) {
     nlohmann::json item= findItemId(id);
  //freCell -полность свободіне слоті 
  // freeCellCount свободное место


bool error=checkpossibilityPut(UserData, item, count, freeCell, freeCellCount);
if(!error)  {
    return;
}


if(freeCellCount>0){
 
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
      int guildInventoryCount=UserData["inventory"][i]["count"].get<int>()+count;
       std::cout<<guildInventoryCount<<std::endl;
      if(guildInventoryCount<=item["stack"].get<int>()){
          UserData["inventory"][i]["count"]=guildInventoryCount;
        
        count =0;
        break;
      }else{
        int  freeCount= item["stack"].get<int>() - UserData["inventory"][i]["count"].get<int>();
        count =count -freeCount;
       
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
      count=0;
      break;
}
}  
}


}

bool checkpossibilityPut(nlohmann::json& UserData, const nlohmann::json& item, int& count, int& freeCell, int& freeCellCount) {
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

//error
if(freeCellCount<count&&freeCell==0){
  std::cout<<"you dont have free cell"<<std::endl;
  return false;
} 
return true;
}




