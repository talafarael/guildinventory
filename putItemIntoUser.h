#pragma once 
#include <iostream>
#include "json.hpp"
void putItemIntoUser(nlohmann::json& UserData,int& id,int& count,  int& freeCell, int& freeCellCount);