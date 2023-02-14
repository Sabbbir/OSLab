#include<stdio.h>
int main()
{
    int n,burst_t[10],waiting_t[10],ct[10],priority[10],i,j,temp=0,temp1=0;
    printf("Number of processes:");
    scanf("%d",&n);
    // printf("     Burst_Time Priority \n");
    for(i=0;i<n;i++)
    {
        printf("Burst Time[P%d]: ",i+1);
        scanf("%d",&burst_t[i]);
        printf("Priority[P%d]: ",i+1);
        scanf("%d",&priority[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(priority[i]>priority[j])
            {
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;

                temp1=burst_t[i];
                burst_t[i]=burst_t[j];
                burst_t[j]=temp1;
            }
        }
    }
    printf("Priority  BT \n");
    for(i=0;i<n;i++)
    {
        printf("%d   \t%d\n",priority[i],burst_t[i]);
    }

    printf("\n");
       ct[-1]=0;
     for(i=0;i<n;i++)
    {
        ct[i]=ct[i-1]+ burst_t[i];
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        waiting_t[i]=ct[i]-burst_t[i];
        sum=sum+waiting_t[i];
    }
    printf("Waiting Time: ");
    printf("%d\n",sum);
    float avg;
    avg=(float)sum/n;
    printf("Avg. Waiting Time:\n");
    printf("%.3f\n",avg);
}