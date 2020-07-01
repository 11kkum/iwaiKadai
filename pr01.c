#include<stdio.h>

  typedef struct{
  double w[5];
  double theta;
}neuron;

int output(int x[], neuron unit);

int main(void){
  neuron unit = {1.0, 1.0, 1.0, 1.0, 1.0, 2.5};
  int x[5];
  int i, y;

  for(i=0; i<5; i++){
    printf("x[%d]:",i);
    scanf("%d",&x[i]);
  }
  y = output(x, unit);

  printf("出力は%d\n", y);
    return 0;
}

int output(int x[], neuron unit){
  int out, i;
  double mp=0.0;

  for(i=0; i<5; i++)mp += unit.w[i]*x[i];

  if(mp >= unit.theta){
    out = 1;
      }else{
    out = 0;
  }
      return out;
}
