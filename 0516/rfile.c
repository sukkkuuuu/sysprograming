#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int read_file(char* c, int line, char* str, char* copy){
	FILE* fp = fopen(c, "r");
	if(fp==0) { printf("파일열기 오류\n"); return -1;}

	char buf[1025];
	for(int i=0; i<line; i++)
		if(fgets(buf, 1024, fp) ==0){printf("err\n"); fclose(fp); return -1;}
	char* find_L = strstr(buf, str);
	if(find_L ==0) printf("not found\n");
	else strcpy(copy, find_L + strlen(str));
	fclose(fp);

	if(find_L ==0) return-1;
	return 0;
}
void main(int argc, char* argv[]){
	if(argc <4){ printf("usage: file line char\n"); exit(5);}
	char buf[1025];

	int result = read_file(argv[1], atoi(argv[2]), argv[3], (char*)&buf);
	//if (result == -1) printf("오류 \n");
	if (result != -1) printf("%s", buf);
}

void read_file_str(char* c, int line, char* str){
	FILE* fp = fopen(c,"r");
	char buf[1025];
	for(int i=0; i<line; i++)
		if(fgets(buf, 1024, fp)==0) return;
	if(strlen(buf) < strlen(str)) return;
	printf("%s", buf + strlen(str));
	fclose(fp);
}
