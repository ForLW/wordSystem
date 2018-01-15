#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"mydil.h"


void
wordRecite()
{
	FILE *wordPlan;
	int wordNum=20;
	
	if((wordPlan=fopen("wordPlan.txt","r+"))==NULL)
	{
		
		printf("你还没有单词计划，请设置您的单词计划！\n");
		wordSysSetPlan();
	}
	
	
	if((wordPlan=fopen("wordPlan.txt","r+"))==NULL)
	{
		printf("读取单词计划失败，请联系管理员！\n");
		return ;
	}
	
	char wordtxt[20];
	if(fscanf(wordPlan,"%s",wordtxt)!=1)
	{
		printf("获取计划单词文件名称失败！\n");
		return ;
	}
	if(fscanf(wordPlan,"%d",&wordNum)!=1)
	{
		printf("获取每日背诵单词数失败！\n");
		return ;
	}
	FILE *wordList;
	if((wordList=fopen(wordtxt,"r"))==NULL)
	{
		printf("您还没有下载离线单词，请确认后再使用！\n");
		return ;
	}
	printf("开始背诵今天的单词吧！\n");
	printf("你今天要背诵%d个单词！\n",wordNum);
	linux_pause();
	int i=0;
	char word[30];
	char translate[50];
	char word_log[20]="./log/";   //日志的位置
	produce_day_log(word_log);
	FILE *day_log;
	//printf("%s\n",word_log);
	//linux_pause();
	if((day_log=fopen(word_log,"w"))==NULL)
	{
		printf("单词日志创建异常，请联系管理员！\n");
		return ;
	}
	
	while(i<wordNum)
	{
		
		if(fscanf(wordList,"%s %s",word,translate)!=2)
		{
			break;
		}
		fprintf(day_log,"%s %s\n",word,translate);
		i++;
	}
	fclose(wordList);
	struct Word
	{
		char word[30];
		char translate[50];
	}today_word[wordNum];
	srand((unsigned int)time(NULL));
	i=0;
	while(i<wordNum)
	{
		rand()%wordNum;
	}
	
	//fclose(day_log);
}
