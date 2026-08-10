#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* myThread(void* arg) {
  printf("Thread is running...\n");
  printf("Thread is terminating....\n");
  pthread_exit(NULL);
}

int main() {
  pthread_t tid;

  //Create thread
  if(pthread_create(&tid, NULL, myThread, NULL)!=0){
    printf("Thread creation failed\n");
    return 1;
  }

  //wait for thread to finish
  pthread_join(tid, NULL);

  printf("Main process terminating....\n");


  printf("\n---------------------------------------\n");
  printf("Lab No.: 2   Name: Karuna Achhami   Roll No.: 46   Section: B\n");
  printf("---------------------------------------\n");


  return 0;
}