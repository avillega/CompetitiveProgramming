#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d\n", &N)!=EOF){
        if(N%6==0) printf("Y\n");
        else printf("N\n"); 
    }
    return 0;
}