#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int dp[26][200003] = {0};
    int left, right, N;
    char ch;

    std::cin>>str;

    dp[str[0]-'a'][0] = 1;
    for(int i=1; i<str.length(); i++){
        ch = str[i];
        for(int j = 0; j < 26; j++){
            dp[j][i] = dp[j][i-1];
        }
        dp[ch-'a'][i]++;
    }

    std::cin>>N;
    while(N--){
        std::cin >> ch >> left >> right;
        if(left == 0){
            std::cout << dp[ch - 'a'][right]<<'\n';
        }
        else{
            std::cout << dp[ch - 'a'][right] - dp[ch - 'a'][left-1] << '\n';
        }
    }

    return 0;
}