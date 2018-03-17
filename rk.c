#include <stdio.h>
#include <string.h>

#define d 256

int rabincarp_search(char pattern[], char text[], int q){
	int m = strlen(pattern);
	int n= strlen(text);
	int i,j,t=0,p=0,h=1;

	for (i=0; i<m-1; i++){
		h=(h*d)%q;
	}

	for (i=0; i<m ; i++){
		p=(p*d + pattern[i])%q;
		t=(t*d + text[i])%q;
	}

	for (i=0; i<=n-m; i++){
		if (p==t){
			for (j=0; j<m; j++){
				if (text[i+j]!=pattern[j]){
					break;
				}
			}
			if(j==m){
				printf("%s%d\n", "Pattern has found in index ",i);
			}
		}
		if (i<n-m){
			t=(d*(t-text[i]*h) + text[i+m])%q;
			if (t < 0)
            t = (t + q);
		}
	}
	return 0;
}

int main(){
	char text[]="carratcappatnat";
	char pattern[]="rat";
	int q=101;
	int shift=rabincarp_search(pattern,text,q);
	return shift;
}