#include"wordSystem.h"
#include<stdio.h>
#include<string.h>

int
wordSysPat()
{
	printf("请选择登录的模式‘1’离线模式，‘2’在线模式：");
	char answer[10];
	while(1)
	{
		fscanf(stdin,"%s",answer);
		if(!strcmp(answer,"1"))
		{
			system("clear");
			wordSysLogin();
			return 1;
		}
		else if(!strcmp(answer,"2"))
		{
			system("clear");
			wordSqlLogin();
			return 0;
		}
		else
			printf("输入有误，请重新输入：");
	}
	
}
