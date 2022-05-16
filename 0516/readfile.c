#include <stdio.h>
#include <string.h>
#define MAXLINE 80
/* 텍스트 파일에 줄 번호 붙여 프린트한다. */
int main()
{
	FILE *fp;
	int num;
	int line;
	char buf[MAXLINE];
	char buffer[MAXLINE];
	char string[MAXLINE];
	printf("파일 이름 : ");
	scanf("%s", buffer);
	printf("라인 수 : ");
	scanf("%d", &num);
	printf("문자열 : ");
	scanf("%s", string);
	
	fp = fopen(buffer, "r");
	if(string == "option"){
		while (fgets(buf, MAXLINE, fp) != NULL) { // 한 줄 읽기
			line++;	
			if (line == num){
				printf("%s\n", strtok(buf, string)); // 읽은 파일의 문자
			}
			if(line > num){
				printf("%s", buf);
			}
		}
	}
	else if (string !="option"){
		printf("string err");
	}
	//라인오류 
	if(line < num){
		printf("line err");
	}
	fclose(fp);
	return 0;
}
