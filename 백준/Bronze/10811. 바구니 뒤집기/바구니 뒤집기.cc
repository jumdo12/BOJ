#include <iostream>

using namespace std;

int main(){
    int arr[100];
    for(int i=0; i<100;i++){
        arr[i]=i+1;
    }

    int N,M,start,end,tmp; cin >>N>>M;

    for(int i=0; i<M; i++){
        cin >>start >> end;
        start--;
        end--;
        for(int j=0; j<=(end-start)/2; j++){
            tmp = arr[start +j];
            arr[start+j]=arr[end-j];
            arr[end-j]=tmp;
        }
    }

    for(int i=0; i<N; i++){
        cout << arr[i]<<" ";
    }

    return 0;
}