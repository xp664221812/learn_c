#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd=-1,i;
    ssize_t size=-1;
    char buf[10];
    char filename[]="test.txt";
    fd=open(filename,O_RDONLY);
    if(-1==fd){
        printf("open file %s failure,fd :%d\n",filename,fd);
        return 0;
    }else{
        printf("open file %s success,fd :%d\n",filename,fd);
    }
    while(size){
        size=read(fd,buf,10);
        if(-1==size){
            close(fd);
            printf("read file error occurs\n");
            return -1;
        }else{
            if(size>0){
                printf("read %d bytes:",size);
                printf("\n");
                //for(i=0;i<size;i++){
                    //printf("%c",*(buf+1));
                //}
                //printf("\n");
                printf("%s\n",buf);
            }else{
                printf("read the end of file\n");
            }
        }
    }

    return 0;

}
