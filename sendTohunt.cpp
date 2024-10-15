#include <iostream>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include "confirmation.h"


#include <iomanip> 
#include <string>
#include "json.hpp"
#include "confirmation.h"
#include "saveUser.h"
bool sendTohunt(nlohmann::json& UserData){
     if(confirmation()){
    return false;
  }
  std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
 auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    UserData["stateHunt"]=currentTime;
    saveUser(UserData);
    return true;
}



