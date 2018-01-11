#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>

void *producter_f(void *arg);
void *consumer_f(void *arg);

int buffer_has_item=0;
pthread_mutex_t mutex;
int running=-1;





int main()
{

    pthread_t consumer_t;
    pthread_t producter_t;

    pthread_mutex_init(&mutex,NULL);
    pthread_create(&producter_t,NULL,(void*)producter_f,NULL);
    pthread_create(&consumer_t,NULL,(void*)consumer_f,NULL);

    usleep(1);
    running=0;
    pthread_join(consumer_t,NULL);
    pthread_join(producter_t,NULL);

    pthread_mutex_destroy(&mutex);

}






//生产者函数

void *producter_f(void *arg){
    while(running){
        pthread_mutex_lock(&mutex);
        buffer_has_item++;
        printf("生产，总数量:%d\n",buffer_has_item);
        pthread_mutex_unlock(&mutex);
    }

}


//消费者
void *consumer_f(void *arg){
    while(running){
        pthread_mutex_lock(&mutex);
        buffer_has_item--;
        printf("消费，总数量%d\n",buffer_has_item);
        pthread_mutex_unlock(&mutex);
    }

}
