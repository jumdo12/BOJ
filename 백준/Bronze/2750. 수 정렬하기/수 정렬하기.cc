#include <iostream>

using namespace std;

int main(){
    int N, tmp; cin >>N;
    int arr[1000];

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        for(int j= i; j<N; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp; 
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << arr[i] << endl;
    }

    return 0;
}