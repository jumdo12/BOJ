#include <iostream>
#include <stack>
#include <string>

int main(){
    std::stack<int> s;
    std::string str;
    int N,num;

    std::cin>>N;

    while(N--){
        std::cin>>str;
        if(str == "push"){
            std::cin>>num;
            s.push(num);
        }
        else if(str == "pop"){
            if(s.empty())   std::cout << -1 <<'\n';
            else{
                std::cout<<s.top()<<'\n';
                s.pop();
            }
        }
        else if(str == "size"){
            std::cout<<s.size()<<'\n';
        }
        else if(str == "empty"){
            std::cout<<s.empty()<<'\n';
        }
        else{
            if(s.empty())   std::cout<<-1<<'\n';
            else    std::cout<<s.top()<<'\n';
        }
    }

    return 0;
}