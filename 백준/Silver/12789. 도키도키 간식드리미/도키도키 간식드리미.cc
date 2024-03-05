#include <iostream>
#include <stack>

int main(){
    int N,cnt=1;
    std::stack<int> s;

    std::cin>>N;    
    for(int i=0; i<N; i++){
        int temp;
        std::cin>>temp;
        
        if(temp == cnt) cnt++;
        else s.push(temp);

        while(!s.empty() && s.top() == cnt){
            cnt++;
            s.pop();
        }
    }

    if(s.empty())   std::cout<<"Nice";
    else    std::cout<<"Sad";

    return 0;
}