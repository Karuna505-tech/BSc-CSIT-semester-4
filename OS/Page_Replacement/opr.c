#include <stdio.h>

int main() {
    int frames, n, i, j, k;

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    printf("Enter length of reference string: ");
    scanf("%d",&n);

    int ref[n], frame[frames];

    printf("Enter reference string:\n");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);

    for(i=0;i<frames;i++)
        frame[i]=-1;

    int hit=0,fault=0;

    printf("\nPage\tFrames\n");

    for(i=0;i<n;i++){

        int found=0;

        for(j=0;j<frames;j++){
            if(frame[j]==ref[i]){
                found=1;
                hit++;
                break;
            }
        }

        if(!found){

            int empty=-1;

            for(j=0;j<frames;j++){
                if(frame[j]==-1){
                    empty=j;
                    break;
                }
            }

            if(empty!=-1){
                frame[empty]=ref[i];
            }
            else{

                int farthest=-1,index=-1;

                for(j=0;j<frames;j++){

                    int next=n;

                    for(k=i+1;k<n;k++){

                        if(frame[j]==ref[k]){
                            next=k;
                            break;
                        }
                    }

                    if(next>farthest){
                        farthest=next;
                        index=j;
                    }
                }

                frame[index]=ref[i];
            }

            fault++;
        }

        printf("%d\t",ref[i]);

        for(j=0;j<frames;j++){

            if(frame[j]==-1)
                printf("- ");
            else
                printf("%d ",frame[j]);
        }

        printf("\n");
    }

    printf("\nPage Hits=%d",hit);
    printf("\nPage Faults=%d\n",fault);
    
    printf("\n---------------------------------------------\n");
    printf("Lab No .: 3    Name: Karuna  Roll no: 46 Section: B\n");
    printf("--------------------------------------------------\n");

    return 0;
}