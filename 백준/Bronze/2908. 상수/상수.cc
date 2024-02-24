#include <iostream>

using namespace std;

int main(){
    string A , B; cin >> A >> B;

    for(int i = 2; i>=0; i--){
        if(A[i] > B[i]){
            for(int j=2; j>=0; j--){
                cout << A[j];
            }
            break;
        }
        else if(A[i] < B[i]){
            for(int j=2; j>=0; j--){
                cout << B[j];
            }
            break;
        }
    }

    return 0;
}