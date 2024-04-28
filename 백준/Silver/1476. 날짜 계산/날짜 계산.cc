#include <iostream>

int main(){
    int E,S,M,x,y,z;
    int years = 0;
    x=y=z=0;
    std::cin>>E>>S>>M;

    while (1){   
        x++;
        y++;
        z++;
        years++;

        if(x == E && y == S && z == M){
            std::cout<< years;
            break;
        }
        x %= 15;
        y %= 28;
        z %= 19;
    }
    
    return 0;
}