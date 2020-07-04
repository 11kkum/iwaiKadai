/*2020604 菊池淳志*/
#include <stdio.h>

#define IN 2
#define PAT 4

typedef struct {
    double w[IN];
    double t;
} neuron;

int output(int x[], neuron unit){
    /*mp=ニューロンから総入力の和*/
    double mp;
    int out;
    int j;
    for(j=0; j<IN; j++){
        mp += (unit.w[j] * x[j]);
    }
    if(mp >= unit.t){
        out = 1;
    }else{
        out = 0;
    }
    printf("mp : %lf\n", mp);

    return out;
};

int main(void) {
    neuron unit = {{
        1.0, 1.0}, 1.5};
    int i, out, m;
    int input[PAT][IN];
    int flag; 

    input[0][0] = 1;
    input[0][1] = 1;
    input[1][0] = 1;
    input[1][1] = 0;
    input[2][0] = 0;
    input[2][1] = 1;
    input[3][0] = 0;
    input[3][1] = 0;

    do{
    flag = 1;

    printf("入力1(値は1 or 0):");
    scanf("%d",&input[PAT]);
    printf("入力2(値は1 or 0):");
    scanf("%d",&input[IN]);

    out = output(input[m], unit);
    printf("出力は%dです", out);
    printf("再入力しますか（YES=1, NO=0):");
    scanf("%d",&flag);
    }while(flag == 0);

    printf("output : %d\n", out);

    return 0;
}