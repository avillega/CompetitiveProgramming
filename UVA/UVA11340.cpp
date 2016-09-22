#include <cstdio>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int main(){
    map<char, int> charPrice;
    char artLine[10100];    
    int T; scanf("%d\n", &T);
    int N;
    ll totalCents;
    while(T--){        
        totalCents=0;
        charPrice.clear();
        scanf("%d\n", &N);        
        char c;
        int val;
        while(N--){            
            scanf("%c %d\n", &c, &val);            
            charPrice[c]=val;
        }        
        scanf("%d\n", &N);
        while(N--){
            gets(artLine);
            string line(artLine);            
            for(char c: line){
                totalCents+=charPrice[c];
            }            
        }
        
        printf("%.2f$\n", totalCents/100.0 );
    }
    return 0;

}