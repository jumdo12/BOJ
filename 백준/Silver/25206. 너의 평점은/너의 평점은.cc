#include <iostream>
#include <string>

int main(){
    std::string name, grade;
    double credit , total_credits=0, total_scores=0;

    for(int i=0; i<20; i++){
        std::cin>>name>>credit>>grade;

        double temp;
        if(grade[0] == 'A') temp = 4;
        else if(grade[0] == 'B') temp= 3;
        else if(grade[0] =='C') temp=2;
        else if(grade[0] =='D') temp = 1;
        else if(grade[0] == 'F') temp = 0;
        else    continue;

        if(grade.length() != 1 && grade[1] == '+')  temp += 0.5;

        total_credits += credit;
        total_scores += temp * credit;
    }
    std::cout << total_scores / total_credits;
    return 0;
}