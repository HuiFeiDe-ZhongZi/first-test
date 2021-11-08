#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<regex.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

//<a class='ptv' href='/cj/shipin/cns-d/2021/11-08/news906472.shtml'>网红博主齐聚</a>

//关键内容1: 新闻连接
//关键内容2: 新闻标题
//表达式内容: "<a[^>]\\+\\?href=\"\\([^\"]\\+\\?\\.shtml\\)\"[^>]\\+\\?>\\+\\?>\\([^<]\\+\\?\\)</a>"

int main()
{
	int fd = open("new.html",O_RDWR);

	int fsize = lseek(fd,0,SEEK_END);

	char *pstring = NULL;
	char *jstring = NULL;

	pstring = mmap(NULL,fsize,PROT_READ,MAP_PRIVATE,fd,0);
	jstring = pstring;

	regex_t areg;

	regcomp(&areg,"<a[^>]\\+\\?href=\"\\([^\"]\\+\\?\\.shtml\\)\"[^>]\\+\\?>\\+\\?>\\([^<]\\+\\?\\)</a>",0);

	char link_buf[4096];
	char title_buf[1024];
	bzero(link_buf,sizeof(link_buf));
	bzero(title_buf,sizeof(title_buf));
	regmatch_t amatch[3];

	//循环匹配
	
	while((regexec(&areg,pstring,3,amatch,0)) == 0)
	{
		snprintf(link_buf,amatch[1].rm_eo - amatch[1].rm_so + 1,"%s",pstring + amatch[1].rm_so);
		snprintf(title_buf,amatch[2].rm_eo - amatch[2].rm_so + 1,"%s",pstring + amatch[2].rm_so);
		printf("title [%s]  link [%s]\n",title_buf,link_buf);
		bzero(link_buf,sizeof(link_buf));
		bzero(title_buf,sizeof(title_buf));
		
		//数据偏移处理
		pstring += amatch[0].rm_eo;

	}
	
	regfree(&areg);
	close(fd);
	munmap(jstring,fsize);
	return 0;
}
