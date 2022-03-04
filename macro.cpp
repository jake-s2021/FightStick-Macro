#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<fstream>
#include<vector>

void init_stack(std::stack<int> &actions, std::map<std::string,int> &assoc, std::string filename);
std::map<std::string,int> init_map();


int main(){

    std::map<std::string,int> keys = init_map();
    std::stack<int> cmds_one;
    std::stack<int> cmds_two;
    std::stack<int> cmds_three;

    init_stack(cmds_one, keys, "Profile_One");
    init_stack(cmds_two, keys, "Profile_Two");
    init_stack(cmds_three, keys, "Profile_Three");

    while(!cmds_one.empty()){
       std::cout << cmds_one.top() << std::endl;
       cmds_one.pop();
   }

}

void init_stack(std::stack<int> &actions, std::map<std::string,int> &assoc, std::string filename){
    
    
    //1.Open file into vector of strings TEST: write each substring to terminal on new line
    std::vector<std::string> unparsed_actions;
    std::ifstream profile(filename);
    std::string temp;


    while(std::getline(profile, temp)){
        unparsed_actions.push_back(temp);
    }

     //2. push relevant strings to stack in reverse order by their map value

    for(int i = unparsed_actions.size()-1; i >= 0; i--){
        if(assoc.find(unparsed_actions[i]) != assoc.end()){
            actions.push(assoc[unparsed_actions[i]]);
        }
    }


    profile.close();


    

   
}


std::map<std::string,int> init_map(){

    std::map<std::string, int> keys =
    {{"A",1,},
    {"B",2,},
    {"X",3,},
    {"Y",4,},
    {"RB",5,},
    {"RT",6,},
    {"LB",7,},
    {"LT",8,},
    {"U",9,},
    {"D",10,},
    {"L",11,},
    {"R",12,},
    {"UR",13,},
    {"UL",14,},
    {"DR",15,},
    {"DL",16,},
    {"QCF",17,},
    {"QCB", 18,},
    {"HCF", 19,},
    {"HCB", 20,},
    {"HCFB", 21,},
    {"HCBF", 22,},
    {"DP", 23,},
    {"RDP", 24,},
    {"DQCF", 25,},
    {"DQCB", 26,},
    {"DHCF",27,},
    {"DHCB",28,},
    {"DHCFB",29,},
    {"DHCBF",30,},
    {"SPD", 31,},
    {"DSPD", 32,}
    };

    return keys;
}
