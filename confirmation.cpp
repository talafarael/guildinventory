#include <iostream>
#include "confirmation.h"

bool confirmation(){
 std::cout<<"are you sure"<<std::endl;
 std::cout<<"if yes enter y"<<std::endl;
 char action;
 std::cin>>action;
 if(action=='y'){
    return false;
 }
  return true;
}
