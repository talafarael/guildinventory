#include <iostream>
#include "guildBankSession.h"



char guildBankSession(){
char action;
std::cout<<"if ypu want get Item enter g";
std::cin>>action;
  if(action=='g') {
return action;
  }
 return guildBankSession();
}