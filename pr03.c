#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 32
#define T 6

typedef struct{
	double w[N];
}neuron;

int output(int x[], neuron unit);

int main(void){
	int i, m, j, x[N], x1[N], x2[N], step;
	double p[N], p1[N], p2[N], b;
	neuron unit[N], unit1[N], unit2[N];

	srand((unsigned)time(NULL));

	//pのパターン
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
				unit[i].w[j] += p[i]*p[j]/(double)N;
		}
	}

	//p1のパターン
	for(i=0; i<N; i++){
		if((i>=0 && i<=7) || (i>=16 && i<=23))
		p1[i] = 1;
		else
		p1[i] = -1;
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j)
				unit1[i].w[j]=0.0;
			else
				unit1[i].w[j] += p1[i]*p1[j]/(double)N;
		}
	}

	//p2のパターン
	for(i=0; i<N; i++){
		if((i>=0 && i<=3) || (i>=8 && i<=11) || (i>=16 && i<=19) || (i>=24 && i<=27))
		p2[i] = 1;
		else
		p2[i] = -1;
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j)
				unit2[i].w[j]=0.0;
			else
				unit2[i].w[j] += p2[i]*p2[j]/(double)N;
		}
	}


//初期発火状態の表示

	for(i=0; i<N; i++){
		if((double)rand()/RAND_MAX >= 0.5){
			x[i] = 1;
			x1[i] = 1;
			x2[i] = 1;
		}else{
		x[i] = -1;
		x1[i] = -1;
		x2[i] = -1;
	}
	}

printf("p表示\n");
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

printf("p1表示\n");
	for(step=0; step<T; step++){
		for(i=0; i<N; i++){
			b= (double)rand()/(RAND_MAX+1.0);
			m=(int)(N*b);
			x1[m] = output(x1, unit1[m]);
		}
		for(i=0; i<N; i++){
		if(x1[i] == 1)
			printf("@ ");
		else
		printf("- ");

		if((i+1)%8 == 0)
			printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

printf("p2表示\n");
	for(step=0; step<T; step++){
		for(i=0; i<N; i++){
			b= (double)rand()/(RAND_MAX+1.0);
			m=(int)(N*b);
			x2[m] = output(x2, unit2[m]);
		}
		for(i=0; i<N; i++){
		if(x2[i] == 1)
			printf("@ ");
		else
		printf("- ");

		if((i+1)%8 == 0)
			printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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
