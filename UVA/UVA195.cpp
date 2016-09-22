#include <bits/stdc++.h>


using namespace std;
int main(){
    map<char, int> m;
    map<int, char> p;
    m['A'] = 0;
    m['a'] = 1;
    m['B'] = 2;
    m['b'] = 3;
    m['C'] = 4;
    m['c'] = 5;
    m['D'] = 6;
    m['d'] = 7;
    m['E'] = 8;
    m['e'] = 9;
    m['F'] = 10;
    m['f'] = 11;
    m['G'] = 12;
    m['g'] = 13;
    m['H'] = 14;
    m['h'] = 15;
    m['I'] = 16;
    m['i'] = 17;
    m['J'] = 18;
    m['j'] = 19;
    m['K'] = 20;
    m['k'] = 21;
    m['L'] = 22;
    m['l'] = 23;
    m['M'] = 24;
    m['m'] = 25;
    m['N'] = 26;
    m['n'] = 27;
    m['O'] = 28;
    m['o'] = 29;
    m['P'] = 30;
    m['p'] = 31;
    m['Q'] = 32;
    m['q'] = 33;
    m['R'] = 34;
    m['r'] = 35;
    m['S'] = 36;
    m['s'] = 37;
    m['T'] = 38;
    m['t'] = 39;
    m['U'] = 40;
    m['u'] = 41;
    m['V'] = 42;
    m['v'] = 43;
    m['W'] = 44;
    m['w'] = 45;
    m['X'] = 46;
    m['x'] = 47;
    m['Y'] = 48;
    m['y'] = 49;
    m['Z'] = 50;
    m['z'] = 51;
    p[0] = 'A';
    p[1] = 'a';
    p[2] = 'B';
    p[3] = 'b';
    p[4] = 'C';
    p[5] = 'c';
    p[6] = 'D';
    p[7] = 'd';
    p[8] = 'E';
    p[9] = 'e';
    p[10] = 'F';
    p[11] = 'f';
    p[12] = 'G';
    p[13] = 'g';
    p[14] = 'H';
    p[15] = 'h';
    p[16] = 'I';
    p[17] = 'i';
    p[18] = 'J';
    p[19] = 'j';
    p[20] = 'K';
    p[21] = 'k';
    p[22] = 'L';
    p[23] = 'l';
    p[24] = 'M';
    p[25] = 'm';
    p[26] = 'N';
    p[27] = 'n';
    p[28] = 'O';
    p[29] = 'o';
    p[30] = 'P';
    p[31] = 'p';
    p[32] = 'Q';
    p[33] = 'q';
    p[34] = 'R';
    p[35] = 'r';
    p[36] = 'S';
    p[37] = 's';
    p[38] = 'T';
    p[39] = 't';
    p[40] = 'U';
    p[41] = 'u';
    p[42] = 'V';
    p[43] = 'v';
    p[44] = 'W';
    p[45] = 'w';
    p[46] = 'X';
    p[47] = 'x';
    p[48] = 'Y';
    p[49] = 'y';
    p[50] = 'Z';
    p[51] = 'z';

    int N, c;
    scanf("%d\n", &N);
    
    
    vector<int> nums(100000);
    while(N--){
        nums.clear();        
        while(c = getchar(), c!='\n'){
            nums.push_back(m[c]);
        }        
        
        sort(nums.begin(), nums.end());
        do{
            for(int i = 0 ; i < nums.size(); i++){
                putchar(p[nums[i]]);
            }
            putchar('\n');
        }while(next_permutation(nums.begin(), nums.end()));
    }
    return 0;
}
