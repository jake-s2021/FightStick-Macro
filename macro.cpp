#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
#include<filesystem>
#include<wiringPi.h>
#define A_ON digitalWrite(15, HIGH)
#define A_OFF digitalWrite(15, LOW)
#define B_ON digitalWrite(16, HIGH)
#define B_OFF digitalWrite(16, LOW)
#define X_ON digitalWrite(1, HIGH)
#define X_OFF digitalWrite(1, LOW)
#define Y_ON digitalWrite(4, HIGH)
#define Y_OFF digitalWrite(4, LOW)
#define RB_ON digitalWrite(5, HIGH)
#define RB_OFF digitalWrite(5, LOW)
#define RT_ON digitalWrite(6, HIGH)
#define RT_OFF digitalWrite(6, LOW)
#define LB_ON digitalWrite(10, HIGH)
#define LB_OFF digitalWrite(10, LOW)
#define LT_ON digitalWrite(11, HIGH)
#define LT_OFF digitalWrite(11, LOW)
#define U_ON digitalWrite(31, HIGH)
#define U_OFF digitalWrite(31, LOW)
#define D_ON digitalWrite(26, HIGH)
#define D_OFF digitalWrite(26, LOW)
#define L_ON digitalWrite(27, HIGH)
#define L_OFF digitalWrite(27, LOW)
#define R_ON digitalWrite(28, HIGH)
#define R_OFF digitalWrite(28, LOW)


void init_stack(std::stack<int> &actions, std::map<std::string,int> assoc, std::string filename);
std::map<std::string,int> init_map();
bool is_num(std::string num);
bool update_made(auto init_time_one, auto init_time_two, auto init_time_three, auto init_time_four);
void exec(std::stack<int> cmds, int player);
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
void L(int player);
void R(int player);
void UR(int player);
void UL(int player);
void DR(int player);
void DL(int player);
void QCF(int player);
void QCB(int player);
void HCF(int player);
void HCB(int player);
void HCFB(int player);
void HCBF(int player);
void DP(int player);
void RDP(int player);
void DQCF(int player);
void DQCB(int player);
void DHCF(int player);
void DHCB(int player);
void DHCFB(int player);
void DHCBF(int player);
void SPD(int player);
void DSPD(int player);
void U_Hold();
void D_Hold();
void L_Hold(int player);
void R_Hold(int player);
void UR_Hold(int player);
void UL_Hold(int player);
void DR_Hold(int player);
void DL_Hold(int player);
void U_Release();
void D_Release();
void L_Release(int player);
void R_Release(int player);
void UR_Release(int player);
void UL_Release(int player);
void DR_Release(int player);
void DL_Release(int player);

int main(){

    std::map<std::string,int> keys = init_map();
    std::stack<int> cmds_one;
    std::stack<int> cmds_two;
    std::stack<int> cmds_three;
    std::stack<int> cmds_four;
    int player = 1;
    auto one_date = std::filesystem::last_write_time("Profile_One");
    auto two_date = std::filesystem::last_write_time("Profile_Two");
    auto three_date = std::filesystem::last_write_time("Profile_Three");
    auto four_date = std::filesystem::last_write_time("Profile_Four");
    

    init_stack(cmds_one, keys, "Profile_One");
    init_stack(cmds_two, keys, "Profile_Two");
    init_stack(cmds_three, keys, "Profile_Three");
    init_stack(cmds_four, keys, "Profile_Four");

    wiringPiSetup();

    pinMode(15,OUTPUT); //A
    A_OFF;
    pinMode(16,OUTPUT); //B
    B_OFF;
    pinMode(1,OUTPUT); //X
    X_OFF;
    pinMode(4,OUTPUT); //Y
    Y_OFF;
    pinMode(5,OUTPUT); //RB
    RB_OFF;
    pinMode(6,OUTPUT); //RT
    RT_OFF;
    pinMode(10,OUTPUT); //LB
    LB_OFF;
    pinMode(11,OUTPUT); //LT
    LT_OFF;
    pinMode(31,OUTPUT); //U
    U_OFF;
    pinMode(26,OUTPUT); //D
    D_OFF;
    pinMode(27,OUTPUT); //L
    L_OFF;
    pinMode(28,OUTPUT); //R
    R_OFF;

    pinMode(21, INPUT); //macro 1
    pinMode(22, INPUT); //macro 2
    pinMode(23, INPUT); //macro 3
    pinMode(24, INPUT); //macro 4
    pinMode(25, INPUT); //position switch

    pinMode(29, OUTPUT);
    digitalWrite(29, HIGH); //LED to say macros are ready


    while(true){
        if(digitalRead(21)){ //change to microcontroller 1
            exec(cmds_one, player);
        }
        if(digitalRead(22)){ //change to microcontroller 2
            exec(cmds_two, player);
        }
        if(digitalRead(23)){ //change to microcontroller 3
            exec(cmds_three, player);
        }
        if(digitalRead(24)){ //change to microcontroller 4
            exec(cmds_four, player);
        }
        if(digitalRead(25)){
            if(player == 1){
                player = 2;
                digitalWrite(29, LOW);
            }
            else{
                player = 1;
                digitalWrite(29, HIGH);
            }
        }
        if(update_made(one_date, two_date, three_date, four_date)){
            init_stack(cmds_one, keys, "Profile_One");
            init_stack(cmds_two, keys, "Profile_Two");
            init_stack(cmds_three, keys, "Profile_Three");
            init_stack(cmds_four, keys, "Profile_Four");
        }

    }

}

