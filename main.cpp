#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <optional>
#include "json.hpp"
#include "guildBankSession.h"
#include "seeGuildBank.h"
#include "getItemGuild.h" 
#include "getFileContent.h" 
using json = nlohmann::json;

struct Inventory {
 int id;
 int count;
};
struct Item{
  int id;
  std::string name;
  int sell;
  int stack;
  std::string obtainedBy;
  std::optional<double> dropChance;
 std::optional<int> buyPrice;
 };


struct User {
  std::string name;
  std::string password;
  std::vector<Inventory> inventory={};
  };


nlohmann::json GuildInventory;
nlohmann::json ItemDb;
nlohmann::json UserData;

// std::string getFileContent(std::string fileName);
// char guildBankSession() {
    // char action;
    // std::cout << "if you want to get Item, enter g";
    // std::cin >> action;
    // if (action == 'g') {
    //     return action;
    // }
//     return 'f';
// }
void startSession();
void getItemId();
char starAtionEnter();
void getGuildInventory();
void Register();
void Login();
void getItemGuild();
char choiceAction();

int main(){

  

// std::string usersData=getFileContent("user.json");
//  json j =json::parse(usersData);
startSession();
std::cout<<UserData;


getGuildInventory();
getItemId();



for(;;){
  char action=choiceAction();

  if(action='s'){

 seeGuildBank(GuildInventory, ItemDb);
for(;;){
 char actionGuild = guildBankSession();
  if(actionGuild=='g'){
   getItemGuild(UserData);
  }
}
}
}

  // j["name"] = "Habr";
  // std::cout<<j;
// User user;
// std::cin >> user.name;
// std::cin >> user.password;
  // std::ifstream f("example.json");
  // json data = json::parse(f);
  //   User user;
  // std::cin >> user.name;
  // std::cin >> user.password;
  // std::ofstream file("output.json");
  // file << j.dump(5);

  // user.inventory=[""];
  // std::ofstream users;
  // users.open("user.txt");
  // users.write(user.name.c_str(),user.name.size());
  // for(int i=0;i<user.name.size();i++) {
  //   char letter=user.name[i];
  //   users.write(&letter, sizeof(char));
  // }

  return 0;
}
void getItemId(){
  std::string ItemData= getFileContent("itemDb.json");
  ItemDb=nlohmann::json::parse(ItemData);
}
void getGuildInventory(){
std::string GuildInventoryJson= getFileContent("GildInventory.json");
 
if(GuildInventoryJson.empty()){
  nlohmann::json newInventory = {{"inventory", nlohmann::json::array()}};

  for (int i = 0; i < 7; ++i) {
    nlohmann::json row = {};  
    for (int j = 0; j < 7; ++j) {
        nlohmann::json item = {
            {"id", 0},
            {"count", 0}
        };
        row.push_back(item);  
  }
  newInventory["inventory"].push_back(row); 
  }
  
GuildInventoryJson= newInventory.dump();
  std::ofstream file("GildInventory.json");
    if (file.is_open()) {
        file << newInventory.dump(5); 
        file.close(); 
    } 
}
GuildInventory =json::parse(GuildInventoryJson);
}
void createJson(std::string fileName){
    std::ofstream file(fileName);
   json jsonFile=json::object();
   file<<jsonFile.dump(4);
    file.close();
}
void startSession(){
 char  startAction= starAtionEnter();
  if( startAction=='r') {
    Register();
  }
    if( startAction=='l') {
    Login();
  }
  
}


char starAtionEnter() {
  char startAction;
  std::cout<<"login enter l register r";
  std::cin>>startAction;
  if(startAction=='r'||startAction=='l') {
    return  startAction;
  }
   if(startAction=='r'||startAction=='l') {
    return  startAction;
  }
 return starAtionEnter();

}
void Register() {
  std::string usersData=getFileContent("user.json");
  json j =json::parse(usersData);
  User user;


  std::cout<<"enter username"<<std::endl;
  std::cin >> user.name;
  for(int i=0;i<j.size();i++) {
    if(j[i]["name"]==user.name) {
      std::cout<<"name is required"<<std::endl;
      Register();
    }
  }
  std::cout<<"enter password"<<std::endl;
  std::cin >> user.password;

  nlohmann::json userJson = {
        {"name", user.name},
        {"password", user.password},
        {"inventory", nlohmann::json::array()}
    };
    for(int i=0;i<14;i++){
      userJson["inventory"].push_back({
          {"id", 0},
            {"count", 0}
      });
    }
  j.push_back(userJson);
  std::ofstream file("user.json");
  file << j.dump(5);
  UserData=userJson;
std::cout<<"user secsefull register"<<std::endl;
  file.close();
}


void Login() {
  std::string usersData=getFileContent("user.json");
  json j =json::parse(usersData);
  std::string name;
std::string password;
  bool stateLogin=false;
  std::cout<<"enter username"<<std::endl;
  std::cin >> name;
    std::cin >> password;
  for(int i=0;i<j.size();i++) {
    if(j[i]["name"].get<std::string>()==name && j[i]["password"].get<std::string>()==password) {
     
    UserData=j[i];
    stateLogin=true;
  }
}
 if(!stateLogin){
  std::cout<<"login or password don't exist"<<std::endl;
  Login();
  return;
 }
 std::cout<<"you entered in your account"<<std::endl;
}


char choiceAction(){
    char Action;
  std::cout<<"if you want  open giuld bank enter s "<<std::endl;
    std::cout<<"if you want  go to vendor enter v "<<std::endl;
      std::cout<<"if you want send yout person in to hunt press g and after that you can't play perform the action for at least an hour"<<std::endl;
  std::cin>>Action;
  if(Action=='s'||Action=='v'||Action=='g') {
    return  Action;
  }
 
 return choiceAction();
}