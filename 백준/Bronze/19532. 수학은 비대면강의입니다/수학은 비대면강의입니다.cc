#include <iostream>

int main(){
    int a,b,c,d,e,f;
    std::cin>>a>>b>>c>>d>>e>>f;
    for(int x=-999; x<=999; x++){
        for(int y=-999; y<= 999; y++){
            if(((a*x+b*y) == c && (d*x+y*e)==f)){
                std::cout<<x<<" "<<y;
                return 0;
            }
        }
    }
    return 0;
}