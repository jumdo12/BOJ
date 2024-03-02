#include <stdio.h>

int gcd(int a , int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    int n; scanf("%d",&n);
    int a , b , T;
    for(int i=0; i<n;i++){
        scanf("%d %d", &a, &b);
        T = gcd(a,b);
        printf("%d\n",a*b/T);
    }
    return 0;
}