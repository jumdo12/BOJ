#include <iostream>
#include <string>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::map<std::string, std:: string,std::greater<std::string>>m;
    std::string name,status;

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>name>>status;
        if(status == "enter")  m.insert({name,status});
        else    m.erase(name);
    }

    for(auto it : m){
        std::cout << it.first << '\n';
    }

    return 0;
}