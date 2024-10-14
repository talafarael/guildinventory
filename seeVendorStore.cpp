#include <iostream>
#include "seeVendorStore.h"
#include "json.hpp" 
#include "getFileContent.h"
#include "findItemId.h"
void seeVendorStore(){
    std::string VendorInventoryString= getFileContent("VendorInventory.json");
    nlohmann::json  VendorInventoryData=nlohmann::json::parse(VendorInventoryString);
    for(int i=0;i<VendorInventoryData["inventory"].size();i++){
        int id =VendorInventoryData["inventory"][i]["id"].get<int>();
        nlohmann::json item= findItemId(id);
       std::cout<<"Column: 0"<<"Row"<<i<<"|"<<item["name"]<<"Count"<<VendorInventoryData["inventory"][i]["id"].get<int>()<<std::endl;
    }

}