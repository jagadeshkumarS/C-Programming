#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage : %s <input_file> <output_file>",argv[0]);
		return;
	}
	
	FILE *fs = fopen(argv[1],"r");
	FILE *fd = fopen(argv[2],"w");
	if(fs==NULL||fd==NULL)
	{
		printf("Files can't Openable");
		return;
	}

	char t[100],ch;
	int i,c=0,b=0;

	printf("Enter the Title : ");
	scanf(" %[^\n]",t);

	fputs("<!doctype html>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<html>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<head><meta content='width=device-width, initial-scale=1, minimum-scale=1, maximum-scale=1' name='viewport'><title>",fd);
	fputs(t,fd);
	fputs("</title></head>",fd); fputc(10,fd); fputc(10,fd);
	fputs("<body lang=EN-US>",fd); fputc(10,fd); fputc(10,fd);
	
	while((ch = fgetc(fs))!=EOF)
    {
		c++;
        if(ch=='\n')
			if(b<c)
            {
				b=c;
                c=0;
            }
    }b=b+3;
	char *buf = (char *)malloc(b*sizeof(char));
	rewind(fs);
	
	while(!feof(fs))
	{
		fgets(buf,b,fs);
		if(!strncmp(buf,"!h1",3))
		{
			fputs("<p align=center style='margin-top:2.4pt; margin-right:2.4pt; margin-bottom:2.4pt; margin-left:0in; text-align:center; line-height:22.5pt'>",fd);
			fputc(10,fd);
			fputs("<span style='color:#8B0000; letter-spacing:-.75pt'><b>",fd);
			fgets(buf,b,fs);
			fputs(buf,fd);
			fseek(fd,-2,SEEK_CUR);
			fputs("</b></span></p>",fd);
			fputc(10,fd);
			fputc(10,fd);
			goto end;
		}
		else if(!strncmp(buf,"!h2",3))
		{
			fputs("<p style='margin-top:2.4pt; margin-right:2.4pt; margin-bottom:2.4pt; margin-left:0in; line-height:18.0pt'>",fd);
			fputc(10,fd);
			fputs("<span style='color:#A40000; letter-spacing:-.75pt; font-weight:normal'>",fd);
			fgets(buf,b,fs);
			fputs(buf,fd);
			fseek(fd,-2,SEEK_CUR);
			fputs("</span></p>",fd);
			fputc(10,fd);
			fputc(10,fd);
			goto end;
		}
		else if(!strncmp(buf,"!pgm",4))
		{
			fputs("<div style='border:solid #D6D6D6 1.0pt;padding:4.0pt 4.0pt 4.0pt 4.0pt;background:#EEEEEE'>",fd);
			fputc(10,fd);
			fputs("<pre style='margin-bottom:7.5pt;line-height:12.0pt;background:#EEEEEE;border:none;padding:0in'>",fd);
			fputc(10,fd);
			while(!feof(fs))
			{
				fgets(buf,b,fs);
				if(!strncmp(buf,"#include",8))
				{
					fputs("<span style='color:#880000'>",fd);
					for(i=0;buf[i];i++)
					{
						if(buf[i] == '<')
							fputs("&lt;",fd);
						else
							fputc(buf[i],fd);
					}
					fputs("</span>",fd);
					fputc(10,fd);
					continue;
				}
				if(strncmp(buf,"!pgm",4))
				{
					fputs("<span style='color:#000088'>",fd);
					for(i=0;buf[i];i++)
					{
						if(buf[i] == '<')
							fputs("&lt;",fd);
						else
							fputc(buf[i],fd);
					}
					fputs("</span>",fd);
					continue;
				}
				else
				{
					fputs("</pre> </div>",fd);
					fputc(10,fd);
					fputc(10,fd);
					goto end;
				}
			}
		}
		else if(!strncmp(buf,"!block",4))
		{
			fputs("<pre><span style='color:black'>",fd);
			fputc(10,fd);
			while(!feof(fs))
			{
				fgets(buf,b,fs);
				if(!strncmp(buf,"#include",8))
				{
					for(i=0;buf[i];i++)
					{
						if(buf[i] == '<')
							fputs("&lt;",fd);
						else
							fputc(buf[i],fd);
					}
					fputs("",fd);
					continue;
				}
				if(strncmp(buf,"!block",4))
				{
					fputs(buf,fd);
					continue;
				}
				else
				{
					fputs("</span></pre>",fd);
					fputc(10,fd);
					fputc(10,fd);
					goto end;
				}
			}
		}
		else if(!strncmp(buf,"!long",4))
		{
			fputs("<div style='border:solid #D6D6D6 1.0pt;padding:4.0pt 4.0pt 4.0pt 4.0pt;background:#EEEEEE'>",fd);
			fputc(10,fd);
			fputs("<pre style='margin-bottom:7.5pt;line-height:20.0pt;background:#EEEEEE;border:none;padding:0in'>",fd);
			fputc(10,fd);
			fputs("<span style='color:#000088'>",fd);
			fputc(10,fd);
			while(!feof(fs))
			{
				fgets(buf,b,fs);
				if(!strncmp(buf,"#include",8))
				{
					fputs("<span style='color:#880000'>",fd);
					for(i=0;buf[i];i++)
					{
						if(buf[i] == '<')
							fputs("&lt;",fd);
						else
							fputc(buf[i],fd);
					}
					fputs("</span>",fd);
					fputc(10,fd);
					continue;
				}
				if(strncmp(buf,"!long",4))
				{
					fputs(buf,fd);
					fputs("",fd);
					continue;
				}
				else
				{
					fputs("</span>",fd);
					fputc(10,fd);
					fputs("</pre> </div>",fd);
					fputc(10,fd);
					fputc(10,fd);
					goto end;
				}
			}
		}
		else if(!strncmp(buf,"!p",2))
		{
			fputs("<p style='margin-top:0in; margin-right:2.4pt; margin-bottom:12.0pt; margin-left:2.4pt; text-align:justify; line-height:18.0pt'>",fd);
			fputc(10,fd);
			fputs("<span style='color:black'>",fd);
			while(!feof(fs))
			{
				fgets(buf,b,fs);
				if(!strncmp(buf,"#include",8))
				{
					fputs("#include&lt;",fd);
					fputs(buf+9,fd);
					fputs("",fd);
					continue;
				}
				if(strncmp(buf,"!p",2))
				{
					fputs(buf,fd);
					continue;
				}
				else
				{
					fseek(fd,-2,SEEK_CUR);
					fputs("</span></p>",fd);
					fputc(10,fd);
					fputc(10,fd);
					goto end;
				}
			}
		}
		else if(!strncmp(buf,"!img",4))
		{
			fputs("<p align=center style='margin-bottom:0in;margin-bottom:.0001pt;text-align:center;line-height:normal'>",fd);
			fputc(10,fd);
			fputs("<span style='font-size:12.0pt'>",fd);
			fputc(10,fd);
			fputs("<img width=345 height=300 src='images/",fd);
			fgets(buf,b,fs);
			fputs(buf,fd);
			fputs("' alt='image'></span></p>",fd);
			fputc(10,fd);
			fputc(10,fd);
			goto end;
		}
	end: continue;
	}
	fputs("</body>",fd);
	fputc(10,fd);
	fputc(10,fd);
	fputs("</html>",fd);

	fclose(fs);
	fclose(fd);
	free(buf);
}