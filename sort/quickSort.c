#include <stdio.h>

int size;

void printArr(int arr[], char string[]);
void swap(int *x, int *y);
/*Insertion Sort:
total Comparison Times is worst condition is n*(n-1) / 2
Time Complexity worst case to O(n^2), best case O(n)

int i是「目前要處理」的資料index(i)；
int j=i-1是用來指出前1~i−1筆資料的index；
第一個for迴圈，用意是把每一個矩陣元素都視為「目前要處理」的資料一次；
在for迴圈裡的while迴圈，用意是把「目前要處理」的資料與前1~i−1筆資料做比較，並找到適當的位置，將1~i筆資料做排序。
參考網誌: http://alrightchiu.github.io/SecondRound/comparison-sort-insertion-sortcha-ru-pai-xu-fa.html
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

    // 將數量慢慢地從1擴增至 size 大小，逐步增加已排序的陣列大小。
    for(i=0;i < size ; i++){
        int key = arr[i];
        int j = i - 1 ;
        while(key < arr[j] && j >=0){
            //如果小於排序的數值，直接往後搬移，因為需要全數搬移出空位給新數放置。
            totalCmpTime++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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