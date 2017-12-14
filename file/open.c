#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{

    int fd=-1;
    char filename[]="test.txt";
    fd=open(filename,O_RDWR|O_CREAT,S_IRWXU);
    if(-1==fd){
        printf("open file %s failure! fd :%d\n",filename,fd );
        printf("Message : %s\n", strerror(errno));

    }else{
        printf("open file %s success! fd :%d\n",filename,fd );
    }

    return 0;
}

