#include <stdio.h>
#define MAX 255
#include <string.h>
int main(){
	FILE* fp;
	char string[MAX];
	int k=0;
	if((fp = fopen("a.txt","r")) != NULL) {
		while(fgets(string,MAX, fp) != NULL){
			k++;
			if(k == 2){
				printf("%s", strtok(string, "option:"));
			
			}
			else if (k>2){
				printf("%s", string);
			}
		}
	}
	return 0;

}
