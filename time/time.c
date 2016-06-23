#include "time.h"


bool IsLeapYear( int year ) //判断年份是平年还是闰年
{
return ( year % 400==0 || ( year %4==0 && year %100 !=0 ) );
}

int GetDaysOfMonth(int year,int month)//获得一年中各个月的天数
{
	int i=0;
	switch(month-1)
	{
		case 11:
			i+=30;
		case 10:
			i+=31;
		case 9:
			i+=30;
		case 8:
			i+=31;
		case 7:
			i+=31;
		case 6:
			i+=30;
		case 5:
			i+=31;
		case 4:
			i+=30;
		case 3:
			i+=31;
		case 2:
			i = ( IsLeapYear( year) ) ?(i+= 29) :( i+=28);
		case 1:
			i+=31;
	}
	return i;

}


void FunctionThree( int birthYear, int birthMonth, int birthDay, int year, int month, int day )
{
int iResult=0,j;
for ( j=birthYear; j<=year; j++ )
{
iResult += ( ( IsLeapYear(j) ) ? 366 : 365);
}
iResult -= GetDaysOfMonth( birthYear, j );
for ( j=1; j < birthDay; j++ )
{
iResult--;
}
iResult += GetDaysOfMonth( year, j );
for ( j=1; j < day; j++ )
{
iResult++;
}
printf("\n%d年%d月%d日-%d年%d月%d日 = %d天\n", year, month, day, birthYear, birthMonth, birthDay,iResult);

}



time_t *ni_time(viod){
	
	return time(NULL);	
}

int mon(struct tm *time){
	
	switch(*time->tm_mon)
	{
		case 12:
			if(*time->mday > 31) {
				*time->tm_mday = 1;
				*time->tm_mom = 1;
				*time->tm_year ++;
			}
			break;
		case 11:
			if(*time->mday > 30) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 10:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 9:
			if(*time->mday > 30) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 8:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 7:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 6:
			if(*time->mday > 30) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 5:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 4:
			if(*time->mday > 30) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 3:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
		case 2:
			(IsLeapYear(*time->tm_year))?(if(*time->mday > 29) {*time->tm_mday = 1; *time->tm_mom ++;}) : (if(*time->mday > 28) {*time->tm_mday = 1; *time->tm_mom ++;})
			break;
		case 1:
			if(*time->mday > 31) {*time->tm_mday = 1; *time->tm_mom ++;}
			break;
	}
}

int mon_time(struct tm *time){
	int MonBuf[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(IsLeapYear(*time->tm_year))	MomBUf[1] = 29;
	
	return MonBuf[*time->tm_mon-1];
}

#dienf year_time(struct tm *time)	{(IsLeapYear(*time->tm_year))?(31622400/*366*24*60*60*/) : (31536000/*365*24*60*60*/}
//#dienf mon_time(struct tm *time)	{}
#dienf DAY_TIME		86400
#dienf HOUR_TIME	3600
#dienf MIN_TIME		60
#dienf SEC_TIME		1


void ni_data(time_t ni_t,struct tm *time){
	time_t temp;
	
	while(ni_t > year_time(time)){
		ni_t -= year_time(time);
		*time->tm_year ++;
	}
	
	while(ni_t > mon_time(time)){
		ni_t -= mon_time(time);
		*time->tm_mon ++;
	}
	
	while(ni_t > DAY_TIME){
		ni_t -= DAY_TIME;
		*time->tm_mday ++;
	}
	
	while(ni_t > HOUR_TIME){
		ni_t -= HOUR_TIME;
		*time->tm_hour ++;
	}
	
	while(ni_t > MINUTE_TIME){
		ni_t -= MINUTE_TIME;
		*time->tm_min ++;
	}
	
	while(ni_t > SEC_TIME){
		ni_t -= SEC_TIME;
		*time->tm_sec ++;
	}
	
	return 0;
}

struct tm *ni_time(time_t ni_p){
	struct tm *time;
	time_t day;
	
	time->tm_sec = ni_p % 60;
	time->tm_min = ni_p / 60 % 60;
	time->tm_hour = (ni_p/(60 * 60)) % 24;
	
	day = ni_p / (60 * 60 * 24);
	time = ni_data(day,time);
	for(i = 0;i < day;i ++){
		*time->tm_mday ++;
		mon(time);
	}

	return time;
}
