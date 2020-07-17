/*2020604 菊池淳志*/
#include <stdio.h>

typedef struct {
    double w[5];
    double theta;
} neuron;

int output(int x[], neuron unit){
    /*mp=ニューロンから総入力の和*/
    double mp = 0.0;
    int out;
    int j;
    for(j=0; j<5; j++){
        mp += (unit.w[j] * x[j]);
    }
    if(mp >= unit.theta){
        out = 1;
    }else{
        out = 0;
    }
    printf("mp : %lf\n", mp);

    return out;
};

int main(void) {
    neuron unit = {{
        1, 1, 1, 1, 1}, 2.5};
    int i, y;
    int x[5];

    for(i=0; i<5; i++){
        printf("x[%d] = ",i);
        scanf("%d", &x[i]);
    }

    y = output(x, unit);

    printf("output : %d\n", y);

    return 0;
}