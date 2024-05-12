#include <iostream>
#include <vector>

#define mod 1000000007

typedef long long ll;
typedef std::vector<std::vector<ll>> Mat;

Mat operator*(Mat& a, Mat& b){
    
    int N,M,K;

    N = a.size();
    M = a[0].size();
    K = b[0].size();

    Mat ret(N,std::vector<ll>(K));

    for (int i = 0; i < N; i++)
    {
        for(int j=0; j<K; j++){
            for(int k =0; k<M; k++){
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= mod;
        }
    }
    return ret;
}

ll Fibo(ll N){
    Mat temp(2, std::vector<ll>(2));

    Mat M(2,std::vector<ll>(2));
    Mat M0(2,std::vector<ll>(1));
    temp[0][0] = temp[1][1] = 1;

    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;

    M0[0][0] = 1;
    M0[1][0] = 0;

    if(N == 0) return 0;
    else if(N == 1) return 1;
    else{
        N-=2;
        while(N){
            if(N % 2){
                temp = temp * M;
            }
            M = M * M;
            N /= 2;
        }
    }

    temp = temp * M0;

    return (temp[0][0] + temp[1][0]) % mod; 
}

int main(){
    ll N;
    std::cin>>N;

    std::cout<<Fibo(N);

    return 0;
}