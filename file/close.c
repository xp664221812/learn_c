#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
    int i = 0;
    int fd=0;
    char filename[]="test.txt";

    for(i=0;fd>=0;i++){
        fd=open(filename,O_RDONLY);
        if(fd>0){
            printf("fd:%d\n",fd);
        }else{
            printf("error,can't open file\n");
            return 0;
        }
    }


    return 0;
}

