#include <iostream>
#include <string>
#include "json.hpp"

#include "getFileContent.h"
#include "putItemIntoUser.h"
#include "saveUser.h"
void getItemAfterHunter(nlohmann::json& UserData){
   

    int id=UserData["huntDrop"][0]["id"];
    int count=UserData["huntDrop"][0]["count"];
   
    int freeCell=0;
    int  freeCellCount=0;
  putItemIntoUser( UserData, id,count,  freeCell,  freeCellCount);
  UserData["huntDrop"][0]["id"]=0;;
UserData["huntDrop"][0]["count"]=0;
UserData["stateHunt"]=0;
std::cout<<"you get item";
  saveUser(UserData);

}