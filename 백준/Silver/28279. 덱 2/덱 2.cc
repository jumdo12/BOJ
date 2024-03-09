// 1 X : 정수 X를 덱의 앞에 넣는다.(1 ≤ X ≤ 100, 000)
// 2 X : 정수 X를 덱의 뒤에 넣는다.(1 ≤ X ≤ 100, 000)
// 3 : 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
// 4 : 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
// 5 : 덱에 들어있는 정수의 개수를 출력한다.
//6 : 덱이 비어있으면 1, 아니면 0을 출력한다.
// 7 : 덱에 정수가 있다면 맨 앞의 정수를 출력한다.없다면 - 1을 대신 출력한다.
// 8 : 덱에 정수가 있다면 맨 뒤의 정수를 출력한다.없다면 - 1을 대신 출력한다.

#include <iostream>
#include <deque>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::deque<int> q;
    int t,N,num;

    std::cin>>t;
    for(int i=0; i<t; i++){
        std::cin>>N;
        if(N==1){
            std::cin>>num;
            q.push_front(num);
        }
        else if(N==2){
            std::cin>>num;
            q.push_back(num);
        }
        else if(N==3){
            if(q.empty()){
                std::cout<<-1<<'\n';
            }
            else{
                num = q.front();
                q.pop_front();
                std::cout<<num<<'\n';
            }
        }
        else if(N==4){
            if(q.empty()){
                std::cout<<-1<<'\n';
            }
            else{
                num = q.back();
                q.pop_back();
                std::cout<<num<<'\n';
            }
        }
        else if(N==5){
            std::cout<<q.size()<<'\n';
        }
        else if(N==6){
            std::cout<<q.empty()<<'\n';
        }
        else if(N==7){
            if(!q.empty()){
                std::cout<<q.front()<<'\n';
            }
            else{
                std::cout<<-1<<'\n';
            }
        }
        else{
            if(!q.empty()){
                std::cout<<q.back()<<'\n';
            }
            else{
                std::cout<<-1<<'\n';
            }
        }
    }
    return 0;
}