#include <iostream>
#include <algorithm>

typedef struct{
    int start;
    int end;
}table;

int comp(table& a, table& b){
    if(a.end == b.end)  return a.start < b.start;
    return a.end < b.end;
}

int main(){
    table t[1000001];
    int N,cnt,curr;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>t[i].start>>t[i].end;
    }

    std::sort(t,t+N,comp);

    curr = cnt = 0;
    for(int i=0; i<N; i++){
        if(t[i].start >= curr){
            cnt++;
            curr = t[i].end;
        }
    }

    std::cout<<cnt;

    return 0;
}