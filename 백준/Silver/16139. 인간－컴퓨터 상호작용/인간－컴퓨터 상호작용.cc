#include <iostream>
#include <string>

int main(){
    std::string str;
    int dp[26][200002] = {0};
    int left, right, N;
    char ch;

    std::cin>>str;

    for(int i=0; i<str.length(); i++){
        ch = str[i];
        for(int j = i; j < str.length(); j++){
            dp[ch-'a'][j+1]++;
        }
    }

    std::cin>>N;
    while(N--){
        std::cin >> ch >> left >> right;
        right++;
        std::cout<<dp[ch-'a'][right]-dp[ch-'a'][left]<<'\n';
    }

    return 0;
}