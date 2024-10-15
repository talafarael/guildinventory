#include <iostream>
#include "getITemVendor.h"
#include "json.hpp" 
#include "getFileContent.h"
#include "fillItem.h"
#include <string>
#include <chrono>
#include <ctime>  
const int THREE_HOURS_IN_SECONDS = 3600;
void getITemVendor(){
   
    std::string type="sold by vendor";
    int count=5;
    std::string file="VendorInventory.json";

  
   std::string VendorInventoryString= getFileContent("VendorInventory.json");
    if(VendorInventoryString.empty()){
      filllItem(type,count,file);
     VendorInventoryString= getFileContent("VendorInventory.json");
    }

    nlohmann::json  VendorInventory=nlohmann::json::parse(VendorInventoryString);
        std::time_t timeStart=VendorInventory["time"];
        auto now = std::chrono::system_clock::now();
        std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

        
        double difference = std::difftime(timeNow, timeStart);
        std::cout<<timeNow;
        if (difference >= THREE_HOURS_IN_SECONDS) {
             filllItem(type,count,file);
             VendorInventoryString= getFileContent("VendorInventory.json");
             VendorInventory=nlohmann::json::parse(VendorInventoryString);
        }

}