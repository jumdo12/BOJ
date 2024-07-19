#include <iostream>
#include <stack>
#include <map>

int main(){
    int N,x,cnt;
    long long sum = 0;

    std::stack<std::pair<int,int>> s;

    std::cin>>N;
    while(N--){
        std::cin>>x;
        cnt = 1;

        while(!s.empty() && s.top().first <= x){
            sum += s.top().second;
            if(x == s.top().first){
                cnt += s.top().second;
            }
            s.pop();
        }

        if(!s.empty()) sum++;
        s.push({x,cnt});
    }
    std::cout<<sum;

    return 0;
}