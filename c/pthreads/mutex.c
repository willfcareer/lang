#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>

static int value = 0;
pthread_mutex_t mutex;

void func(void* args){
	while(1){
		pthread_mutex_lock(&mutex);
		value ++;
		printf("value = %d, tid = %d\n", value,syscall(SYS_gettid));
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

int main(){
	pthread_t pid1, pid2;
	pthread_mutex_init(&mutex, NULL);

	if(pthread_create(&pid1, NULL, func, NULL)){
		return -1;
	}

	if(pthread_create(&pid2, NULL, func, NULL)){
                return -1;
        }
	printf("PID = %d\n",getpid());
	while(1) sleep(0);
	return 0;
}
