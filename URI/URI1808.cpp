#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    string line;
    int points, cant;
    points=0;
    cant=0;
    cin >> line;
    int i = 0;
    while(i < line.size()){
        
        if(line[i] != '1'){
            points+= line[i] -'0';
            cant++;
            i++;
        }else{
            if(i < line.size()-1){
                if(line[i+1] == '0'){
                    points+=10;
                    cant++;
                    i+=2;
                }else{
                    points+=1;
                    cant++;
                    i++;
                }
            }else{
                points+=1;
                cant++;
                i++;
            }
        }
    }
    printf("%.2f\n", (double) points/cant);
    return 0;
}