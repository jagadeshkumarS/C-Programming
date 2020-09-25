int Noof_Char(FILE *fp)
{
	int n=0; char ch;
	rewind(fp);
	while((ch=fgetc(fp))!=EOF)
		n++;n++;
	return n;
}

int Noof_Line(FILE *fp)
{
	int c=0,l=0; char ch;
	rewind(fp);
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch == '\n')
		{
			l++;
			c=0;
		}
	}
	return l;
}

int Noof_Char_Bigline(FILE *fp)
{
	int c=0,bl=0; char ch;
	rewind(fp);
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch == '\n')
		{
			if(bl<c)
				bl = c;
			c=0;
		}
	}bl++;
	return bl;
}

int Noof_Word(FILE *fp)
{
	int w=0;
	char *buf = (char *)malloc(25*sizeof(char));
	rewind(fp);
	while(fscanf(fp,"%s",buf)!=EOF)
		w++;
	return w;
}

void Merge_Files(FILE *fp1,FILE *fp2,FILE *fd)
{
	int bl = Noof_Char_Bigline(fp1);
	int n = Noof_Char_Bigline(fp2);
	int i;
	bl = (bl<n)?n:bl;
	char *buf = (char *)malloc(bl*sizeof(char));
	rewind(fp1);
	rewind(fp2);
	n = Noof_Line(fp1);
	n += Noof_Line(fp2);
	rewind(fp1);
	rewind(fp2);
	for(i=0;i<=n;i++)
	{
		if(fgets(buf,bl,fp1)!=NULL)
			fputs(buf,fd);
		if(fgets(buf,bl,fp2)!=NULL)
			fputs(buf,fd);
	}
	return;
}

void Append_Files(FILE *fp1,FILE *fp2,FILE *fd)
{
	int bl = Noof_Char_Bigline(fp1);
	int *n = (int *)malloc(sizeof(int));
	*n = Noof_Char_Bigline(fp2);
	bl = (bl<*n)?*n:bl;
	free(n);
	char *buf = (char *)malloc(bl*sizeof(char));
	rewind(fp1);
	rewind(fp2);
	while(fgets(buf,bl,fp1)!=NULL)
		fputs(buf,fd);
	while(fgets(buf,bl,fp2)!=NULL)
		fputs(buf,fd);
	return;
}
