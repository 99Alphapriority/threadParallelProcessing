#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int a;
pthread_mutex_t mutex;


void update(){
    int s = 0;
    while(s<100)
    {   s++;
        a++;   
    }
    printf("Value: %d \n",a);
}


void* init(void* a){
    long *myID = (long*) a;
    
    printf("Thread %ld started. \n",*myID);
    sleep(2);
    pthread_mutex_lock(&mutex);
    update();
    pthread_mutex_unlock(&mutex);
        

    
}



void main(){
    int n, *res;
    pthread_t tid;
    printf("Enter number of thread: \n");
    scanf("%d",&n);
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i<n; i++)
        pthread_create(&tid, NULL, &init, (void *)&tid);
       
     pthread_exit(NULL);   
    // for(int i = 0; i<n; i++)    
    //     {   pthread_join(tid, NULL);
    //         printf("Thread %d stopped. \n",i+1) ;
    //     }
    
 
}