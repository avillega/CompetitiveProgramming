#include <cstdio>

using namespace std;

int main(){

    
    double base, sales;
    scanf("%*s\n%lf\n%lf", &base, &sales);
    printf("TOTAL = R$ %.2f\n", (base+(sales*0.15D)) );
    return 0;
}



