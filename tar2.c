#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
int N=5; //the "define"
  int TheOne;           //represents the thread witch is currently runnig

void* Timer(void *index){
    struct timeval start,end;
    int *IntIndex=index ,num;
    double doubleStart,doubleEnd,doubleRes;
    num=IntIndex[0] ;
    while(1){               //looping untill the thread ends   //only happns when the main is done
gettimeofday(&start,NULL);
doubleStart= start.tv_usec;    // when ever the current thread starts to work          
TheOne=num;                     // seting the global var to this thread num so all other threads know they were ended
                                // note threads knows it wasent running  only when they come back to be the runnig thread
while(TheOne==IntIndex[0]){     // for as long as the thread is undesterbed  update it was runnig at the moment of exe the commend 
    gettimeofday(&end,NULL);
    doubleEnd=end.tv_usec;
}
doubleRes=doubleEnd-doubleStart;   // using doubles cus float is to small and trying to print strate away had probloms (maybe treated it like afloat?)
printf("\nTime slice for thread %d=%f ms",num,doubleRes/1000);  //dividing  cus of 
}


}//end Of Timer


int main(){
    int i,*Marry;
    pthread_t *thread;
    pthread_t thread1,thread2;
  thread=(pthread_t*)malloc(sizeof(pthread_t)*(N));         //array of threads
   Marry=(int*)malloc(sizeof(int)*N);                      //array of vars for threads
                                                         
   for(i=0;i<N;i++){
       Marry[i]=i;
     pthread_create(&thread[i],NULL,Timer, &Marry[i]);                   
   }
sleep(1);
free(thread);
free(Marry);
}//end of main

