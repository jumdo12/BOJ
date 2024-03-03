#include <iostream>
#include <stack>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::stack<int> s;
    int N,num,sum=0;

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>num;
        if(!num)    s.pop();
        else    s.push(num);
    }

    while(!s.empty()){
        num = s.top();
        s.pop();
        sum += num;
    }
    std::cout<<sum;

    return 0;
}