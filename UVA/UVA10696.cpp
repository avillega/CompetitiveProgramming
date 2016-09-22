#include <cstdio>

int f(int N){
    if(N>100) return N-10;
    return f(f(N+11));
}

int main(){

    int N, ans;
    while(scanf("%d", &N), N!=0){
        ans=f(N);
        printf("f91(%d) = %d\n", N, ans);
    }
    return 0;

}