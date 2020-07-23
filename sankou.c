#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define IN 3
#define PAT 4
typedef struct{
    double w[IN];
}neuron;


int output(int x[IN]);
void learn(int x[IN],double eta,int ch);

neuron unit;
int main(void){
    int i,y,n;
    int input[PAT][IN];
    int t[PAT]={1,1,1,0};
    int count=0;
    double eta=0.02;
    int ch;
    srand((unsigned)time(NULL));
    input[0][0]=1;
    input[1][0]=1;
    input[2][0]=1;
    input[3][0]=1;
    
    input[0][1]=1;
    input[0][2]=1;
    input[1][1]=1;
    input[1][2]=0;
    input[2][1]=0;
    input[2][2]=1;
    input[3][1]=0;
    input[3][2]=0;
    
    for(i=0;i<IN;i++){
        unit.w[i]=(2.0*(double)rand()/(RAND_MAX))-1.0;
    }
    n=1;
    while(n==1){
        count++;
        printf("%d回目\n",count);
        n=0;
        for(i=0;i<PAT;i++){
            y=output(input[i]);
            printf("input data-> x1=%d,x2=%d\n",input[i][1],input[i][2]); 
            printf("output : %d\n",y);
            if(t[i]!=y){
	            n=1;
	            ch=t[i]-y;
	            printf("重みを変更します\n");
	            learn(input[i],eta,ch);
            }
        }   
    }
    return 0;
}
int output(int x[IN]){
    int i;
    double mp=0.0;

    for(i=0;i<IN;i++){
        mp+=x[i]*unit.w[i];
    }
    if(mp>0.0)
        return 1;
    else
    return 0;
}

void learn(int x[IN],double eta,int ch){
    int i;
    for(i=0;i<IN;i++){
        unit.w[i]+=ch*eta*x[i];
        printf("w[%d]=%f\n",i,unit.w[i]);
    }

}