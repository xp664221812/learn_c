#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>

typedef int sem_t;

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
}arg;

/*
struct sembuf{
    ushort sem_num;   //信号量的编号
    short sem_op;     //信号量的操作
    short sem_flag;   //信号量的操作标志
};
*/


sem_t createSem(key_t key,int value){
    union semun sem;
    sem_t semid;
    sem.val=value;
    semid=semget(key,1,IPC_CREAT|0x0666);

    if(-1==semid){
        perror("create sem error");
        printf("create semaphore error\n");
        return -1;
    }

    semctl(semid,0,SETVAL,sem);  //建立value个初始值的信号量

    return semid;

}


//增加信号量
int sem_p(sem_t semid){
    struct sembuf sops={0,+1,IPC_NOWAIT};   /*建立信号量结构值*/
    return semop(semid,&sops,1);
}


//减小信号量
int sem_v(sem_t semid){
    struct sembuf sops={0,-1,IPC_NOWAIT};
    return semop(semid,&sops,1);

}

//设置信号量的值
void setValueSem(sem_t semid,int value){
    union semun sem;
    sem.val=value;
    semctl(semid,0,SETVAL,sem);
}


//获取信号量的值
int getValueSem(sem_t semid){
    union semun sem;
    return semctl(semid,0,GETVAL,sem);
}

//销毁信号量
void destroySem(sem_t semid){
    union semun sem;
    sem.val=0;

    semctl(semid,0,IPC_RMID,sem);

}



int main()
{

    key_t key;
    int semid;
    char i;
    int value = 0;

    key=ftok("ipc/sem/",'a');
    printf("k===%d\n",key);
    semid=createSem(key,100);

    for(i=0;i<=3;i++){
        sem_p(semid);
        sem_v(semid);
    }

    value=getValueSem(semid);
    printf("信号量值位:%d\n",value);


    destroySem(semid);

    return 0;


}

























