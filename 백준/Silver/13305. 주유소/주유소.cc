#include <iostream>

int cost[100001] = {0};
int dist[100001] = {0};

int min_cost;
int N;

long long sum = 0;

void solve(){
    min_cost = cost[0];

    for(int i = 1; i<N; i++){
        sum += ((long long)min_cost * (long long)dist[i-1]);

        if(min_cost > cost[i]){
            min_cost = cost[i];
        }
    }

    std::cout<<sum;
}

int main(){
    std::cin>>N;

    for(int i=0; i<N-1; i++){
        std::cin>>dist[i];
    }
    for(int i=0; i<N; i++){
        std::cin>>cost[i];
    }

    solve();

    return 0;
}