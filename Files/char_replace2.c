#include<stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Usage : %s <file> <find_char> <replace_char>\n",argv[0]);
		return 0;
	}
	FILE *fp = fopen(argv[1],"r+");
	if(fp == NULL)
	{
		perror("File ");
		return 0;
	}
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch == argv[2][0])
		{
			fseek(fp,-1,SEEK_CUR);
			fputc(argv[3][0],fp);
		}
	}
	fclose(fp);
	return 0;
}
