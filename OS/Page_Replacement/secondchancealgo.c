#include <stdio.h>

int main(){
  int frames,n,i,j;

  printf("Enter number of frames: ");
  scanf("%d", &frames);

  printf("Enter length of reference string: ");
  scanf("%d", &n);

  int ref[n], frame[frames], bit[frames];

  printf("Enter reference strinf:\n");

  for(i=0;i<n;i++)
    scanf("%d", &ref[i]);
  
    for(i=0; i<frames;i++){
      frame[i]=-1;
      bit[i]=0;
    }
    int pointer=0, hit=0, fault=0;
    printf("\nPage\tFrames\n");
    for(i=0;i<n;i++){
      int found =-1;
      for(j=0;j<frames;j++){
        if(frame[j]==ref[i]){
          found=j;
          break;
        }
      }
      if (found!=-1){
        hit++;
        bit[found]=1;
      }
        else {
          while(bit[pointer]==1){
          bit[pointer]=0;
          pointer=(pointer+1)%frames;
        }
        frame[pointer]= ref[i];
        bit[pointer]=1;
        pointer=(pointer+1)%frames;
        fault++;
      }
      printf("%d\t", ref[i]);

      for(j=0;j<frames;j++){
        if(frame[j]==-1)
        printf("-");
        else
          printf("%d", frame[j]);
      }
      printf("\n");
    }
    printf("\nPage Hits=%d", hit);
    printf("\nPage Faults=%d\n", fault);
    
    printf("\n---------------------------------------------\n");
    printf("Lab No .: 3    Name: Karuna  Roll no: 46 Section: B\n");
    printf("--------------------------------------------------\n");

    return 0;
}