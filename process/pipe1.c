#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{

    int result=-1;
    int fd[2],nbytes;    /*文件描述符，字符个数*/
    pid_t pid;
    char string[]="你好，管道";
    char readbuf[80];

    int *write_fd=&fd[1];
    int *read_fd=&fd[0];

    result=pipe(fd);
    if(-1==result){
        printf("常见管道失败!!\n");
        return -1;
    }

    pid=fork();
    if(-1==pid){
        printf("fork 进程失败\n");
        return -1;
    }

    if(0==pid){
        close(*read_fd);
        write(*write_fd,string,strlen(string));
        return 0;
    }else{
    close(*write_fd);
    nbytes=read(*read_fd,readbuf,sizeof(readbuf));
    printf("接收到%d个数据,内容为%s\n",nbytes,readbuf);

    return 0;
    }
    return 0;

}
