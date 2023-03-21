#include <stdio.h>
#include <string.h>

typedef struct
{
    char subject[100];
    float grade = 0;
    char credit[2];

    void input(){
        scanf("%s %f %s",subject,&grade,credit);
    }

    float score(){
        float tmp;
        if(credit[1] == '+'){
            tmp = 0.5;
        }
        else{
            tmp = 0;
        }

        if(credit[0] == 'A'){
            tmp += 4;
        }
        else if(credit[0] == 'B'){
            tmp +=3;
        }
        else if(credit[0] == 'C'){
            tmp +=2;
        }
        else if(credit[0] == 'D'){
            tmp +=1;
        }
        else if(credit[0] == 'P'){
            tmp = -1;
        }
        else{
            tmp = 0;
        }

        return tmp;
    }

}Grade;


int main(){

    Grade g[100];
    float sum = 0;
    int count =0;

    for(int i=0; i<100; i++){
        g[i].input();
        if(g[i].score() != -1){
            count += g[i].grade;
            sum += g[i].grade * g[i].score();
        }
    }

    printf("%.6f",sum / count);

    return 0;
}