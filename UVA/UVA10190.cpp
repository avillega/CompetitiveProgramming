#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main(){    

    long long num, div;
    string results; 
    while(scanf("%lld %lld", &num, &div) != EOF){        
        bool end = num > 1 ? false:true;
        results="";        
        while(!end && num > 1){
            
            if(div > num || div <= 1 || num==0){
                end = true; 
            }            
            else if(num%div==0){
                results.append(to_string(num)+" ");                
                num/=div;                                
            }else{
                 end = true;
            }
        }
        if(end){
            printf("Boring!");
        } 
        else{            
            results.append(to_string(1));
            printf("%s", results.c_str());
        }
        printf("\n");

    }
    
    return 0;

}