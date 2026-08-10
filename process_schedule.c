#include <stdio.h>
#define MAX 20

int main() {
  int n, i;
  int bt[MAX], wt[MAX], tat[MAX];
  float avwt = 0, avtat = 0;


  printf("Enter total number of processes (maximum %d): ", MAX);
  scanf("%d", &n);

  printf("Enter Burst Time of each process (in the order they arrive):\n");
  for(i = 0; i<n; i++) {
    printf("P[%d]: ", i+1);
    scanf("%d", &bt[i]);
  }

  /*FCFS: processes run strictly in arrival order.*/
  /*Waiting time of a process =sum of burst time of all processes before it*/
  wt[0]=0;
  for(i=1;i<n;i++){
    wt[i] = wt[i-1] + bt[i-1];
  }
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0; i<n; i++){
    tat[i]= bt[i] + wt[i];
    avwt += wt[i];
    avtat += tat[i];
    printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
  }
  printf("\nAverage Waiting Time = %.2f", avwt /n);
  printf("\nAverage Turnaround Time = %.2f\n", avtat /n);

  printf("\n---------------------------------------------\n");
  printf("Lab No .: 3    Name: Karuna  Roll no: 46 Section: B\n");
  printf("--------------------------------------------------\n");

  return 0;

}
