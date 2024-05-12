#include <iostream>
#include <vector>

#define mod 1000

typedef long long ll;
typedef std::vector<std::vector<ll>> Mat;

Mat operator*(const Mat& a, const Mat& b){
    ll size = a.size();
    Mat ret(size, std::vector<ll>(size));
    for(ll i = 0; i < size; i++){
        for(ll j = 0; j<size; j++){
            for(ll k = 0; k <size; k++){
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= mod;
        }
    }
    return ret;
}

Mat pow(Mat a ,ll n){
    ll size = a.size();
    Mat ret(size,std::vector<ll>(size));
    for(ll i = 0; i < size; i++){
        ret[i][i] = 1;
    }

    while(n > 0){
        if(n % 2){
            ret = ret * a;
        }
        a = a * a;
        n /= 2;
    }
    return ret;
}

void print_mat(const Mat& a){
    ll size = a.size();

    for(ll i = 0; i<size; i++){
        for(ll j = 0; j<size; j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    ll n,b;
    std::cin>>n>>b;

    Mat m(n,std::vector<ll>(n));

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            std::cin>>m[i][j];
        }
    }

    print_mat(pow(m,b));

    return 0;
}