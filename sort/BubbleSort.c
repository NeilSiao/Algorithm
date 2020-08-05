#include <stdio.h>

int size;

void printArr(int arr[], char string[]);
void swap(int *x, int *y);
/*Bubble Sort:
total Comparison Times is worst condition is n*(n-1) / 2
Time Complexity worst case to O(n^2), best case O(n)

1.      比較之回合數=資料數(n)-1。
2.        每一回合至少有一資料可以排列至正確之次序。
3.        時間複製度，最差與平均時間O(n2)
4.        需要一個額外(元素)空間。 O(1) 需要 temp 參數，進行交換。
5.        為一穩定排序。
6.        資料量小時，使用效果佳。
參考網址: http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm#_Toc229730276
*/
int main()
{
    int arr[] = {1, 5, 7, 3, 8, 2, 2, 1, 5, 8};
    int i, j;

    // C language doesn't have built in function like count or length....
    size = sizeof(arr) / sizeof arr[0];
    //count algo runs how many times.
    int totalCmpTime = 0;

    printf(" Array Size is  %d \n", size);
    printArr(arr, "BeforeSort");

    /* 
    慢慢兩兩相比較，往上浮上去，總比較回合數為 n - 1 回合。
    每一回合皆會完成最尾數排序，下一回合就不需列入考慮，因此才會有 j < size - i
    */
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[(j + 1)])
            {
                totalCmpTime++;
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printArr(arr, "AfterSort");

    printf("\n Total Comparison times:  %d", totalCmpTime);
}

void printArr(int arr[], char string[])
{
    printf("\n%s \n", string);
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d \n", i, arr[i]);
    }
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}