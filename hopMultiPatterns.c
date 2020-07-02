#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NP 3
#define N 32
#define T 30

typedef struct{
    double w[N];
} neuron;

int output(int x[], neuron unit){
    int out;
    double mp = 0.0;
    int i;
    for(i=0; i<N; i++){
        mp += unit.w[i]*x[i];
    }
    if(mp >= 0) out = 1;
    else out = -1;

    return out;
}

int mask[N];

void shuffle(void){
    int i,  n, tmp;
    n=(int)(N*(double)rand()/(RAND_MAX+1.0));
    tmp=mask[n];
    mask[n]=mask[i];
    mask[i]=tmp;
}

int main(void){
    double p[NP][N], r;
    int step;
    int m, i, j, k, x[N];
    int noise, np;
    neuron unit[N];

    srand((unsigned)time(NULL));
    // pattern 1
    for(i=0; i<N/2; i++) p[0][i] = 1;
    for(i=N/2; i<N; i++ ) p[0][i] = -1;
    // pattern2
    for(i=0; i<N/4; i++) p[1][i] =1;
    for(i=N/4; i<N/2; i++) p[1][i] =-1;
    for(i=N/2; i<3*N/4; i++) p[1][i] =1;
    for(i=3*N/4; i<N; i++) p[1][i] =-1;
    // pattern3
    for(i=0; i<N/8; i++) p[2][i] =1;
    for(i=N/8; i<N/4; i++) p[2][i] =-1;
    for(i=N/4; i<3*N/8; i++) p[2][i] =1;
    for(i=3*N/8; i<N/2; i++) p[2][i] =-1;
    for(i=N/2; i<5*N/8; i++) p[2][i] =1;
    for(i=5*N/8; i<3*N/4; i++) p[2][i] =-1;
    for(i=3*N/4; i<7*N/8; i++) p[2][i] =1;
    for(i=7*N/8; i<N; i++) p[2][i] =-1;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++) {
            unit[i].w[j]=0.0;
            if(i!=j){
                for(k=0; k<NP; k++){
                    unit[i].w[j] += (double)p[k][i]*p[k][j]/(double)N;
                }
            }
        }
    }

    for(k=0; k<NP; k++){
        printf("---- pattern %d ----\n", k+1);
        for(i=0; i<N; i++){
            if(p[k][i] == 1)printf("@ ");
            else printf("- ");
            if((i+1)%8 == 0) printf("\n");
        }
    }
    printf("================================\n");

    printf("パターン番号(0,1,2): ");
    scanf("%d", &np);
    printf("ノイズの数");
    scanf("%d", &noise);

    for(i=0; i<N; i++){
        mask[i] = i;
        x[i] = p[np][i];
    }

    shuffle();

    for(i=0; i<noise; i++){
        x[mask[i]] *= -1;
    }

    // 初期発火状態の表示
    for(i=0; i<N; i++){
        if(x[i] == 1) printf("@ ");
        else printf("- ");
        if((i+1)%8 == 0) printf("\n");
    }
    printf("==================================\n");

    for(step=0; step<T; step++){//時間のループ
        for(i=0; i<N; i++){//stepの更新
            r = (double)rand()/(RAND_MAX + 1.0);
            m = (int)(N*r);
            x[m] = output(x, unit[m]);
        }
        for(i=0; i<N; i++){//表示
            if(x[i] == 1) printf("@ ");
            else printf("- ");
            if((i+1)%8 == 0) printf("\n");
        }
        printf("--------------------------------\n");
    }

    return 0;
}