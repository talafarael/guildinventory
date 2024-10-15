#include <iostream>
#include "json.hpp"
#include "dataMatrixInput.h"
#include "findItemId.h"
#include "saveUser.h"
#include "confirmation.h"
void sellItem(nlohmann::json& UserData){
     int column,row ,count;

   dataMatrixInput(column, row, count);
    int id=UserData["inventory"][column*7+row]["id"];
    nlohmann::json item=findItemId(id);
    if(count>UserData["inventory"][column*7+row]["count"]){
        std::cout<<"you want sell so much";
        return;
    }
  if(confirmation()){
    return;
  }
  int endCount=UserData["inventory"][column*7+row]["count"].get<int>()-count;
  int allGold=UserData["gold"].get<int>()+item["sell"].get<int>()*count;
  UserData["gold"]=allGold;

  UserData["inventory"][column*7+row]["count"]=endCount;
  if(UserData["inventory"][column*7+row]["count"]==0){
    UserData["inventory"][column*7+row]["id"]=0;
  }
   saveUser(UserData);
}

