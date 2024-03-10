#include <iostream>
#include <map>
#include <string>
int main(){
    std::map<std::string,int> m;
    std::string A,B;
    int N,cnt=1;

    std::cin>>N;
    m["ChongChong"] = 1;
    while (N--){
        std::cin>>A>>B;
        if ((m[A] == 1 && m[B] == 0)||(m[A]==0 && m[B]==1)){
            m[A] = 1;
            m[B] = 1;
            cnt++;
        }
    }
    std::cout<<cnt;
    return 0;
}