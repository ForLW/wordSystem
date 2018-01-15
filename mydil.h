#ifndef _MYDIL_
#define _MYDIL_

void
my_fflush(FILE *fp);   //清空流中的内容

void 
my_itoa(int num,char s[],int n); //将整数转换成字符串

int
my_atoi(char *str);  //将字符串转换成整数 (标准库有)

void
linux_pause();   //linux系统暂停

int 
my_linux_getpass( char *dest, int maxlen );  //linux获取密码

char *
produce_day_log(char *str_time);  //以时间(精确到天)作为日志名称 **字符串必需要初始化**

char *
produce_sec_log(char *str_time);   //以时间(精确到秒)作为日志名称 **字符串必需要初始化**

char *
del_blank_ch(char *str);

#endif //_MYDIL_
