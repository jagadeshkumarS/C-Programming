#include<stdio.h>
#include<conio.h>
int day(int x);
int month(int y);
int year_one(int l);
int year_two(int m);
int main()
{
int x,y,l,m,n,a,b,c,d,p;
printf ("Enter Your date of Birth:\n");
scanf ("%d %d %d %d %d",&x,&y,&l,&m,&n);
a = day(x);
b = month(y);
c = year_one(l);
d = year_two(m);
p=a+b+c+d;
if(p>=7)
{
 p=p%7;
}
int leep=(n%4);
if(leep==0)
 {
 if(y==1)
 {
  if(p==0)
   p=6;
  else
   p=p-1;
 }
 if(y==2)
 {
 if(p==0)
   p=6;
  else
   p=p-1;
 }
}
switch(p)
{
 case 1:
	  printf("Your Birth Day is SUNDAY");break;
 case 2:
	  printf("Your Birth Day is MONDAY");break;
 case 3:
	  printf("Your Birth Day is TUESDAY");break;
 case 4:
	  printf("Your Birth Day is WEDNESDAY");break;
 case 5:
	  printf("Your Birth Day is THURSDAY");break;
 case 6:
	  printf("Your Birth Day is FRIDAY");break;
 case 0:
	  printf("Your Birth Day is SATURDAY");break;
 default:printf("error");break;
}
getch ();
return 0;
}
int day(int x)
{
 int rem;
 if(x>=7)
 {
  rem=x%7;
 }
 else
  rem=x;
 return rem;
}
int month (int y)
{
 int x;
 switch(y)
 {
  case 1:x=1;break;
  case 2:x=4;break;
  case 3:x=4;break;
  case 4:x=0;break;
  case 5:x=2;break;
  case 6:x=5;break;
  case 7:x=0;break;
  case 8:x=3;break;
  case 9:x=6;break;
  case 10:x=1;break;
  case 11:x=4;break;
  case 12:x=6;break;
 }
 return x;
}
int year_one(int l)
{
 int x;
 switch(l)
 {
  case 16:x=6;break;
  case 17:x=4;break;
  case 18:x=2;break;
  case 19:x=0;break;
  case 20:x=6;break;
  case 21:x=4;break;
 }
 return x;
}
int year_two(int m)
{
 int x=m;
 int qua=x/4;
 int rem=((qua+x)%7);
 return rem;
}