/*2020604 菊池淳志
outputとlearningが分からず未完成です
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IN 3
#define PAT 4

typedef struct {
    double w[IN];
} neuron;

neuron unit;

int output(int x[IN]){
    /*mp=ニューロンから総入力の和*/
    double mp = 0.0;
    int j;
    for(j=0; j<IN; j++){
        mp += x[j]*unit.w[j];
    }
    if(mp >= 0.0){
        return 1;
    }else    
    return 0;
};

void learning(int x[IN], double eta, int ch){
    int j;
    for(j = 0; j < IN; j++){
        unit.w[j] += ch*eta*x[j];
    }
};

int main(void) {
    int out, n;
    int input[PAT][IN],t[PAT];
    int flag=0, no=0, ch;
    double eta = 0.02;
    srand((unsigned)time(NULL));

    unit.w[0] = 2.0*((double)rand()/RAND_MAX) -1;
    unit.w[1] = 2.0*((double)rand()/RAND_MAX) -1;
    unit.w[2] = 2.0*((double)rand()/RAND_MAX) -1;

    printf("w1 = %lf\n", unit.w[0]);
    printf("w2 = %lf\n", unit.w[1]);
    printf("theta = %lf\n", unit.w[2]);


    input[0][0] = 1;
    input[0][1] = 1;
    input[0][2] = 1;
    t[0] = 1;

    input[1][0] = 1;
    input[1][1] = 1;
    input[1][2] = 0;
    t[1] = 1;

    input[2][0] = 1;
    input[2][1] = 0;
    input[2][2] = 1;
    t[2] = 1;

    input[3][0] = 1;
    input[3][1] = 0;
    input[3][2] = 0;
    t[3] = 0;

    int count = 0;
    // ここを繰り返して学習させる
    do{
        count++;
        printf("============%d回目============\n", count);
        for(no = 0; no < PAT; no++){
            out = output(input[no]);
            printf("input: x1 = %d, x2 = %d\n", input[no][1], input[no][2]);
            printf("output: %d\n", out);
            if(out == t[no]){
                flag++;
            }
            else{
                ch = t[no] - out;
                learning(input[no], eta, ch);
                flag = 0;
            }
        }
        no++;
        no = no % PAT;
    }while(flag<PAT);

    printf("閾値:%lf\n", unit.w[0]);
    printf("入力値1:%lf\n", unit.w[1]);
    printf("入力値2:%lf\n", unit.w[2]);

    no = 0;
    do{
        out = output(input[no]);
        printf("pattern %d: %d\n",no, out);
        no++;
    }while(no<PAT);

    return 0;
}