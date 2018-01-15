#include<stdio.h>
#include"mydil.h"

void
watchRecited()
{
	FILE *fp;
	if((fp=fopen("wordRecited.txt","r"))==NULL)
	{
		printf("您还没有背过的单词\n");
		return ;
	}
	int n=0;
	char word[100];
	while(1)
	{
		if(fgets(word,100,fp)!=NULL)
		printf("%s",word);
		else break;
		n++;
		if(n==10)
		{
			linux_pause_clear();
			n=0;
		}
	}
	fclose(fp);
	linux_pause_clear();
}
