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

	if((wordPlan=fopen("./wordtxt/wordPlan.txt","r+"))==NULL)
	{

		printf("你还没有单词计划，请设置您的单词计划！\n");
		wordSysSetPlan();
	}


	if((wordPlan=fopen("./wordtxt/wordPlan.txt","r+"))==NULL)
	{
		printf("读取单词计划失败，请联系管理员！\n");
		return ;
	}

	char wordtxt[50]="./wordtxt/";
	char tmp[20];
	if(fscanf(wordPlan,"%s",tmp)!=1)
	{
		printf("获取计划单词文件名称失败！\n");
		return ;
	}
	if(fscanf(wordPlan,"%d",&wordNum)!=1)
	{
		printf("获取每日背诵单词数失败！\n");
		return ;
	}
	strcat(wordtxt,tmp);

	char word[30];
	char translate[50];
	char yourself_wordtxt[50]="./wordtxt/yourself_";
	strcat(yourself_wordtxt,tmp);
	FILE *wordList,*yourself_wordList;
	if((yourself_wordList=fopen(yourself_wordtxt,"r"))==NULL)
	{
		if((wordList=fopen(wordtxt,"r"))==NULL)
		{
			printf("您还没有下载离线单词，请确认后再使用！\n");
			return ;
		}
		if((yourself_wordList=fopen(yourself_wordtxt,"w+"))==NULL)
		{
			printf("创建你自己的单词列表失败，请联系管理员！\n");
			return ;
		}

		while(1)
		{
			if(fscanf(wordList,"%s %s",word,translate)!=2)
			{
				break;
			}
			fprintf(yourself_wordList,"%s %s\n",word,translate);
		}
		fclose(wordList);

	}
	fclose(yourself_wordList);
	if((yourself_wordList=fopen(yourself_wordtxt,"r"))==NULL)
	{
		printf("读取您的单词列表失败，请联系管理员！\n");
		return ;
	}
	printf("开始背诵今天的单词吧！\n");
	printf("你今天要背诵%d个单词！\n",wordNum);
	linux_pause_clear();
	int i=0;
	char word_log[20]="./log/";   //日志的位置
	produce_day_log(word_log);
	FILE *day_log;
	//printf("%s\n",word_log);
	//linux_pause();
    int reRecite = 0;
    if((day_log=fopen(word_log,"r")) !=NULL)
	{
        reRecite = 1 ;
	}
	else 
	{
		if((day_log=fopen(word_log,"w"))==NULL)
		{
			printf("单词日志创建异常，请联系管理员！\n");
			return ;
		}
		i=0;
		while(i<wordNum)
		{

			if(fscanf(yourself_wordList,"%s %s",word,translate)!=2)
			{
				break;
			}
			fprintf(day_log,"%s %s\n",word,translate);
			i++;
		}
	}
	FILE *swapfile;
	
	if((swapfile=fopen("swapfile","w+"))==NULL)
	{
		printf("创建交换文件失败，请联系管理员！\n");
		return ;
	}
	while( 1 )
	{
		if(fscanf(yourself_wordList,"%s %s",word,translate)!=2)
		{
			break;
		}
		fprintf(swapfile,"%s %s\n",word,translate);
	}

	fclose(swapfile);

	fclose(yourself_wordList);
	fclose(day_log);
	
	if((swapfile=fopen("swapfile","r"))==NULL)
	{
		printf("读取交换文件失败，请联系管理员！\n");
		return ;    
	}
	if((yourself_wordList=fopen(yourself_wordtxt,"w"))==NULL)
	{
		printf("修改您自己的单词列表失败，请联系管理员！\n");
		return ;
	}

	while( 1 )
	{
		if(fscanf(swapfile,"%s %s",word,translate)!=2)
		{
			break;
		}
		fprintf(yourself_wordList,"%s %s\n",word,translate);
	}
	fclose(swapfile);
	fclose(yourself_wordList);
	remove("swapfile");
	if((day_log=fopen(word_log,"r"))==NULL)
	{
		printf("单词日志读取异常，请联系管理员！\n");
		return ;
	}
	struct Word
	{
		char word[30];
		char translate[50];
	}today_word[wordNum];
	i=0;
	while(i<wordNum)
	{
		today_word[i].word[0]='\0';
		today_word[i].translate[0]='\0';
		i++;
	}
	srand((unsigned int)time(NULL));
	i=0;
	while(i<wordNum)
	{
		int num;
		num=rand()%wordNum;
		while(1)
		{
			if(today_word[num].word[0]=='\0')
			{
				if(fscanf(day_log,"%s %s",today_word[num].word,
				today_word[num].translate)!=2)
				goto end;
				break;
			}
			num=(num+1)%wordNum;
		}
		i++;
	}
