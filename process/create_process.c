#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int createWithFork(){
    pid_t pid;
    /* fork 函数执行一次，返回两次，如果返回0,打印子进程信息，大于0打印父进程信息 */
    printf("current pid:   %d\n",getpid());
    pid=fork();
    if(-1==pid){
        printf("创建进程失败!\n");
        return -1;
    }else if(0==pid){
        /*子进程执行此段代码*/
        printf("子进程,fork 返回值:%d,ID:%d,父进程 ID:%d\n",pid,getpid(),getppid());
    }else {
        printf("父进程,fork 返回值:%d,ID:%d,父进程 ID:%d\n",pid,getpid(),getppid());
    }

    return 0;

}


void createWithSystem(){
    int ret;

    printf("系统分配的进程号是:%d\n",getpid());
    ret = system("ping www.baidu.com -c 2");
    printf("返回值为:%d\n",ret);
    return;
}



int main()
{

    /*创建进程的三种方式*/
    //1.fork
    createWithFork();

    //2.system
    //createWithSystem();


    return 0;

}
