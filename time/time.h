#include <stdio.h>


#ifndef __TIME_T
#define __TIME_T
/* 避免重复定义 time_t */
typedef long     time_t;    /* 时间值time_t 为长整型的别名*/
#endif


#ifndef _TM_DEFINED

struct tm {
         int tm_sec;       /* 秒 - 取值区间为[0,59] */
         int tm_min;      /* 分 - 取值区间为[0,59] */
         int tm_hour;      /* 时 - 取值区间为[0,23] */
         int tm_mday;     /* 一个月中的日期 - 取值区间为[1,31] */
         int tm_mon;      /* 月份(从一月开始，0代表一月)- 取值区间为[0,11] */
         int tm_year;      /* 年份，其值等于实际年份减去1900 */
         int tm_wday;     /* 星期–取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
         int tm_yday;     /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
         int tm_isdst;     /*夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
         };
#define _TM_DEFINED
/* 避免重复定义 tm */
#endif

char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};/*指针字符数组*/

double difftime(time_t time1, time_t time0);
time_t mktime(struct tm * timeptr);
time_t time(time_t * timer);
char * asctime(const struct tm * timeptr);
char * ctime(const time_t *timer);
struct tm * gmtime(const time_t *timer);                                         
struct tm * localtime(const time_t * timer);
