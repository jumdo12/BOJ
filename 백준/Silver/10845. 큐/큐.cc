#include <iostream>
#include <queue>
#include <string>

int main(){
    std::queue<int> q;
    std::string str;
    int cnt, data;

    std::cin>>cnt;
    while(cnt--){
        std::cin>>str;
        if(str == "push"){
            std::cin>>data;
            q.push(data);
        }
        else if(str == "pop"){
            if(q.empty())   std::cout<<-1<<'\n';
            else{
                std::cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(str == "size"){
            std::cout<<q.size()<<'\n';
        }
        else if(str == "empty"){
            std::cout<<q.empty()<<'\n';
        }
        else if(str == "front"){
            if(q.empty())   std::cout<<-1<<'\n';
            else    std::cout<<q.front()<<'\n';
        }
        else if(str == "back"){
            if(q.empty())   std::cout<<-1<<'\n';
            else    std::cout<<q.back()<<'\n';
        }
    }

    return 0;
}