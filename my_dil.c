#include<stdio.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void
my_fflush(FILE *fp)
{
	#if 1
	int ch;
	if(feof(fp)||ferror(fp))
		return ;
	while((ch=fgetc(fp))!='\n'&&ch!=EOF) ;
	#endif
	#if 0
	scanf("%*[^\n]"); //scanf("%*[^\n]%*c");//无效，不明所以。
	scanf("%*c");
	#endif
	#if 0
	int ch;
	while((ch=fgetc(fp))!='\n'&&ch!=EOF) ;
	#endif
}

void 
my_itoa (int num,char s[],int n)
{
	int i,j,sign;
	int g;
	char b[20];
	if((sign=num)<0)//记录符号
	num=-num;//使n成为正数
	i=0;
	do{
	       b[i++]=num%n+'0';//取下一个数字
	}
	while ((num/=n)>0);//删除该数字
	if(sign<0)
	b[i++]='-';
	b[i]='\0';
	for(j=i-1,g=0;j>=0;j--,g++)//生成的数字是逆序的，所以要逆序输出
	       s[g]=b[j];
	s[g]='\0';
}

void
linux_pause()
{
	my_fflush(stdin);
	printf("请按enter键继续...");
	getchar();
	system("clear");
}

int 
my_linux_getpass( char *dest, int maxlen )
{
	struct termios oldflags,newflags;
	int len;
	tcgetattr(fileno(stdin),&oldflags);
	newflags=oldflags;
	newflags.c_lflag &= ~ECHO;
	newflags.c_lflag !=ECHONL;
	if(tcsetattr(fileno(stdin),TCSANOW,&newflags)!=0)
	{
		perror("tcsetattr");
		return -1;
	}
	
	fgets(dest,maxlen,stdin);
	len=strlen(dest);
	dest[len-1]='\0';
	if(tcsetattr(fileno(stdin),TCSANOW,&oldflags)!=0)
	{
		perror("tcsetattr");
		return -1;
	}
	return 0;
}

char *
produce_day_log(char *str_time)
{
	time_t a = time(NULL);
	struct tm *now;
	now=localtime(&a);
	int year=now->tm_year+1900;
	int mon=now->tm_mon+1;
	int day=now->tm_mday;
	char str_year[20];
	char str_mon[4];
	char str_day[4];
	my_itoa(year,str_year,10);
	my_itoa(mon,str_mon,10);
	my_itoa(day,str_day,10);
	char ch;
	if(strlen(str_mon)<2)
	{
		ch=str_mon[0];
		str_mon[0]='0';
		str_mon[1]=ch;
		str_mon[2]='\0';
	}
	if(strlen(str_day)<2)
	{
		ch=str_day[0];
		str_day[0]='0';
		str_day[1]=ch;
		str_day[2]='\0';
	}
	strcat(str_year,str_mon);
	strcat(str_year,str_day);
	strcat(str_time,str_year);
	return str_time;
}

char *
produce_sec_log(char *str_time)
{
	time_t a = time(NULL);
	struct tm *now;
	now=localtime(&a);
	int year=now->tm_year+1900;
	int mon=now->tm_mon+1;
	int day=now->tm_mday;
	int hour=now->tm_hour;
	int min=now->tm_min;
	int sec=now->tm_sec;
	char str_year[20];
	char str_mon[4];
	char str_day[4];
	char str_hour[4];
	char str_min[4];
	char str_sec[4];
	my_itoa(year,str_year,10);
	my_itoa(mon,str_mon,10);
	my_itoa(day,str_day,10);
	my_itoa(hour,str_hour,10);
	my_itoa(min,str_min,10);
	my_itoa(sec,str_sec,10);
	char ch;
	if(strlen(str_mon)<2)
	{
		ch=str_mon[0];
		str_mon[0]='0';
		str_mon[1]=ch;
		str_mon[2]='\0';
	}
	if(strlen(str_day)<2)
	{
		ch=str_day[0];
		str_day[0]='0';
		str_day[1]=ch;
		str_day[2]='\0';
	}
	if(strlen(str_hour)<2)
	{
		ch=str_hour[0];
		str_hour[0]='0';
		str_hour[1]=ch;
		str_hour[2]='\0';
	}
	if(strlen(str_sec)<2)
	{
		ch=str_sec[0];
		str_sec[0]='0';
		str_sec[1]=ch;
		str_sec[2]='\0';
	}
	strcat(str_year,str_mon);
	strcat(str_year,str_day);
	strcat(str_year,str_hour);
	strcat(str_year,str_min);
	strcat(str_year,str_sec);
	strcat(str_time,str_year);
	return str_time;
}

char *
del_blank_ch(char *str)
{
	if(str==NULL)
		return NULL;
	int i=0,j=0;
	char ch;
	while((ch=str[i])!='\0')
	{
		if(ch=='\n'||ch=='\t'||ch==' ')
		{
			j=i;
			while(str[j]!='\0')
			{
				str[j]=str[++j];
			}
			str[++j]='\0';
		}
		else
		{
			i++;
		}
	}
	return str;
}



