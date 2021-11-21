#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

/*信号忽略SIG_IGN 需要定义新的结构体,里面自行更换设置信号行为,可以变为忽略行为,也可以变为捕捉行为*/



int main()
{
	// 信号行为结构体创建与定义
	struct sigaction nset,oset;
	nset.sa_handler = SIG_IGN;
	nset.sa_flags = 0;
	sigemptyset(&nset.sa_mask);
	// 替换使用自定义信号行为
	sigaction(SIGINT,&nset,&oset);

	while(1)
		sleep(1);
	return 0;

}
