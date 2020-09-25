#include<stdio.h>
#include<stdlib.h>
#include"file_driver.c"
int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Usage : %s <file> <find_char> <replace_char>\n",argv[0]);
		return 0;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("File ");
		return 0;
	}
	int c = Noof_Char(fp),i=0;
	char *buf = (char *)malloc(c*sizeof(char));
	char ch;
	rewind(fp);
	while((ch=fgetc(fp))!=EOF)
		buf[i++] = ch;buf[i] = '\0';

	fclose(fp);

	fp = fopen(argv[1],"w");
	for(i=0;i<c;i++)
		if(buf[i] == argv[2][0])
			fputc(argv[3][0],fp);
		else
			fputc(buf[i],fp);

	fclose(fp);
	return 0;
}
