#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int N=4; //the "define"
 long int *cnt;
void* cntUp(void *arr){             //tested
    int i,*a=arr;
    i=a[0];
    while(1){
    cnt[i] ++;
    }
}//cntUp                           
int inutilaizeCntArr(){         //tested
    int i;
    cnt=(long int*)malloc(N*sizeof(long int));
    if (cnt==NULL){
        printf("malloc in inutilaizeCntArr fail");
        return -1;
    }
    for(i=0;i<N;i++)cnt[i]=0;
    return 1;
}//inutilaizeCntArr()
void freeCnt(){                 //tested
 free(cnt);
}//end of freeCnt()
void* print(){
    int i;
    while(1){
    printf("\nprint:");
    for(i=0; i<N; i++)
    printf("\ncnt[%d]=%d",i,cnt[i]);
    sleep(2);
    }
}

int main(){
    int i,arr[1],*Marr;
    pthread_t *thread;
   if (-1==inutilaizeCntArr()) exit(0);
  thread=(pthread_t*)malloc(sizeof(pthread_t)*(N+1)) ;
  Marr=(int*)malloc(sizeof(int)*N);
  for(i=0;i<N;i++){
    Marr[i]=i;
pthread_create(&thread[i],NULL,cntUp, &Marr[i]);
  }

pthread_create(&thread[N],NULL,print, NULL);

sleep(20);
free(Marr);
freeCnt();
}//end of main

