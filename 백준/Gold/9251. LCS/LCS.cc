#include <iostream>
#include <string>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int dp[1001][1001] = {0};
    std::string str1,str2;
    std::cin>>str1>>str2;
    int len1, len2;
    len1 = str1.length();
    len2 = str2.length();

    for(int i = 1; i<=len1; i++){
        for(int j = 1; j<=len2; j++){
            if(str1[i-1] != str2[j-1]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    std::cout<<dp[len1][len2];

    return 0;
}