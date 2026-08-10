#include <stdio.h>

int main(){
  int frames,n,i,j;

  printf("Enter number of frames: ");
  scanf("%d", &frames);

  printf("Enter length of reference string: ");
  scanf("%d", &n);

  int ref[n], frame[frames], time[frames];

  printf("Enter reference string:\n");
  for(i=0;i<n;i++)
    scanf("%d", &ref[i]);
  
    for(i=0;i<frames;i++){
      frame[i]=-1;
      time[i]=0;
    }
    int hit=0,fault=0,clock=0;
    printf("\nPage\tFrames\n");

    for(i=0;i<n;i++){
      clock++;
      int found=-1;

      for(j=0;j<frames;j++){
        if(frame[j]==ref[i]){
          found=j;
          break;
        }
      }
      if(found != -1){
        hit++;
        time[found]=clock;
      }
      else {
        int pos = -1;
        for(j=0;j<frames;j++){
          if(frame[j]==-1){
            pos = j;
            break;
        }
      }
        if(pos == -1){
          pos=0;
          for(j=1;j<frames;j++){
            if(time[j]<time[pos])
            pos=j;
          }
        }
        frame[pos]=ref[i];
        time[pos]=clock;
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
  printf("\nPage Fault=%d\n",fault);

    printf("\n---------------------------------------------\n");
    printf("Lab No .: 3    Name: Karuna  Roll no: 46 Section: B\n");
    printf("--------------------------------------------------\n");
  return 0;
}