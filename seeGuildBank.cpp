#include <iostream>
#include "seeGuildBank.h"
#include "json.hpp"
void seeGuildBank(nlohmann::json& GuildInventory,nlohmann::json& ItemDb  ){
    for(int i=0;i<GuildInventory["inventory"].size();i++){
  for(int j=0;j<GuildInventory["inventory"][i].size();j++){
      std::cout << "Column " << i << ", Row " << j << " | ";
    if(GuildInventory["inventory"][i][j]["id"]==0){
      
       std::cout << "Empty" << std::endl;
      continue;
    }
   
  for(int y=0;y<ItemDb["items"].size();y++){
    if(ItemDb["items"][y]["id"]==GuildInventory["inventory"][i][j]["id"]){
    // item.id=ItemDb["items"][y]["id"];
    //    item.name = ItemDb["name"][y].get<std::string>();
    //  item.sell = ItemDb["sell"][y].get<int>();
    //  item.stack = ItemDb["stack"][y];
    //  item.obtainedBy = ItemDb["obtainedBy"][y];

  std::cout << "Item: " << ItemDb["items"][y]["name"].get<std::string>()
                          << " | Count: " << GuildInventory["inventory"][i][j]["count"].get<int>()<<std::endl;


    }
  }
}
std::cout << "-------------------------------------" << std::endl;
}
}