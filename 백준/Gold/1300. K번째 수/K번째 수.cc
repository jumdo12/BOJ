#include <iostream>

typedef long long ll;

ll count(ll num , ll n){
    ll sum = 0;
    ll temp;
    for(int i = 1; i <= n; i++){
        temp = num / i;
        if(temp > n)    temp = n;
        sum += temp;
    }
    return sum;
}

void solve(ll n , ll k ,ll left, ll right){
    ll mid;
    
    while(left <= right){
        mid = (left + right) / 2;

        if(left == right){
            std::cout<<left;
            break;
        }

        if(count(mid,n) >= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
}

int main(){
    ll n,k;
    std::cin>>n>>k;

    solve(n,k,1,n*n);

    return 0;
}