void exec(std::stack<int> cmds, int player){

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
                    U_Hold();
					break;
				case 34:
                    D_Hold();
					break;
				case 35:
                    L_Hold(player);
					break;
				case 36:
                    R_Hold(player);
					break;
				case 37:
                    UR_Hold(player);
					break;
				case 38:
                    UL_Hold(player);
					break;
				case 39:
                    DR_Hold(player);
					break;
				case 40:
                    DL_Hold(player);
					break;
				case 41:
                    U_Release();
					break;
				case 42:
                    D_Release();
					break;
				case 43:
                    L_Release(player);
					break;
				case 44:
                    R_Release(player);
					break;
				case 45:
                    UR_Release(player);
					break;
				case 46:
                    UL_Release(player);
					break;
				case 47:
                    DR_Release(player);
					break;
				case 48:
                    DL_Release(player);
					break;
				case 49:
					break;
                default:
                    break;
            }

        }
    }


}

void init_stack(std::stack<int> &actions, std::map<std::string,int> assoc, std::string filename){
    
    
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
    {"DSPD", 32,},
    {"UHold", 33,},
    {"DHold", 34,},
    {"LHold", 35,},
    {"RHold", 36,},
    {"URHold", 37,},
    {"ULHold", 38,},
    {"DRHold", 39,},
    {"DLHold", 40,},
    {"URel", 41,},
    {"DRel", 42,},
    {"LRel", 43,},
    {"RRel", 44,},
    {"URRel", 45,},
    {"ULRel", 46,},
    {"DRRel", 47,},
    {"DLRel", 48,}
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

bool update_made(auto init_time_one, auto init_time_two, auto init_time_three, auto init_time_four){
    if(init_time_one < std::filesystem::last_write_time("Profile_One") || init_time_two std::filesystem::last_write_time("Profile_Two") || init_time_three < std::filesystem::last_write_time("Profile_Three") || init_time_four < std::filesystem::last_write_time("Profile_Four")){
        return true;
    }
    return false;
}

void A(){
    A_ON;
    sleep(17);
    A_OFF;

}
void B(){
    B_ON;
    sleep(17);
    B_OFF;
}
void X(){
    X_ON;
    sleep(17);
    X_OFF;
}
void Y(){
    Y_ON;
    sleep(17);
    Y_OFF;
}
void RB(){
    RB_ON;
    sleep(17);
    RB_OFF;
}
void RT(){
    RT_ON;
    sleep(17);
    RT_OFF;
}
void LB(){
    LB_ON;
    sleep(17);
    LB_OFF;
}
void LT(){
    LT_ON;
    sleep(17);
    LT_OFF;
}
void U(){
    U_ON;
    sleep(17);
    U_OFF;
}
void D(){
    D_ON;
    sleep(17);
    D_OFF;
}
void L(int player){
    if(player == 1){
        L_ON;
        sleep(17);
        L_OFF;
    }
    else{
        R_ON;
        sleep(17);
        R_OFF;
    }
}
void R(int player){
    if(player == 1){
        R_ON;
        sleep(17);
        R_OFF;
    }
    else{
        L_ON;
        sleep(17);
        L_OFF;
    }
}
void UR(int player){
    if(player == 1){
        U_ON;
        R_ON;
        sleep(17);
        U_OFF;
        R_OFF;
    }
    else{
        U_ON;
        L_ON;
        sleep(17);
        U_OFF;
        L_OFF;
    }

}
void UL(int player){
    if(player == 1){
        U_ON;
        L_ON;
        sleep(17);
        U_OFF;
        L_OFF;
    }
    else{
        U_ON;
        R_ON;
        sleep(17);
        U_OFF;
        R_OFF;
    }
}
void DR(int player){
    if(player == 1){
        D_ON;
        R_ON;
        sleep(17);
        D_OFF;
        R_OFF;
    }
    else{
        D_ON;
        L_ON;
        sleep(17);
        D_OFF;
        L_OFF;
    }
}
void DL(int player){
    if(player == 1){
        D_ON;
        L_ON;
        sleep(17);
        D_OFF;
        L_OFF;     
    }
    else{
        D_ON;
        R_ON;
        sleep(17);
        D_OFF;
        R_OFF;     
    }
}
void QCF(int player){
    if(player == 1){
        D();
        DR(1);
        R(1);
    }
    else{
        D();
        DL(1);
        L(1);
    }

}
void QCB(int player){
    if(player == 1){
        D();
        DL(1);
        L(1);
    }
    else{
        D();
        DR(1);
        R(1);       
    }

}
void HCF(int player){
    if(player == 1){
        L(1);
        DL(1);
        D();
        DR(1);
        R(1);
    }
    else{
        R(1);
        DR(1);
        D();
        DL(1);
        L(1);
    }

}
void HCB(int player){
    if(player == 1){
        R(1);
        DR(1);
        D();
        DL(1);
        L(1);
    }
    else{
        L(1);
        DL(1);
        D();
        DR(1);
        R(1);
    }
}
void HCFB(int player){
    if(player == 1){
        L(1);
        DL(1);
        D();
        DR(1);
        R(1);
        L(1);
    }
    else{
        R(1);
        DR(1);
        D();
        DL(1);
        L(1);
        R(1);
    }

}
void HCBF(int player){
    if(player == 1){
        R(1);
        DR(1);
        D();
        DL(1);
        L(1);
        R(1);
    }
    else{
        L(1);
        DL(1);
        D();
        DR(1);
        R(1);
        L(1);
    }
}
void DP(int player){
    if(player == 1){
        R(1);
        D();
        DR(1);
    }
    else{
        L(1);
        D();
        DL(1);
    }

}
void RDP(int player){
    if(player == 1){
        L(1);
        D();
        DL(1);
    }
    else{
        R(1);
        D();
        DR(1);
    }

}
void DQCF(int player){
    if(player == 1){
        QCF(1);
        QCF(1);
    }
    else{
        QCB(1);
        QCB(1);
    }

}
void DQCB(int player){
    if(player == 1){
        QCB(1);
        QCB(1);
    }
    else{
        QCF(1);
        QCF(1);
    }
}
void DHCF(int player){
    if(player == 1){
        HCF(1);
        HCF(1);
    }
    else{
        HCB(1);
        HCB(1);
    }
}
void DHCB(int player){
    if(player == 1){
        HCB(1);
        HCB(1);
    }
    else{
        HCF(1);
        HCF(1);       
    }
}
void DHCFB(int player){
    if(player == 1){
        HCFB(1);
        HCFB(1);
    }
    else{
        HCBF(1);
        HCBF(1);
    }
}
void DHCBF(int player){
    if(player == 1){
        HCBF(1);
        HCBF(1);        
    }
    else{
        HCFB(1);
        HCFB(1);
    }

}
void SPD(int player){
    if(player == 1){
        R(1);
        DR(1);
        D();
        DL(1);
        L(1);
        UL(1);
        U();
        UR(1);
        R(1);
    }
    else{
        L(1);
        DL(1);
        D();
        DR(1);
        R(1);
        UR(1);
        U();
        UL(1);
        L(1);
    }
}
void DSPD(int player){
    SPD(player);
    SPD(player);
}
void U_Hold(){
    U_ON;
}
void D_Hold(){
    D_ON;
}
void L_Hold(int player){
    if(player == 1){
        L_ON;
    }
    else{
        R_ON;
    }
}
void R_Hold(int player){
    if(player == 1){
        R_ON;
    }
    else{
        L_ON;
    }
}
void UR_Hold(int player){
    if(player == 1){
        U_ON;
        R_ON;
    }
    else{
        U_ON;
        L_ON;
    }
}
void UL_Hold(int player){
    if(player == 1){
        U_ON;
        L_ON;
    }
    else{
        U_ON;
        R_ON;
    }
}
void DR_Hold(int player){
    if(player == 1){
        D_ON;
        R_ON;
    }
    else{
        D_ON;
        L_ON;
    }

}
void DL_Hold(int player){
    if(player == 1){
        D_ON;
        L_ON;
    }
    else{
        D_ON;
        R_ON;
    }
}
void U_Release(){
    U_OFF;
}
void D_Release(){
    D_OFF;
}
void L_Release(int player){
    if(player == 1){
        L_OFF;
    }
    else{
        R_OFF;
    }
}
void R_Release(int player){
    if(player == 1){
        R_OFF;
    }
    else{
        L_OFF;
    }
}
void UR_Release(int player){
    if(player == 1){
        U_OFF;
        R_OFF;
    }
    else{
        U_OFF;
        L_OFF;
    }

}
void UL_Release(int player){
    if(player == 1){
        U_OFF;
        L_OFF;
    }
    else{
        U_OFF;
        R_OFF;
    }
}
void DR_Release(int player){
    if(player == 1){
        D_OFF;
        R_OFF;
    }
    else{
        D_OFF;
        L_OFF;
    }
}
void DL_Release(int player){
    if(player == 1){
        D_OFF;
        L_OFF;
    }
    else{
        D_OFF;
        R_OFF;
    }
}