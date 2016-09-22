#include <cstdio>

using namespace std;

int main(){

    int N;
    scanf("%d", &N);
    while(N!=0){
        int lostPlaces=0, currentPos[N], polePos[N];
        printf("N=%d\n", N);
        bool finish=false;
        for(int i=0; i < N; i++){
            scanf("%d %d",&currentPos[i], &lostPlaces );
            if(!finish){
                if(polePos[i+lostPlaces] == 0){
                    polePos[i+lostPlaces] = currentPos[i];
                }else{
                    printf("-1\n");
                    finish=true;                
                }
            }
        }
        
        if(finish){
            scanf("%d", &N);
            continue;
        } 
        printf("%d", polePos[0]);
        for(int i=1; i < N; i++){
            printf(" %d", polePos[i]);
        }
        printf("\n");
        scanf("%d", &N);
        
    }
    return 0;
}