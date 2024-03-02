#include <iostream>
#include <vector>
int gcd(int A, int B){
    if(B==0)    return A;
    else    return gcd(B,A%B);
}

int main(){
    int N,temp,GCD,dist=0;
    std::vector<int> v;

    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        v.push_back(temp);
    }

    temp = v[1] - v[0];
    GCD = temp;
    dist += temp;
    for(int i=2; i<N; i++){
        temp = v[i] - v[i-1];
        GCD = gcd(GCD, temp);
        dist += temp;
    }

    std::cout<< dist / GCD - (N - 1);
    
    return 0;
}