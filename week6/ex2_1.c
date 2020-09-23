#include<stdio.h>

//Quick Sort
int partition(int arr[], int low, int high, int at[]) {
    int temp;
    int pivot = arr[high]; // assuming last element of the array as the pivot element
    int i = (low - 1); // assuming the index of i pointer as one position less than the first element
    for (int j = low; j <= high - 1; j++) // assuming the index of j pointer as the first position
        { // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // increment index of i pointer and swap the elemets at index i and j
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
    }
    // swapping the pivot (last) element and element at i + 1 index
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    temp = at[i + 1];
    at[i + 1] = at[high];
    at[high] = temp;
    // returning the index of pivot element having lesser elements to the left and greater elements to the right
    return (i + 1);
}

void quick_sort(int arr[], int low, int high, int at[]) {
    if (low < high) {
        // partitioning the single array into two sub-arrays
        int pi = partition(arr, low, high, at);
        // sorting the sub-arrays
        quick_sort(arr, low, pi - 1, at);
        quick_sort(arr, pi + 1, high, at);
    }
}

int main(){

	int bt[20]={0},at[20]={0},tat[20]={0},wt[20]={0},ct[20]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter Arrival time and Burst time for each process\n\n");

	for(int i=0;i<n;i++)
	{
		printf("Arrival time of process[%d]: ",i+1);
		scanf("%d",&at[i]);
		printf("Burst time of process[%d]: ",i+1);
		scanf("%d",&bt[i]);
	}
	//Sorting by AT
    quick_sort(bt, 0, n - 1, at);

	//calculate completion time of processes
	for(int j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum+at[0];
	}

	//calculate turnaround time and waiting times
	for(int k=0;k<n;k++) {
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}
	for(int k=0;k<n;k++) {
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}

	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	for(int i=0;i<n;i++) {
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}

	printf("\n\nAverage Turnaround Time: %f\n",totalTAT/n);
	printf("Average Waiting Time: %f\n\n",totalWT/n);
	return 0;
}


