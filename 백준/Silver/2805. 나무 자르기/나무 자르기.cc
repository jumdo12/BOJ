#include <iostream>
#include <vector>

typedef long long ll;

ll max(ll a, ll b){
    return a > b ? a : b;
}

int main(){
    ll N,M,ans,temp;
    ll left = 1, right = 0;
    std::cin>>N>>M;

    std::vector<ll> v;

    for(int i=0; i<N; i++){
        std::cin>>temp;
        v.push_back(temp);
        right = max(right,temp);
    }

    ans = 0;

    while(left <= right){
        ll mid = (left + right) / 2;

        temp = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] - mid > 0){
                temp += v[i] - mid;
            }
        }

        if(temp >= M){
            left = mid + 1;
            ans = max(ans,mid);
        }
        else{
            right = mid - 1;
        }
    }
    std::cout<<ans;

    return 0;
}