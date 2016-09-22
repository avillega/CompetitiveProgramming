#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

bool ii_cmp(ii a, ii b){
    int valA = a.first - a.second;//valor negativo significa que perdio
                                  //valor ==0 significa que empato
    int valB = b.first - b.second;//valor positivo signifca que gano
    return valA > valB;

}

void sumPoints(int diferenciaGoles, int &golesPorComprar, int &points){
    if(diferenciaGoles > 0){
        points+=3;
    }else if(diferenciaGoles == 0){
        if(golesPorComprar >0){
            golesPorComprar--;
            points+=3;
        }else{
            points++;
        } 
    }else{
        if(golesPorComprar > diferenciaGoles*-1){
            golesPorComprar -= (diferenciaGoles*-1+1);
            points+=3;
        }else if(golesPorComprar==diferenciaGoles*-1){
            golesPorComprar -= diferenciaGoles*-1;
            points++;
        }
    } 
}
int main(){
    int matchs, goals;
    int score, recived;
    int points; 
    while(scanf("%d %d", &matchs, &goals)!=EOF){
        ii match[matchs];
        points=0;
        for(int i =0; i<matchs; i++){
            scanf("%d %d", &score, &recived);
            match[i] = make_pair(score, recived);
        }

        sort(match, match+matchs, ii_cmp);
        
        for(int i = 0; i<matchs; i++){
            
            sumPoints(match[i].first - match[i].second, goals, points);
           
        }
        printf("%d\n", points);
        
    }
    return 0;
}