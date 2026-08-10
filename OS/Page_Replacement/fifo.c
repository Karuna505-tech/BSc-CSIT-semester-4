#include <stdio.h>

int main() {
  int frames, n, i ,j;

  printf("Enter number of frames: ");
  scanf("%d", &frames);

  printf("Enter length of reference string: ");
  scanf("%d", &n);

  int ref[n], frame[frames];

  printf("Enter reference string: \n");
  for(i=0; i<n; i++)
    scanf("%d", &ref[i]);
  
  for(i=0; i<frames; i++)
    frame[i]= -1;
  
  int pointer = 0;
  int hit = 0, fault = 0;

  printf("\nPage\tFrames\n");

  for(i = 0; i<n; i++){
    int found = 0;

    for(j=0; j<frames; j++){
      if (frame[j] == ref[i]){
        found = 1;
        hit++;
        break;
      }
    }
    if(!found) {
      frame[pointer] = ref[i];
      pointer = (pointer+1)%frames;
      fault++;
    }
    printf("%d\t", ref[i]);

    for(j = 0; j<frames; j++){
      if(frame[j] == -1)
        printf("-");
      else
        printf("%d\t", frame[j]);

      }
      printf("\n");
    }
    printf("\nPage Hits = %d", hit);
    printf("\nPage Faults = %d\n", fault);
    
    printf("\n---------------------------------------------\n");
    printf("Lab No .: 3    Name: Karuna  Roll no: 46 Section: B\n");
    printf("--------------------------------------------------\n");
    return 0;
  }
