#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mydil.h"

void
wordSysSetPlan()
{
	FILE *setWordPlan;
	char wordChoise[5];
	int wordNum=20;
	char str[5]="";
	
	
		
		if((setWordPlan=fopen("wordPlan.txt","w+"))==NULL)
		{
			printf("设置单词计划失败，请联系管理员！\n");
			return ;
		}
		else
		{
			
			printf("输入‘1’四级单词，输入‘2’六级单词：");
			scanf("%s",wordChoise);
			
			while(strcmp("1",wordChoise)&&strcmp("2",wordChoise))
			{
				printf("输入有误，请重新输入：");
				scanf("%s",wordChoise);
			}
			
			if(!strcmp("1",wordChoise))
			{
				fputs("four_words.txt\n",setWordPlan);
			}
			else if(!strcmp("2",wordChoise))
			{
				fputs("six_words.txt\n",setWordPlan);
			}
			
			system("clear");
			printf("每日背诵单词数：");
			while(scanf("%d",&wordNum)!=1)
			{
				printf("输入有误，请重新输入：");
			}
			
			my_itoa(wordNum,str,10);
			fputs(str,setWordPlan);
			system("clear");
			printf("设置计划成功！\n");
			fclose(setWordPlan);
			linux_pause_clear();
		}
		
	
}
