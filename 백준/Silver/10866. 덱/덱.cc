#include <iostream>
#include <deque>
#include <string>

int main(){
    std::deque<int> dq;
    std::string s;
    int N,data;

    std::cin>>N;
    while(N--){
        std::cin>>s;
        if (s == "push_front"){
            std::cin>>data;
            dq.push_front(data);
        }
        else if (s == "push_back"){
            std::cin>>data;
            dq.push_back(data);
        }
        else if (s == "pop_front"){
            if(dq.empty())  std::cout<< -1 <<'\n';
            else{
                std::cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        else if (s == "pop_back"){
            if(dq.empty())  std::cout<<-1<<'\n';
            else{
                std::cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        else if (s == "size"){
            std::cout<<dq.size()<<'\n';
        }
        else if (s == "empty"){
            std::cout<<dq.empty()<<'\n';
        }
        else if (s == "front"){
            if(dq.empty())  std::cout<<-1<<'\n';
            else{
                std::cout<<dq.front()<<'\n';
            }
        }
        else if(s == "back"){
            if(dq.empty())  std::cout<<-1<<'\n';
            else{
                std::cout<<dq.back()<<'\n';
            }
        }
    }

    return 0;
}