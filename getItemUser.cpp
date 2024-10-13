#include <iostream>
#include "json.hpp"
#include "getItemUser.h"
#include "findItemId.h"
void getItemUser(nlohmann::json& UserData){
    for(int i=0;i<UserData["inventory"].size();i++){
        int column=0;
        int row=i;
        if(i-7>0){
column=1;
row=i-7;
        }
        int id=UserData["inventory"][i]["id"].get<int>();
        if(id!=0){
        nlohmann::json item = findItemId(id);
        
         std::cout<<"Column"<<column<<", Row"<<row<<"| Item"<<item["name"]<<"| Count"<<UserData["inventory"][i]["count"]<<std::endl;
        }
        else{
            std::cout<<"Column"<<column<<", Row"<<row<<"| Empty"<<std::endl;
        }
    }
}