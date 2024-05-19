#include <iostream>
#include <queue>
#include <vector>

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::priority_queue<int , std::vector<int>, std::greater<int>> h;
    std::vector<int> v;

    int cnt, tmp;

    std::cin>>cnt;

    while(cnt--){
        std::cin>>tmp;
        if(tmp){
            h.push(tmp);
        }
        else{
            if(h.empty()){
                std::cout<<"0"<<'\n';
            }
            else{
                std::cout<<h.top()<<'\n';
                h.pop();
            }
        }
    }
    return 0;
}