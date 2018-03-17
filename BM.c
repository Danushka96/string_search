#include <stdio.h>
#include <string.h>

int findchar(char pat[], char letter);
int boyer_moore(char txt[], char pat[]);
void setTable(char text[],char pattern[]);
int index_table[256];

int main(){
	char text[] = "ratcatbatnatfat";
	char pattern[] = "cat";
	int shift= boyer_moore(text,pattern);
	if (shift!=-1){
		printf("%s%d\n","Match Found at index",shift);
	}else{
		printf("%s\n", "Not found a Match");
	}
	return 0;
	// findchar(pattern,'c');
}

int boyer_moore (char txt[], char pat[]){
	setTable(txt,pat);
	int i,j,n=strlen(txt),m=strlen(pat),lastch;
	i=m-1;
	j=m-1;
	while (i<n){
		if (txt[i]==pat[j]){
			// printf("%c%s%d\n",txt[i]," i= ",i);
			if (j==0){
				//printf("%s%d\n"," ",i);
				return i;
			}else{
				j--;
				i--;
			}
		}else{
			lastch=index_table[(int)txt[i]];
			// printf("%s%c%d","Last char of ",txt[i],lastch );
			if(lastch==-1){
				i+=m;
			}else{
				i+=(j-lastch);
			}
			// printf("%s%d\n"," i= ",i);
			j=m-1;
		}
	}
	return -1;
}


int findchar(char pat[], char letter){
	int pat_size= strlen(pat)-1;
	for (int i=0; i<pat_size+1; i++){
		// printf("%c%s%c\n", pat[pat_size-i]," > ",letter);
		if (pat[pat_size-i]==letter){
			// printf("%s%c%d","letter ",letter,(pat_size-i));
			return (pat_size-i);
		}
	}
	return -1;
}

void setTable(char text[],char pattern[]){
	for (int i=0;i<strlen(text);i++) {
		int current= findchar(pattern,text[i]);
		index_table[(int)text[i]]=current;
	}
	// for (int i=0;i<256;i++){
	// 	printf("%d\n",index_table[i] );
	// }
}