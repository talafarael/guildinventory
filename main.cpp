#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp"
using json = nlohmann::json;
std::string token;
struct Inventory {
  std::string key;
 std::string count;
};
struct User {
  std::string name;
  std::string password;
  std::vector<std::string> inventory={};
  };
std::string getFileContent(std::string fileName);


char startSession();
void Register();
int main(){
  std::remove("userSession.json");

// std::string usersData=getFileContent("user.json");
//  json j =json::parse(usersData);
 char  startAction= startSession();
  if( startAction=='r') {
    Register();
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
std::string getFileContent(std::string fileName) {
  std::string line;
  std::string fileContents;
  std::ifstream in(fileName);

  if (in.is_open())
  {
    while (std::getline(in, line))
    {
      fileContents+=line;
    }
  }
  return  fileContents;
}
char startSession() {
  char startAction;
  std::cout<<"login enter l register r";
  std::cin>>startAction;
  if(startAction=='r'||startAction=='l') {
    return  startAction;
  }
  startSession();

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

  std::string jsonString=user.dump();
  std::cout<<jsonString;
  // j.push_back(jsonString);


  // std::ofstream file("user.json");
  // file << j.dump(5);
  token=user.name;
std::cout<<"user secsefull register"<<std::endl;
  // file.close();
}


void login() {
  // std::string usersData=getFileContent("user.json");
  // json j =json::parse(usersData);
  // User user;
  // std::cout<<"enter username"<<std::endl;
  // std::cin >> user.name;
  // for(int i=0;i<j.size();i++) {
  //   if(j[i]["name"]==user.name) {
  //    user.name=j[i]["name"];
  //    user.password=j[i]["password"];
  //     if(j[i]["inventory"]!="[]") {
  //       user.inventory=j[i]["inventory"];
  //     }
  //
  //   }
  // }

}