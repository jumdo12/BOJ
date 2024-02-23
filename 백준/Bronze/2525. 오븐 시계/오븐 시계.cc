#include <iostream>
using namespace std;

int main() {

    int H, M , Time;
    cin >> H >> M >> Time;

    M = 60 * H + M;

    M += Time;

    H = (M / 60) % 24;
    
    M %= 60;

    cout << H <<" " << M;

    return 0;
}
