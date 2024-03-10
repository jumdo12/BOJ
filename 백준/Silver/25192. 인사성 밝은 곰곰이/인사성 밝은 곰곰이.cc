#include <iostream>
#include <set>
#include <string>
int main(){
    int N ,cnt = 0;
    std::string str;
    std::set<std::string> s;
    
    std::cin>>N;
    while(N--){
        std::cin>>str;
        if(str == "ENTER"){
            cnt += s.size();
            s.clear();
        }
        else{
            s.insert(str);
        }
    }
    cnt += s.size();
    
    std::cout<<cnt;
}