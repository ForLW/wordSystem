#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"wordSystem.h"
#include"mydil.h"

int
wordSysLogin()
{
	int i=0;
	while(i<3)
	{
		i++;
		printf("请输入用户名：");
		char userName[10];
		scanf("%s",userName);
		printf("请输入密码：");
		getchar();
		char userPwd[20];
		my_linux_getpass(userPwd,30);
		printf("\n");
		if((!strcmp(userName,"admin"))&&(!strcmp(userPwd,"admin")))
		{
			
			return 1;
		}
		else 
		{
			if(i==3)
			{
				printf("超过尝试限制，请稍后重新输入！\n");
				exit(1);
			}
			printf("用户或密码错误，你还有%d次机会！\n",3-i);
			
		}
	}
	return 0;
}



