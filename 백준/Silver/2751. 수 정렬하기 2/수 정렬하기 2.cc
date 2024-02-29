#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[1000000];
    int t; cin >> t;

    for(int i=0; i<t; i++){
        cin >> arr[i];
    }

    sort(arr , arr+t);

    for(int i=0; i<t; i++){
        cout << arr[i] << " ";
    }

    return 0;
}