#include<stdio.h>
#include<string.h>
#include"wordSystem.h"
void
wordSysShow()
{
	char answer[10];
	printf("\t\t****************************\n");
	printf("\t\t**欢迎使用科学背单词系统！**\n");
	printf("\t\t****************************\n");
	linux_pause_clear();
	int pat=1;
	pat=wordSysPat();
	system("clear");
	answer[0]='\0';
	if(pat==1)
	while(1)
	{
		printf("\t\t输入‘1’开始背单词！\n");
		printf("\t\t输入‘2’单词测试！\n");
		printf("\t\t输入‘3’查看已背单词！\n");
		printf("\t\t输入‘4’设置单词计划！\n");
		printf("\t\t输入‘0’退出系统！\n");
		scanf("%s",answer);
		if(!strcmp(answer,"1"))
		{
			system("clear");
			wordRecite();
		}
		else if(!strcmp(answer,"2"))
		{
			system("clear");
			wordTest();
		}
		else if(!strcmp(answer,"3"))
		{
			system("clear");
			watchRecited();
		}
		else if(!strcmp(answer,"4"))
		{
			system("clear");
			wordSysSetPlan();
		}
		else if(!strcmp(answer,"0"))
			wordSysExit();
		
		else 
		{
			system("clear");
			printf("输入有误，请重新输入!\n");
		}
	}
	else
	;
}
