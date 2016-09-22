#include <cstdio>

using namespace std;

int main(){
	
	int N, num, capt,i;
	scanf("%d", &N);
	i=1;
	while(N > 0){
		scanf("%d", &num);
		
		int a = 0;
		while(a < num){
			scanf("%d", &capt);
			if(a == num/2) printf("Case %d: %d\n", i, capt);
			a++;
		}
		
		N--;
		i++;		
	}
	return 0;
}