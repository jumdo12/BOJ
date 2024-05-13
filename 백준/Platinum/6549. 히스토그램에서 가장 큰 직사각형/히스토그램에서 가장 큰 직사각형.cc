#include <iostream>
#include <vector>
#include <string.h>

typedef long long ll;

std::vector<ll> v;
ll arr[100002] = {0};

ll max(ll a, ll b){
    return a > b ? a : b;
}

int main(){
    int cnt;
    ll ans = 0;
    ll w;

    while(1){
        std::cin>>cnt;
        if(!cnt)  break;

        v.push_back(0);

        for(int i =1; i<=cnt; i++){
            std::cin>>arr[i];
        }

        for(int i=1; i<=cnt+1; i++){
            while(!v.empty() && arr[v.back()] > arr[i]){
                w = v.back();
                v.pop_back();
                ans = max(ans,arr[w] * (i-1-v.back()));
            }
            v.push_back(i);
        }
        std::cout << ans<<'\n';
        v.clear();
        memset(arr,0,100002);
        ans = 0;
    }
    return 0;
}