#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i, s, n) for(int i = s; i < n ; i++)

typedef vector< vector<bool> > picture; //false is e and true is f



void create(string &a, picture &pic, int iniF, int iniC, int finF, int finC, int &index){
    if(a[index] == 'p'){
        index++;
        create(a, pic, iniF, (iniC+finC)/2, (iniF+finF)/2, finC, index);
        create(a, pic, iniF, iniC, (iniF+finF)/2, (iniC+finC)/2, index );
        create(a, pic,(iniF+finF)/2 ,iniC, finF, (iniC+finC)/2, index);
        create(a, pic, (iniF+finF)/2, (iniC+finC)/2 , finF, finC, index);
        return;
    }else if(a[index]=='e'){
        index++;        
    }else{
        index++;
        f(i, iniF, finF){
            f(j, iniC, finC){
                pic[i][j]=true;
            }
        }
        return;
    }

    

}

int main(){_
    string a, b;
    int T, blacks, index;
    cin >> T;
    while(T--){
        cin >> a;
        cin >> b;
        blacks = 0;
        index = 0;
        picture pic1(32, vector<bool>(32, false)), pic2(32, vector<bool>(32, false));
        create(a, pic1, 0,0, 32,32, index);
        index = 0;
        create(b, pic2, 0,0, 32,32, index);
        f(i, 0, 32){
            f(j, 0, 32){
                if(pic1[i][j] || pic2[i][j]) blacks++;                
            }
            
        }
        cout << "There are " << blacks << " black pixels.\n";
    }
    return 0;
}