#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, int> fromTo;

int countP(string cadena){
    int c =0;
    int N=0;
    while(N < 12){
        c= cadena[N]=='o' ? c+1:c;
        N++;
    }
    return c;

}
vector<fromTo> findMoves(string cadena){
    vector<fromTo> ret;
    for(int i =0; i < 10; i++){
        if(cadena[i]=='-'){
            if(cadena[i+1]=='o' && cadena[i+2]=='o') ret.push_back(make_pair(i+2, i));
        }else{
            if(cadena[i+1]=='o' && cadena[i+2]=='-') ret.push_back(make_pair(i, i+2));
        }
    }
    return ret;
}

int findMin(string cadena){
    vector<fromTo> moves = findMoves(cadena);
    int min=13;
    if(moves.size()==0) return countP(cadena);
    else{
        string copiaCadena;
        for(fromTo move: moves){
            copiaCadena=cadena;
            
            if(move.first > move.second){
                copiaCadena[move.first]='-';
                copiaCadena[move.first-1]='-';
                copiaCadena[move.second]='o';
            }else{
                copiaCadena[move.first]='-';
                copiaCadena[move.first+1]='-';
                copiaCadena[move.second]='o';
            }
            int posible = findMin(copiaCadena);
            min= min < posible ? min:posible; 
        }
    }
    
    return min;
}

int main(){
    ios_base::sync_with_stdio(false);
    int N, min;
    string cad;
    cin >> N;
    while(N--){
        cin >> cad; 
        min = findMin(cad);
        cout << min << '\n';
    }
    cout.flush();
    return 0;
    
    

}