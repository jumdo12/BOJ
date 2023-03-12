#include <iostream>

using namespace std;

int main(){
    int N,M,i,k,j;
    cin >> N >>M;
    int arr[101];
    int tmp[101];

    for(int x=1; x<101; x++){
        arr[x] = x;
    }

    for(int x=0; x<M; x++){
        cin >> i >> k >> j;
        int idx = 0;
        for(int y=j; y<=k; y++){
            tmp[idx] = arr[y];
            idx++;
        }
        for(int y=i; y<j; y++){
            tmp[idx] = arr[y];
            idx++;
        }
        for(int y=i; y<=k; y++){
            arr[y] = tmp[y-i];
        }
    }

    for(int x=1; x<=N; x++){
        cout << arr[x] << " ";
    }

    return 0;
}