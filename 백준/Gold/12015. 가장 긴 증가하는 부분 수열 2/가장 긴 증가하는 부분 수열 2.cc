#include <iostream>
#include <vector>

int find_idx(std::vector<int>& v, int tmp){
    int left , right , mid;
    left = 0; right = v.size()-1;

    while(left <= right){
        mid = (left + right) / 2;

        if(v[mid] >= tmp){
            right = mid-1;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N, tmp;
    std::vector<int> v;

    std::cin>>N;
    std::cin>>tmp;

    v.push_back(tmp);

    for(int i = 1;i<N; i++){
        std::cin>>tmp;

        if(v.back() < tmp){
            v.push_back(tmp);
        }
        else{
            int idx = find_idx(v,tmp);
            v[idx] = tmp;
        }
    }

    std::cout<<v.size();

    return 0;
}