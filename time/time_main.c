#include "time.h"


int main()
{
    char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};/*指针字符数组*/
    time_t t;
    struct tm *p;
    t=time(NULL);/*获取从1970年1月1日零时到现在的秒数，保存到变量t中*/
    p=gmtime(&t); /*变量t的值转换为实际日期时间的表示格式*/
   printf("%d年%02d月%02d日",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
    printf(" %s ", wday[p->tm_wday]);
printf("%02d:%02d:%02d\n", p->tm_hour, p->tm_min, p->tm_sec);
    return 0;
}
