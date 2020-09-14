#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage : %s <output_file>",argv[0]);
		return;
	}
	
	FILE *fd = fopen(argv[1],"w");
	if(fd==NULL)
	{
		printf("Files can't Openable");
		return;
	}

	int s1,s2,d1,d2;
	char t[]="arm00.png";

	printf("Enter the start no. : ");
	scanf("%d",&s1);
	printf("Enter the start no. : ");
	scanf("%d",&s2);
	
	printf("Enter the stop no. : ");
	scanf("%d",&d1);
	printf("Enter the stop no. : ");
	scanf("%d",&d2);

	fputs("<!doctype html>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<html>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<head><title>",fd);
	fputs("Linux by JK",fd);
	fputs("</title></head>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<body lang=EN-US>",fd); fputc(10,fd); fputc(10,fd);
	
	while((s1!=d1)||(s2!=(d2+1)))
	{
		fputs("<p align=center style='margin-bottom:0in;margin-bottom:.0001pt;text-align:center;line-height:normal'>",fd);
		fputc(10,fd);
		fputs("<span style='font-size:18.0pt'>",fd);
		fputc(10,fd);
		fputs("<img width=970 height=700 src='ARM_Class/images/",fd);
		t[3]=(char)(s1+48);
		t[4]=(char)(s2+48);
		fputs(t,fd);
		fputs("' alt='image'></span></p>",fd);
		fputc(10,fd);
		fputc(10,fd);
		s2++;
		if(s2>9)
		{
			s1++;
			s2=0;
		}
	}
	fputs("</body>",fd);
	fputc(10,fd);
	fputc(10,fd);
	fputs("</html>",fd);

	fclose(fd);
}