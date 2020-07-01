#include<stdio.h>

typedef struct
{
	double w[2];
	double th;
} neuron;

int output(int x[], neuron unit);

int main(void){
	neuron unit = {1.0, 1.0, 1.5};
	int x[2];
	int y, flag = 0;

	do{
		printf("入力 x1:");
		scanf("%d",&x[0]);

		printf("入力 x2:");
		scanf("%d",&x[1]);

		y = output(x, unit);

		printf("出力:%d\n\n", );

		printf("終了 yes=1, no=0:");
		scanf("%d",&flag);
	} while(flag == 0);
	return 0;
}


int output(int x[], neuron unit){
  int out, i;
  double mp=0.0;
  
  for(i=0; i<N; i++){
    mp += unit.w[i]*x[i];
  }
  
  if(mp>=unit.th) out=1;
  else out=-1;
  
  return out;