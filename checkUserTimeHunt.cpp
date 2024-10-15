#include <iostream>
#include <string>
#include <chrono>
#include <ctime>  
#include "checkUserTimeHunt.h"
const int ONE_HOURS_IN_SECONDS = 3600;
bool checkUserTimeHunt(int& huntState){
        auto now = std::chrono::system_clock::now();
        std::time_t timeNow = std::chrono::system_clock::to_time_t(now);
        double difference = std::difftime(timeNow, huntState);
        if(difference >= ONE_HOURS_IN_SECONDS){
            return true;
        }
        return false;
} 