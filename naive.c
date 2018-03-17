#include <stdio.h>
#include <memory.h>

void bruteForce(char text[],char pattern[]);

int main() {
    char text[]="abbcabab";
    char pattern[]="ab";
    bruteForce(text,pattern);
}

void bruteForce(char text[],char pattern[]){

    int maxShift= strlen(text)- strlen(pattern);
    for (int i=0;i<maxShift;i++){
        int count_of_match=0;
        for (int j=0;j< strlen(pattern);j++) {
            if (text[i + j] == pattern[j]) {
                count_of_match++;
            }
        }
        if (count_of_match== strlen(pattern)){
            printf("%s%d\n","pattern matched at index ",i);
        }
    }
}
