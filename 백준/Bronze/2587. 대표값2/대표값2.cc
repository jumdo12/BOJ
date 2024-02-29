#include <iostream>

using namespace std;

int main(){
    int med , mean=0,tmp;
    int arr[5];

    for(int i=0; i<5; i++){
        cin >> arr[i];
        mean += arr[i];
    }

    for(int i=0; i<5; i++){
        for(int j= i; j<5; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp; 
            }
        }
    }

    cout << mean / 5 << endl;
    cout << arr[2];

    return 0;
}