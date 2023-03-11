#include <iostream>

using namespace std;

int main(){
    int N; cin >>N;

    for(int i=0; i<2*N-1; i++){
        if(i<N){
            for (int j = N-i; j>1; j--)
            {
                cout << " ";
            }
            for (int j=0; j<2*i+1; j++ )
            {
                cout <<"*";
            }
            cout << endl;
        }
        else{
            for(int j=i-N; j>-1; j--)
            {
                cout <<" ";
            }
            for(int j=0; j<2*((2*N-1)-i)-1; j++)
            {
                cout <<"*";
            }
            cout << endl;
        }
    }

    return 0;
}