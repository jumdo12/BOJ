#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

typedef struct Member{
    int age;
    std::string name;
    int num;
};

bool compare(Member m1, Member m2){
    if(m1.age == m2.age)    return m1.num < m2.num;
    else    return m1.age < m2.age;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::vector<Member> v;
    std::cin >> N;
    for(int i=0; i<N; i++){
        int age;
        std::string name;
        std::cin>>age>>name;
        v.push_back({age,name,i});
    }
    std::sort(v.begin(),v.end(),compare);
    for(int i=0; i<N; i++){
        std::cout<<v[i].age <<" "<< v[i].name << '\n';
    }
    return 0;
}