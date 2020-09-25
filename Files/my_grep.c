#include<stdio.h>
#include<string.h>
#include"file_driver.c"
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s <file> <word>\n",argv[0]);
		return 0;
	}

	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		printf("File doesn't Exist\n");
		return 0;
	}

	int bl=Noof_Char_Bigline(fp);
	char buf[bl];
	rewind(fp);
	while(fgets(buf,bl,fp)!=NULL)
	{
		if(strstr(buf,argv[2])!=NULL)
			printf("%s",buf);
	}
	fclose(fp);
}
