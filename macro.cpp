#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>

void init_stack(std::stack<int> &actions, std::map<std::string,int> &assoc, std::string filename);
std::map<std::string,int> init_map();
bool is_num(std::string num);
void exec(std::stack<int> cmds, int &player);
void sleep(int ms);
void A();
void B();
void X();
void Y();
void RB();
void RT();
void LB();
void LT();
void U();
void D();
void L(int &player);
void R(int &player);
void UR(int &player);
void UL(int &player);
void DR(int &player);
void DL(int &player);
void QCF(int &player);
void QCB(int &player);
void HCF(int &player);
void HCB(int &player);
void HCFB(int &player);
void HCBF(int &player);
void DP(int &player);
void RDP(int &player);
void DQCF(int &player);
void DQCB(int &player);
void DHCF(int &player);
void DHCB(int &player);
void DHCFB(int &player);
void DHCBF(int &player);
void SPD(int &player);
void DSPD(int &player);

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
    int player = 1;

    init_stack(cmds_one, keys, "Profile_One");
    init_stack(cmds_two, keys, "Profile_Two");
    init_stack(cmds_three, keys, "Profile_Three");
    init_stack(cmds_four, keys, "Profile_Four");

    while(true){
        if(true){ //change to microcontroller 1
            exec(cmds_one, player);
        }
        if(true){ //change to microcontroller 2
            exec(cmds_two, player);
        }
        if(true){ //change to microcontroller 3
            exec(cmds_three, player);
        }
        if(true){ //change to microcontroller 4
            exec(cmds_four, player);
        }
        if(true){
            if(player == 1){
                player = 2;
            }
            else{
                player = 1;
            }
        }
        std::exit(1);
    }

}

void exec(std::stack<int> cmds, int &player){

    while(!cmds.empty()){
        int next = cmds.top();
        cmds.pop();

        if(next > 49){
            sleep(next);
        }
        else{
            switch(next){
				case 1:
                    A();
					break;
				case 2:
                    B();
					break;
				case 3:
                    X();
					break;
				case 4:
                    Y();
					break;
				case 5:
                    RB();
					break;
				case 6:
                    RT();
					break;
				case 7:
                    LB();
					break;
				case 8:
                    LT();
					break;
				case 9:
                    U();
					break;
				case 10:
                    D();
					break;
				case 11:
                    L(player);
					break;
				case 12:
                    R(player);
					break;
				case 13:
                    UR(player);
					break;
				case 14:
                    UL(player);
					break;
				case 15:
                    DR(player);
					break;
				case 16:
                    DL(player);
					break;
				case 17:
                    QCF(player);
					break;
				case 18:
                    QCB(player);
					break;
				case 19:
                    HCF(player);
					break;
				case 20:
                    HCB(player);
					break;
				case 21:
                    HCFB(player);
					break;
				case 22:
                    HCBF(player);
					break;
				case 23:
                    DP(player);
					break;
				case 24:
                    RDP(player);
					break;
				case 25:
                    DQCF(player);
					break;
				case 26:
                    DQCB(player);
					break;
				case 27:
                    DHCF(player);
					break;
				case 28:
                    DHCB(player);
					break;
				case 29:
                    DHCFB(player);
					break;
				case 30:
                    DHCBF(player);
					break;
				case 31:
                    SPD(player);
					break;
				case 32:
                    DSPD(player);
					break;
				case 33:
					break;
				case 34:
					break;
				case 35:
					break;
				case 36:
					break;
				case 37:
					break;
				case 38:
					break;
				case 39:
					break;
				case 40:
					break;
				case 41:
					break;
				case 42:
					break;
				case 43:
					break;
				case 44:
					break;
				case 45:
					break;
				case 46:
					break;
				case 47:
					break;
				case 48:
					break;
				case 49:
					break;
            }

        }
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
        else if(is_num(unparsed_actions[i]) && std::stoi(unparsed_actions[i])>49 && !actions.empty()){ //if actions is empty and the first command is numeric then it should be ignored
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

void sleep(int ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void A(){

}
void B(){

}
void X(){

}
void Y(){

}
void RB(){

}
void RT(){

}
void LB(){

}
void LT(){

}
void U(){

}
void D(){

}
void L(int &player){

}
void R(int &player){

}
void UR(int &player){

}
void UL(int &player){

}
void DR(int &player){

}
void DL(int &player){

}
void QCF(int &player){

}
void QCB(int &player){

}
void HCF(int &player){

}
void HCB(int &player){

}
void HCFB(int &player){

}
void HCBF(int &player){

}
void DP(int &player){

}
void RDP(int &player){

}
void DQCF(int &player){

}
void DQCB(int &player){

}
void DHCF(int &player){

}
void DHCB(int &player){

}
void DHCFB(int &player){

}
void DHCBF(int &player){

}
void SPD(int &player){

}
void DSPD(int &player){

}
