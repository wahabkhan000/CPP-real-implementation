#include <iostream>
using std::cout,std::cin,std::string,std::endl,std::pair;
void speed_fine_list_R() {
    cout<<"--------------------------------------------------------\n"
          "|    Area      | Code |  Speed Limit  |     Fine       |\n"
          "|--------------|------|---------------|----------------|\n"
          "|              |      | between 50-65 |    700 PKR     |\n"
          "| Residential  |  R   | between 65-75 |   1200 PKR     |\n"
          "|              |      |    above 75   |   1500 PKR     |\n"
          "--------------------------------------------------------"<<endl;
}
void speed_fine_list_N() {
    cout<<"--------------------------------------------------------\n"
          "|    Area      | Code |  Speed Limit  |     Fine       |\n"
          "|--------------|------|---------------|----------------|\n"
          "|              |      | between 60-75 |    400 PKR     |\n"
          "|Nonresidential|  N   | between 75-100|    550 PKR     |\n"
          "|              |      |    above 100  |    700 PKR     |\n"
          "--------------------------------------------------------"<<endl;
}
void input_area_code(char &a) {
    bool flag = false;
    do {
        if (flag == false) {
            cout<<"Enter the Code R for residential and N for non-residential:"<<endl;
        }
        else {
            cout<<"Invalid area code! Please enter the correct one."<<endl;
        }
        cin>>a;
        flag = true;
    }while (a!='R'&&a!='N');
}
void speed_validation(int &speed) {
    bool flag = false;
    do {
        if (flag == false) {
            cout<<"Enter the speed:"<<endl;
        }
        else {
            cout<<"Invalid speed! Please enter the correct speed above 0:"<<endl;
        }
        flag = true;
        cin>>speed;
    }while (speed<1);
}
void speed_measure_N() {
    int speed = 0;
    speed_validation(speed);
    if (speed>50 && speed<65) {
        cout<<"As your speed is "<<speed<<". So your fine is 700 PKR"<<endl;
    }
    else if (speed>=65 && speed<=75) {
        cout<<"As your speed is "<<speed<<". So your fine is 1200 PKR"<<endl;
    }
    else {
        cout<<"As your speed is "<<speed<<". So your fine is 1500 PKR"<<endl;
    }
}
void speed_measure_R() {
    int speed = 0;
    speed_validation(speed);
    if (speed>60 && speed<75) {
        cout<<"As your speed is "<<speed<<". So your fine is 400 PKR"<<endl;
    }
    else if (speed>75 && speed<=100) {
        cout<<"As your speed is "<<speed<<". So your fine is 550 PKR"<<endl;
    }
    else {
        cout<<"As your speed is "<<speed<<". So your fine is 700 PKR"<<endl;
    }
}
int main() {
    char a = 'o';
    input_area_code(a);
    if (a == 'N') {
        speed_fine_list_N();
        speed_measure_N();
    }
    else {
        speed_fine_list_R();
        speed_measure_R();
    }
}
