#include <iostream>

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int arr[1025][1025] = {0};
    long long sum[1025][1025] = {0};
    int N,M;
    int x1,y1,x2,y2;
    std::cin>>N>>M;

    for(int i =1; i<=N; i++){
        for(int j =1; j<=N; j++){
            std::cin>>arr[i][j];
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    while(M--){
        std::cin>>x1>>y1>>x2>>y2;
        long long ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        std::cout<<ans<<'\n';
    }

    return 0;
}