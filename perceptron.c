/*2020604 菊池淳志*/
#include <stdio.h>
#include <stdlib.h>

#define IN 3
#define PAT 4

typedef struct {
    double w[IN];
} neuron;

int no;
double eta=0.01;

int output(neuron uint,int input[no][IN]){
    /*mp=ニューロンから総入力の和*/
    double mp;
    int out;
    int j;
    for(j=0; j<IN; j++){
        mp += (unit.w[j] * input[no][j]);
    }
    if(mp >= 0.0){
        out = 1;
    }else{
        out = 0;
    }
    return out;
};

void learning(neuron unit, int input[IN]){
    unit.w[0] = eta*()
};

neuron unit;

int main(void) {
    int i, out, m;
    int input[PAT][IN],t[PAT];
    int flag, no, ch;

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
    input[3][2] = 1;
    t[3] = 0;

    // ここを繰り返して学習させる
    do{
    flag = 0;
    out = output();
    if(out==t[no]){
        ch = t[no] - out;
        learning();
    }
    no++;
    no = no % PAT;
    }while(flag<PAT);

    printf("閾値:%d\n", unit.w[0]);
    printf("入力値1:%d\n", unit.w[1]);
    printf("入力値2:%d\n", unit.w[2]);
    
    no = 0;
    do{

    }while(no<PAT);

    return 0;
}