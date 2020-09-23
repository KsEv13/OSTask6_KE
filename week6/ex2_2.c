#include <stdio.h>

int main() {
      int at[10], bt[10], temp[10];
      int i, min, count = 0, time, limit, sum =0;
      double wt = 0, turnaround_time = 0, end;
      float average_wt, average_tat;
      printf("\nEnter number of processes: \t");
      scanf("%d", &limit);
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++) {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &bt[i]);
            temp[i] = bt[i];
      }
      bt[9] = 9999;
      for(time = 0; count != limit; time++) {
            min = 9;
            for(i = 0; i < limit; i++) {
                  if(at[i] <= time && bt[i] < bt[min] && bt[i] > 0) {
                        min = i;
                  }
            }
            bt[min]--;
            if(bt[min] == 0) {
                  count++;
                  end = time + 1;
                  wt = wt + end - at[min] - temp[min];
                  turnaround_time = turnaround_time + end - at[min];
            }
      }
      average_wt = wt / limit;
      average_tat = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_wt);
      printf("Average Turnaround Time:\t%lf\n", average_tat);
      return 0;
}


