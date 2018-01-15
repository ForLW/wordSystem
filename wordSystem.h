#ifndef _WORDSYSTEM_
#define _WORDSYSTEM_

int
wordSysPat();
//登录模式

void
wordSysShow();
//显示界面

int
wordSysLogin();
//离线登录模式


void
wordRecite();
//进入背单词选项

void
wordTest();
//进入测试选项

void
watchRecited();
//查看已经背过的单词

void
timeDis();
//时间处理

void
wordSysExit();

//离线模式

void
wordInPutFile();
//将单词导入到文件

void
wordOutPutFile();
//将单词导出文件

void
wordNumFile();
//本次应该背诵的单词计算，并从文件获取


//在线模式

void
wordSqlLogin();
//在线登录模式

void
wordInPutSQL();
//将单词导入数据库

void
wordOutPutSQL();
//将单词导出数据库

void
wordNumSQL();
//本次应该背诵的单词计算，并从数据库获取

void
wordSysSetPlan();
//修改单词计划文件




#endif //_WORDSYSTEM_
