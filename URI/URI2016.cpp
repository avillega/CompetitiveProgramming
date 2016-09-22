#include <cstdio>
using namespace std;

int main(){
    
    int players, rounds, B, Sum, Dealus, bestPoints, N, anyUserPoints, initPoints, totalExtra=0;
    scanf("%d %d\n", &players, &rounds);
    while(rounds--){
        Sum=0;
        scanf("%d %d", &B, &Dealus);
        
        Sum+=Dealus;
        N=players-1;
        while(N--){
            scanf(" %d", &anyUserPoints);
            Sum+=anyUserPoints;
            
        }
        
        if(Sum <= B){
            initPoints=Dealus;
            bestPoints=initPoints;
            while(Dealus < 10000){
                Sum-=Dealus;
                Dealus*=10;
                Sum+=Dealus;
                if(Sum<=B) bestPoints=Dealus;
                
            }
        } 
        else{
            initPoints=0;
            bestPoints=0;
            while(Dealus > 1){
                Sum-=Dealus;
                Dealus/=10;
                Sum+=Dealus;
                if(Sum<=B){
                    bestPoints=Dealus;
                    break;   
                }              
            }
        }
        
        totalExtra+=(bestPoints-initPoints);
               
    }
    printf("%d\n", totalExtra);
    return 0;
}