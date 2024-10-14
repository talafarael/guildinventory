#include <iostream>
#include "vendorSession.h"

char vendorSession(){
    char action;
std::cout<<"if ypu want buy item enter b"<<std::endl;
std::cout<<"if ypu want sell item enter s"<<std::endl;
std::cout<<"if ypu want exit Item enter e"<<std::endl;
std::cin>>action;
  if(action=='g'||action=='p'|| action=='e') {
return action;
  }
 return vendorSession();
}