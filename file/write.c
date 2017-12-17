#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd=-1;
    ssize_t size=-1;
    char buf[]="this is my house";
    char filename[]="test.txt";
    fd=open(filename,O_RDWR);
    if(-1==fd){
        printf("open file %s failure,fd :%d\n",filename,fd);
        return 0;
    }else{
        printf("open file %s success,fd :%d\n",filename,fd);
    }

    size=write(fd,buf,strlen(buf));
    printf("write %d bytes to file %s\n",size,filename);
    close(fd);

    return 0;

}
