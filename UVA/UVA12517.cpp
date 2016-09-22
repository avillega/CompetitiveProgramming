#include <bits/stdc++.h>
using namespace std;

int digitSum(int a){
    int sum = 0;
    while(a>0){
        sum += a%10;
        a/=10;
    }
    return sum;
}

int main(){
    int N, M, sum;
    while(scanf("%d %d\n", &N, &M)){
        if(N==0 && M==0) break;
        sum =0;
        for(; N <= M ; N++ ){
            sum+=digitSum(N);
        }
        printf("%d\n", sum);
    }
}