end:
	i=0;
	while(i<wordNum)
	{
		if(today_word[i].word[0]!='\0')
		{
			printf("%s\n",today_word[i].word);
			linux_pause();
			printf("%s\n",today_word[i].translate);
			linux_pause_clear();
		}
		i++;
	}
	printf("今日背诵单词浏览完毕！\n");
	fclose(day_log);
	linux_pause_clear();
	printf("选出下面这些题中你认为正确的选项：\n");
	linux_pause_clear();


	//看单词从四个选项中选择中选择正确的翻译
	i=0;
	while(i<wordNum)
	{
		int choise[4];
		int num = -1;
		srand((unsigned int)time(NULL));
		if( today_word[i].word == '\0' )
		{
			i++;
			continue;
		}
		printf("%s\n\n",today_word[i].word);
		int j=0;
		while( j < 4 )
		{
			choise[j] = -1;
			j++;
		}
		num = rand()%4;
		choise[num]=i;   //随机正确答案的选项
		j=0;
		int k=0;
		int n;
		while( j < 4 )
		{
			k=0;
			if( choise[j] == -1 )
			{
				while( n=rand()%wordNum ,today_word[n].translate == '\0' ) ;
				while( k < 4 )
				{
					if( choise[k] == n )
					{
						while( n=rand()%wordNum ,today_word[n].translate == '\0' ) ;
						//n = rand()%wordNum;
						k=0;
					}
					else
						k++;
				}
				choise[j] = n;
			}
			j++;
		}

		printf("A : %s\n",today_word[choise[0]].translate);
		printf("B : %s\n",today_word[choise[1]].translate);
		printf("C : %s\n",today_word[choise[2]].translate);
		printf("D : %s\n",today_word[choise[3]].translate);

		char ch[10];
		while(1)
		{

			printf("请输入答案：");
			fscanf(stdin,"%s",ch);
			my_fflush(stdin);
			if( strcmp(ch,"a")==0 || strcmp(ch,"A")==0 )
			{
				n = 0;
			}
			else if( strcmp(ch,"b")==0 || strcmp(ch,"B")==0 )
			{
				n = 1;
			}
			else if( strcmp(ch,"c")==0 || strcmp(ch,"C")==0 )
			{
				n = 2;
			}
			else if( strcmp(ch,"d")==0 || strcmp(ch,"D")==0 )
			{
				n = 3;
			}
			else
			{
				printf("请输入A~D的选项\n");
				continue;
			}

			if( n == num )
			{
				printf("正确!\n");
				linux_pause_clear();
				break;
			}

			printf("错误!\n");

		}


		i++;
	}


	//看翻译从四个选项中选择正确的英文
	i=0;
	while( i < wordNum )
	{

		int choise[4];
		int num = -1;
		srand((unsigned int)time(NULL));
		if( today_word[i].translate == '\0')
		{
			i++;
			continue;
		}
		printf("%s\n\n",today_word[i].translate);
		int j=0;
		while( j < 4 )
		{
			choise[j] = -1;
			j++;
		}
		num = rand()%4;
		choise[num]=i;   //随机正确答案的选项
		j=0;
		int k=0;
		int n;
		while( j < 4 )
		{
			k=0;
			if( choise[j] == -1 )
			{
				while( n=rand()%wordNum ,today_word[n].word == '\0' ) ;
				while( k < 4 )
				{
					if( choise[k] == n )
					{
						while( n=rand()%wordNum ,today_word[n].translate == '\0' ) ;
						//n = rand()%wordNum;
						k=0;
					}
					else
						k++;
				}
				choise[j] = n;
			}
			j++;
		}

		printf("A : %s\n",today_word[choise[0]].word);
		printf("B : %s\n",today_word[choise[1]].word);
		printf("C : %s\n",today_word[choise[2]].word);
		printf("D : %s\n",today_word[choise[3]].word);

		char ch[10];
		while(1)
		{

			printf("请输入答案：");
			fscanf(stdin,"%s",ch);
			my_fflush(stdin);
			if( strcmp(ch,"a")==0 || strcmp(ch,"A")==0 )
			{
				n = 0;
			}
			else if( strcmp(ch,"b")==0 || strcmp(ch,"B")==0 )
			{
				n = 1;
			}
			else if( strcmp(ch,"c")==0 || strcmp(ch,"C")==0 )
			{
				n = 2;
			}
			else if( strcmp(ch,"d")==0 || strcmp(ch,"D")==0 )
			{
				n = 3;
			}
			else
			{
				printf("请输入A~D的选项\n");
				continue;
			}

			if( n == num )
			{
				printf("正确!\n");
				linux_pause_clear();
				break;
			}

			printf("错误!\n");

		}


		j=0;
		while( j < 4 )
		{
			choise[j] = -1;
			j++;
		}

		i++;
	}

	printf("下列各题给出翻译，输入正确的英文。\n");
	linux_pause_clear();

//给翻译输入正确的英文
	i=0;
	while( i < wordNum )
	{
		char choise[50];
		printf("%s\n\n",today_word[i].translate);
		printf("请输入正确答案：");
		scanf("%s",choise);
		while( strcmp(choise,today_word[i].word) != 0 )
		{
			printf("输入错误请重新输入：");
			scanf("%s",choise);
		}

		printf("正确\n");
		linux_pause_clear();

		i++;
	}

    printf("很棒呀今天的单词已经背完了，记得明天再来背单词。\n");
    linux_pause_clear();


    if( reRecite == 0 )
    {

        FILE * wordRecited;
        if( (wordRecited=fopen("./wordtxt/wordRecited.txt","a+")) == NULL )
        {
            printf("wordRecite.txt写入失败，请联系管理员！\n");
        }
        i=0;
        while( i < wordNum )
        {
            if( today_word[i].word[0] != '\0' && today_word[i].translate[0] != '\0' )
            {
                fprintf(wordRecited,"%s %s\n",today_word[i].word,today_word[i].translate);
            }
            i++;
        }

		fclose(wordRecited);

    }


}
