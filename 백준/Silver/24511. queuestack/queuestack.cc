#include <iostream>
#include <deque>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,temp;
    std::deque<int> dq;
    std::vector<int> v;

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        v.push_back(temp);
    }
    for(int i=0; i<N; i++){
        std::cin>>temp;
        if(!v[i]){
            dq.push_back(temp);
        }
    }

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        dq.push_front(temp);
        temp = dq.back();
        dq.pop_back();
        std::cout<<temp<<" ";
    }

    return 0;
}