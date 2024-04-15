#include <iostream>
#include <vector>
#include <algorithm>

int Bsearch(std::vector<int>&v,int left , int right ,int data){
    int mid = (left + right) / 2;
    if(left <= right){
        if(v[mid] == data)  return 1;
        else if(v[mid] > data)  return Bsearch(v,left,mid-1,data);
        else    return Bsearch(v,mid+1,right,data);
    }
    return 0;
}

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    std::vector<int> v;
    int N,M;
    std::cin>>N;

    for(int i=0; i<N; i++){
        int temp;
        std::cin>>temp;
        v.push_back(temp);
    }


    std::cin>>M;

    sort(v.begin(),v.end());

    for(int i=0; i<M; i++){
        int temp;
        std::cin>>temp;
        std::cout<<Bsearch(v,0,N-1,temp)<<'\n';
    }

    return 0;
}