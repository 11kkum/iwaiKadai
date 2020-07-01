#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define N 32
#define T 6

typedef struct{
	double w[N];
}neuron;

int output(int x[], neuron unit);

int main(void){
  while(1){
	int i, m, j, x[N],step;
	double p[N], b;
	neuron unit[N];

	srand((unsigned)time(NULL));

	for(i=0; i<N/2; i++){
		p[i] = 1;
	}
	for (i=N/2; i<N; i++){
		p[i] = -1;
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j)
				unit[i].w[j]=0.0;
			else
				unit[i].w[j] = p[i]*p[j]/(double)N;
		}
	}
//初期発火状態の表示

	for(i=0; i<N; i++){
		if((double)rand()/RAND_MAX >= 0.5)
			x[i] = 1;
		else
		x[i] = -1;
	}

	for(step=0; step<T; step++){
		for(i=0; i<N; i++){
			b= (double)rand()/(RAND_MAX+1.0);
			m=(int)(N*b);
			x[m] = output(x, unit[m]);
		}
	//表示
		for(i=0; i<N; i++){
		if(x[i] == 1)
			printf("@ ");
		else
		printf("- ");

		if((i+1)%8 == 0)
			printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
	sleep(1);
  }
	return 0;
}

int output(int x[], neuron unit){
  int out, i;
  double mp=0.0;

  for(i=0; i<N; i++){
  	mp += unit.w[i]*x[i];
  }

  if(mp>=0) out=1;
  else out=-1;

      return out;
}
