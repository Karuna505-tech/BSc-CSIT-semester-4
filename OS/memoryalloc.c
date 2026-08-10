#include <stdio.h>

int main() {
  int m, n, i, j, choice;
  printf("Enter number of memory blocks: ");
  scanf("%d", &m);

  int block[m], originalBlock[m];

  printf("Enter sizes of memory blocks:\n");
  for(i=0; i<m; i++)
  {
    scanf("%d", &block[i]);
    originalBlock[i] = block[i]; //Save original block sizes
  }
  

  printf("Enter number of processes:\n");
  scanf("%d", &n);

  int process[n];

  printf("Enter sizes of processes:\n");
  for(i= 0; i<n; i++)
  scanf("%d", &process[i]);

  do{
    //Restore original block sizes before every algorithm
    for(i=0; i<m; i++)
      block[i] = originalBlock[i];

      int allocation[n];

      for(i=0; i<n; i++)
        allocation[i] = -1;

      printf("\n");
      printf("===Memory Allocation ====\n");
      printf("1.First Fit\n");
      printf("2.Best Fit\n");
      printf("3.Worst Fit\n");
      printf("4.Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

    switch(choice)
    {
      case 1:
      //First Fit
      for(i=0; i<n; i++)
      {
        for(j=0;j<m; j++)
        {
          if(block[j] >= process[i])
          {
            allocation[i] = j;
            block[j] -= process[i];
            break;
          }
        }
      }
      printf("\n --- First Fit Allocation---\n");
      break;

      case 2:
      // Best Fit
      for(i=0; i<n; i++)
      {
        int best = -1;
        for(j=0; j<m; j++)
        {
          if(block[j] >= process[i])
          {
            if(best == -1 || block[j] < block[best])
            best = j;
          }
        }
        if(best != -1)
        {
          allocation[i] = best;
          block[best] -= process[i];
        }

      }
      printf("\n----Best Fit Allocation---\n");
      break;

      case 3:
      //Worst Fit
      for(i = 0; i<n; i++)
      {
        int worst = -1;
        for(j = 0; j<m; j++)
        {
          if(block[j] >= process[i])
          {
            if(worst == -1 || block[j] > block[worst])
            worst = j;
          }
        }
        if(worst != -1)
        {
          allocation[i] = worst;
          block[worst] -= process[i];
    
        }
      }
      printf("\n --Worst Fit Allocation ---\n");
      break;

      case 4:
      printf("\n Program Terminates.\n");
      return 0;

    
      default:
      printf("\n Invalid Choice!\n");
      continue;

    }
    printf("\nProcess\tSize\tBlock Allocated\n");

    for(i=0; i<n; i++)
    { 
      printf("P%d\t%d\t", i + 1, process[i]);

            if(allocation[i] != -1)
                printf("%d\n", allocation[i] + 1);
            else
                printf("Not Allocated\n");

    }
  printf("\n---------------------------------------\n");
  printf("Lab No.: 2   Name: Karuna Achhami   Roll No.: 46   Section: B\n");
  printf("---------------------------------------\n");


  }while(choice != 4);
  
  
}