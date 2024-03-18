#include <iostream>

int w[51][51][51] = {1,};

int W(int a, int b, int c){
    if(a<=0||b<=0||c<=0)    return 1;
    if(a>20||b>20||c>20)    return W(20,20,20);

    if(w[a][b][c])  return w[a][b][c];
    if(a<b&&b<c)    w[a][b][c] = W(a,b,c-1) + W(a,b-1,c-1) - W(a,b-1,c);
    else    w[a][b][c] = W(a-1,b,c)+W(a-1,b-1,c)+W(a-1,b,c-1)-W(a-1,b-1,c-1);

    return w[a][b][c];
}

int main(){
    int a,b,c;
    while(1){
        std::cin>>a>>b>>c;
        if(a == -1 && b == -1 && c == -1)   break;

        std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<W(a,b,c)<<'\n';
    }
    return 0;
}