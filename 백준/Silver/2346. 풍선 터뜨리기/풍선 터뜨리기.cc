#include <iostream>
#include <deque>
#include <utility>
int main(){
    std::deque<std::pair<int,int>> dq;
    int N,num,temp;
    std::pair<int,int> p;

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>num;
        dq.push_back({i+1,num});
    }

    for(int i=0; i<N; i++){
        p = dq.front();
        dq.pop_front();

        num = p.first;
        temp  = p.second;
        std::cout<<num<<" ";

        if(temp > 0){
            for(int j=0; j<temp-1; j++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            temp *= -1;
            for(int j=0; j<temp; j++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}