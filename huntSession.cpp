#include <iostream>
#include "huntSession.h"



char huntSession(){
char action;
std::cout<<"if ypu want go to hunt enter g"<<std::endl;
std::cout<<"if ypu want get hut enter t"<<std::endl;
std::cout<<"if ypu want exit Item enter e"<<std::endl;
std::cin>>action;
  if(action=='g'||action=='t'|| action=='e') {
return action;
  }
 return huntSession();
}