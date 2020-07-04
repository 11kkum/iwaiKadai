#include<stdio.h>
#include<stdlib.h>
#define N 32

int main(void){
	int i, m;
	double x;

	srand(131);
	for(i=0; i<20; i++){
		x= (double)rand()/(RAND_MAX+1.);
		m= (int)(N*x);
		printf("乱数[%d]:%lf\n",i+1 ,x);
	}
	return 0;
}