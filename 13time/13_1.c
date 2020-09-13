#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now,t1;
	t1 = time(&now);
	printf("当前日历时间:    %u（距离1970.1.1的秒数数）\n",t1);

	struct tm *localtp;
	localtp = localtime(&now);
	printf("现在的日期和时间是：  %d年%d月%d日 %d:%d:%d\n",
		localtp->tm_year+1900,localtp->tm_mon+1,localtp->tm_mday,
		localtp->tm_hour,localtp->tm_min,localtp->tm_sec);
	printf("以asctime呈现 本地时间：%s",asctime(localtp));
	printf("以ctime呈现本地时间：%s",ctime(&now));

	struct tm *gmtp;
	gmtp = gmtime(&now);
	printf("UTC   时间：%s",asctime(gmtp));
	return 0;
}
