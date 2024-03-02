#include <iostream>

void Hanoi(int Size, int left, int mid ,int right){
    if(Size == 1)   std::cout << left << " " << right <<'\n';
    else{
        Hanoi(Size-1,left,right,mid);
        Hanoi(1,left,mid,right);
        Hanoi(Size-1,mid,left,right);
    }
}

int pow(int x, int n){
    if(n == 0)  return 1;
    else if(n % 2 == 0) return pow(x*x,n/2);
    else    return x*pow(x*x,(n-1)/2);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;

    std::cout<<pow(2,N)-1<<'\n';
    Hanoi(N,1,2,3);
    return 0;
}