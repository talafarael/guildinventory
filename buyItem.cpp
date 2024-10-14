#include <iostream>
#include <fstream>
#include "buyItem.h"
#include "json.hpp"
#include "dataMatrixInput.h"
#include "getFileContent.h"
#include "findItemId.h"
#include "putItemIntoUser.h"
#include "saveUser.h"
void buyItem(nlohmann::json& UserData){
     std::string VendorInventoryString= getFileContent("VendorInventory.json");
    nlohmann::json  VendorInventoryData=nlohmann::json::parse(VendorInventoryString);
     int column,row ,count;
    int freeCell=0;
    int freeCellCount=0;
   dataMatrixInput( column, row, count);
  int itemCount=count;
   int id=VendorInventoryData["inventory"][row]["id"];
   if(id==0){
    std::cout<<"empty Row"<<std::endl;
    return;
   }
   
   nlohmann::json item = findItemId(id);
  
   if(item["buyPrice"].get<int>() > UserData["gold"].get<int>()){
    std::cout<<"you dont have money"<<std::endl;
    return;
   }

   putItemIntoUser( UserData, id, count,freeCell,freeCellCount);
  VendorInventoryData["inventory"][row]["count"] =VendorInventoryData["inventory"][row]["count"].get<int>() -itemCount;
if(VendorInventoryData["inventory"][row]["count"]==0){
VendorInventoryData["inventory"][row]["id"]=0;
}


UserData["gold"]=UserData["gold"].get<int>()-item["buyPrice"].get<int>();
 std::ofstream file("VendorInventory.json");
  if (file.is_open()) {
        file << VendorInventoryData.dump(5); 
        file.close(); 
    } 
saveUser(UserData);
}