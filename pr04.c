#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 32
#define T 6

typedef struct{
	double w[N];
}neuron;

int output(int x[], neuron unit);
void shaffle(void);

  int i, m, j, x[N], x1[N], x2[N], step, noise, mask[N],tmp,np;

int main(void){
  //int i, m, j, x[N], x1[N], x2[N], step, noise, mask[N],tmp;
  double p[3][N], b;
  neuron unit[N], unit1[N], unit2[N];
	
  
  srand((unsigned)time(NULL));
  
  //p0のパターン
  for(i=0; i<N/2; i++){
    p[0][i] = 1;
	}
  for (i=N/2; i<N; i++){
    p[0][i] = -1;
  }
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if(i==j)
	unit[i].w[j]=0.0;
      else
	unit[i].w[j] += p[0][i]*p[0][j]/(double)N;
    }
  }
  
  //p1のパターン
  for(i=0; i<N; i++){
    if((i>=0 && i<=7) || (i>=16 && i<=23))
      p[1][i] = 1;
    else
      p[1][i] = -1;
  }
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if(i==j)
	unit1[i].w[j]=0.0;
      else
	unit1[i].w[j] += p[1][i]*p[1][j]/(double)N;
    }
  }
  
  //p2のパターン
  for(i=0; i<N; i++){
    if((i>=0 && i<=3) || (i>=8 && i<=11) || (i>=16 && i<=19) || (i>=24 && i<=27))
      p[2][i] = 1;
    else
      p[2][i] = -1;
  }
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if(i==j)
	unit2[i].w[j]=0.0;
      else
	unit2[i].w[j] += p[2][i]*p[2][j]/(double)N;
    }
  }

  printf("パターン番号:");
  scanf("%d",&np);
  printf("ノイズ数:");
  scanf("%d",&noise);   

  for(i=0; i<N; i++){
    mask[i] = i;
    x[i] = p[np][i];
  }

  shaffle();

  for(i=0; i<noise; i++){
    x[mask[i]] *= -1;
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
void shaffle(void){
  int n;
  n=(int)(N*(double)rand()/(RAND_MAX+1.0));
  tmp=mask[n];
  mask[n]=mask[i];
  mask[i]=tmp;
}
