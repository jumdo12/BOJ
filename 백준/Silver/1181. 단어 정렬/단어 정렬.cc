#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool compare(std::string str1, std::string str2){
    if(str1.length() == str2.length()){
        return str1 < str2;
    }
    else{
        return str1.length() < str2.length();
    }
}

int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> v;
    std::string str;

    for(int i=0; i<N; i++){
        std::cin>>str;
        if(std::find(v.begin(),v.end(),str) == v.end()){
            v.push_back(str);
        }
    }
    std::sort(v.begin(),v.end(),compare);
    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<'\n';
    }
    return 0;
}