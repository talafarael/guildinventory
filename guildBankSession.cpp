#include <iostream>
#include "guildBankSession.h"



char guildBankSession(){
char action;
std::cout<<"if ypu want get Item enter g"<<std::endl;
std::cout<<"if ypu want put Item enter p"<<std::endl;
std::cin>>action;
  if(action=='g'||action=='p') {
return action;
  }
 return guildBankSession();
}