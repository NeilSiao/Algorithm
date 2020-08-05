#include <stdio.h>

int size;

void printArr(int arr[], char string[]);
void swap(int *x, int *y);
/*Selection Sort:
total Comparison Times is fixed to n*(n-1) / 2
Time Complexity is  approximately to O(n^2)
*/
int main()
{
    int arr[] = {1,5,7,3,8,2,2,1,5,8};
    int i,j;
    
    // C language doesn't have built in function like count or length....
    size = sizeof(arr) / sizeof arr[0];
    //count algo runs how many times.
    int totalCmpTime = 0;

    printf(" Array Size is  %d \n",  size);
    printArr(arr, "BeforeSort");

    for(i=0;i < size ; i++){
        for(j= i + 1 ; j < size ; j++){
            totalCmpTime++;
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }

    printArr(arr, "AfterSort");

   printf("\n Total Comparison times:  %d", totalCmpTime);
}

void printArr(int arr[], char string[])
{
     printf("\n%s \n", string);
     for(int i =0;i<size; i++){
        printf("arr[%d] = %d \n",i ,arr[i] );
    }
}
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}