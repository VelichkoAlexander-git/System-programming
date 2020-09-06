#include<signal.h>
#include<unistd.h>

int flag;

void signalHundler(int signum)
{
	flag = 0;
}

void mysleep(unsigned int *sec)
{
	flag = 1;

        signal(SIGALRM, signalHundler);
        alarm(*sec);

        while(flag) 
	{}
        return 0;

}
