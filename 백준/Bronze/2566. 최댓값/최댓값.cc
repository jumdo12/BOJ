#include <iostream>

int main(){
    int Mat[9][9];
    int Max,Row,Col;
    Max = Row = Col = -1;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            std::cin>>Mat[i][j];
            if(Mat[i][j] > Max){
                Max = Mat[i][j];
                Row = i;
                Col = j;
            }
        }
    }
    std::cout<<Max<<std::endl;
    std::cout<<Row+1 <<" "<<Col+1;
    return 0;
}