#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

void nextSec(int index, vector<string> &dict, list<string> &generated, string rule){
    
    if(index==rule.length()){
        
        for(string c : generated){
            cout << c;
        }
        cout << '\n';
    }else{
        if(rule[index] == '0'){
            for(int i = 0; i<10 ; i++ ){
                string d = " ";
                d[0]= (char)(i + '0');
                generated.push_back(d);
                nextSec(index+1, dict, generated, rule);
                generated.pop_back();
            }
        }else{
            for(string word : dict){
                generated.push_back(word);
                nextSec(index+1, dict, generated, rule);
                generated.pop_back();
            }
        }
    }

}

int main(){_
    int n, m;
    vector<string> dictionary, rules;
    string tempWord;
    while(cin >> n){
        dictionary.clear();
        while(n--){
            cin >> tempWord;
            dictionary.push_back(tempWord);
            
        }
        //cout << "dict size = " << dictionary.size();
        cin >> m;
        rules.clear();
        while(m--){
            cin >> tempWord;
            rules.push_back(tempWord);
        }
        
        //cout << "rules size = " << rules.size();
        for(string rule : rules){
            list<string> generated;
            cout << "--" << '\n';
            nextSec(0, dictionary, generated, rule);
            
        }
    }
    return 0;
}