#include <bits/stdc++.h>
using namespace std;

void addPointer(int &pointer){
    if(pointer == 99) pointer = 0;
    else pointer++;
}

void decPointer(int &pointer){
    if(pointer == 0) pointer = 99;
    else pointer--;
}
int main(){
    int T;
    string program;
    char buff[100050];
    scanf("%d\n", &T);
    int t =1;
    while(T--){
        scanf("%s", buff );
        program = string(buff);
        unsigned char c[100] = {0};
        int pointer = 0;
        for(int i = 0; i < program.length(); i++){
            char order = program[i];
            if( order == '+') c[pointer]++;
            else if(order == '-') c[pointer]--;
            else if(order == '>') addPointer(pointer);
            else if(order == '<') decPointer(pointer);
        }
        printf("Case %d:", t); t++;
        for(int i = 0; i < 100 ; i++){
            printf(" %02X", c[i]);
        }
        printf("\n");

    }
    return 0;

}