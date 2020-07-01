#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 32
#define T 20

typedef struct{
  double w[N];
}neuron;

int output(int x[], neuron unit);

int main(void){
  neuron unit[N];
  int x[N];
  int i,j,m,block,random,count=0;
  int memory[16] = {100};
  int step,pattern,noize,fire=0,burn=0;
  double p[3][N];
  double p2[N];

  srand((unsigned)time(NULL));
  
  // printf("pattern0\n");
  printf("--------- pattern 0 ---------\n");
  for(i=0;i<N/2;i++){
    p[0][i] = 1;
    printf("@ ");
    if((i+1)%8==0)
      printf("\n");
  }
  for(i=N/2;i<N;i++){
    p[0][i] = -1;
    printf("- ");
    if((i+1)%8==0)
      printf("\n");
  }
  //printf("pattern1\n");
  printf("--------- pattern 1 ---------\n");
  for(i=0;i<N;i++){
    if(i<8 || (16<=i && i<24)){ 
      p[1][i] = 1;
    printf("@ ");
    if((i+1)%8==0)
      printf("\n");
    }
    else{
      p[1][i]= -1;
      printf("- ");
      if((i+1)%8==0)
	printf("\n");
    }
  }

    //printf("pattern2\n");
    printf("--------- pattern 2 ---------\n");
    for(i=0;i<N;i++){
      if(i<4 || (8<=i && i<12) || (16<=i && i<20) || (24<=i && i<28)){
	p[2][i] = 1;
      printf("@ ");
      if((i+1)%8==0)
	printf("\n");
      }
      else{
	p[2][i] = -1;
	printf("- ");
	if((i+1)%8==0)
	  printf("\n");
      }
    }
    
   printf("chose pattern 0,1 or 2\n");
   scanf("%d",&pattern);
   printf("\n");
   printf("noize num\n");
   scanf("%d",&noize);
   printf("\n");
   for(i=0; i<noize; i++){
   random = rand()%N;
   /* count = 0;
   for(int j=0; j<=i j++){
     if(memory[j] == random)       
        count = 1;
     if(count == 0)
       memory[i] = random;
       }*/
  
   if(p[pattern][random] == 1)
     p[pattern][random] = -1;
   else
     p[pattern][random] = 1;
   }

   printf("select pattern %d\n",pattern);
   for(i=0;i<N;i++){
     if(p[pattern][i] == 1)
       printf("@ ");
     else
       printf("- ");
     if((i+1)%8==0){
       printf("\n");
     }
   }
 printf("-------------------------------------\n");

 printf("select mix pattern\n");
 printf("pattern1 +++\t");
 printf("pattern2 ---\t");
 printf("pattern3 +-+\t");
 printf("\n");
 printf("pattern4 -+-\t");
 printf("pattern5 ++-\t");
 printf("pattern6 --+\t");
 printf("\n");
 printf("pattern7 +--\t");
 printf("pattern8 -++\t");
 scanf("%d",&burn);


 //mix 
 for(block=0; block<3; block++){
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
	if(i == j)
	  unit[i].w[i] = 0;
	else
	  unit[i].w[j] = p[block][i]*p[block][j]/N;
      }
    }
 }
  
  for(i=0; i<N; i++){//decided random
    fire = 0;
      
    if(burn == 1){
      fire += p[0][i];
      fire += p[1][i];
      fire += p[2][i];
    }
    
    if(burn == 2){
      fire -= p[0][i];
      fire -= p[1][i];
      fire -= p[2][i];
    }

    if(burn == 3){
      fire += p[0][i];
      fire -= p[1][i];
      fire += p[2][i];
    }
    
    if(burn == 4){
      fire -= p[0][i];
      fire += p[1][i];
      fire -= p[2][i];
    }    

    if(burn == 5){
      fire += p[0][i];
      fire += p[1][i];
      fire -= p[2][i];
    }

    if(burn == 6){
      fire -= p[0][i];
      fire -= p[1][i];
      fire += p[2][i];
    }

    if(burn == 7){
      fire += p[0][i];
      fire -= p[1][i];
      fire -= p[2][i];
    }
    
    if(burn == 8){
      fire -= p[0][i];
      fire += p[1][i];
      fire += p[2][i];
    }
 
  
    if(fire >= 1) 
      x[i] = 1;
    else
      x[i] = -1;
  }  

    printf("初期状態\n");
    for(i=0;i<N;i++){
      if(x[i] == 1)
	printf("@ ");
      else
	printf("- ");
      if((i+1)%8==0){
	printf("\n");
      }
    }
    printf("------------------------------------\n");

    for(step =0;step<T;step++){
      for(i=0;i<N;i++){
	double random = (double)rand()/(RAND_MAX+1.0);
	m = (int)(N*random);
	x[m] = output(x,unit[m]);
	
      }
      
      for(i=0;i<N;i++){
	if(x[i] == 1)
      	  printf("@ ");
	else
	  printf("- ");
	if((i+1)%8==0)
	  printf("\n");
      }
      printf("-------------------------------------\n");
    }
}

int output(int x[], neuron unit){
  double mp=0; 
  int out;
  int i;

  for(i=0;i<N;i++){
    mp += unit.w[i]*x[i];
  }

  if(mp>=0)
    out=1;
  else 
    out=-1;

  return out;
}
