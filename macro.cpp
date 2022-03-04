#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<fstream>
#include<vector>

void init_stack(std::stack<int> &actions, std::map<std::string,int> &assoc, std::string filename);
std::map<std::string,int> init_map();
bool is_num(std::string num);
void exec(std::stack<int> cmds);

    ////////////////
    //
    //
    //    intialize the GPIO pins for the buttons here
    //
    //
    ////////////////

int main(){

    std::map<std::string,int> keys = init_map();
    std::stack<int> cmds_one;
    std::stack<int> cmds_two;
    std::stack<int> cmds_three;
    std::stack<int> cmds_four;

    init_stack(cmds_one, keys, "Profile_One");
    init_stack(cmds_two, keys, "Profile_Two");
    init_stack(cmds_three, keys, "Profile_Three");
    init_stack(cmds_four, keys, "Profile_Four");

    while(true){
        if(button1){ //change to microcontroller 1
            exec(cmds_one);
        }
        if(button2){ //change to microcontroller 2
            exec(cmds_two);
        }
        if(button3){ //change to microcontroller 3
            exec(cmds_three);
        }
        if(button4){ //change to microcontroller 4
            exec(cmds_four);
        }
    }

}

void exec(std::stack<int> cmds){

//command execution function


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
        else if(is_num(unparsed_actions[i]) && std::stoi(unparsed_actions[i])>49){
            actions.push(std::stoi(unparsed_actions[i]));
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
//used only for init
bool is_num(std::string num){
    if(num == ""){return false;}
    for(char i : num){
        
        if(!(int(i) > 47 && int(i) < 58)){
            return false;
        }
    }

    return true;
}

