#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair< int , int > flip; 
int main(){_
    int N;
    while(cin >>N){
        vector<int> arr;
        vector<flip> flips; 
        int tmp;
        while(N--){
            cin >> tmp;
            arr.push_back(tmp);
        }
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] > arr[i+1]){    
                           
                flips.push_back(flip(i, i+1));
                
            }
        }
        int max = 1, inicio, fin;
        
        if(flips.empty()){
            cout << arr.size() << '\n';
        }else{
            for(int i = 0; i<flips.size(); i++){
                inicio = i == 0 ? 0: flips[i-1].second;
                fin = i == flips.size()-1 ? arr.size()-1 : flips[i+1].first;                
                max = max > fin - inicio ? max:fin-inicio;
            }
            cout << max+1 << '\n';
        }
        
        
        

    } 
    return 0;

}