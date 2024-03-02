#include <iostream>
#include <string>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int cnt=0,len;
    std::string str,temp;
    std::map<std::string,int> m;

    std::cin>>str;
    len = str.length();

    for(int i=1; i <= len; i++){
        for(int j=0; j < len; j++){
            if(i+j > len)   break;
            temp = str.substr(j,i);
            m.insert({temp,1});
        }
    }

    std::cout<<m.size();
    return 0; 
}