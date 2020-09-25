#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file_driver.c"
int main(int argc,char *argv[])
{
	if(argc >= 2)
	{
		if(!strcmp(argv[1],">"))
		{
			FILE *fp = fopen(argv[2],"w");
			char ch;
			while((ch=getchar())!=EOF)
				fputc(ch,fp);
			fclose(fp); 
		}
		else if(!strcmp(argv[1],">>"))
		{
			FILE *fp = fopen(argv[2],"a");
			char ch;
			while((ch=getchar())!=EOF)
				fputc(ch,fp);
			fclose(fp); 
		}
		else
		{
			FILE *fp = fopen(argv[1],"r");
			if(fp == NULL)
			{
				perror("file ");
				return 0;
			}
			int bl = Noof_Char_Bigline(fp);
			char buf[bl];
			while(fgets(buf,bl,fp)!=NULL)
				printf("%s",buf);
		}
	}
	else
	{
		char ch;
		while(1)
		{
			scanf("%c ",&ch);
			printf("%c",ch);
		}
	}
	return 0;
}
