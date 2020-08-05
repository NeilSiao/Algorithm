#include <stdio.h>

int size;

void printArr(int arr[], char string[]);
void swap(int *x, int *y);
void QuickSort(int *arr, int left, int right);
/*Quick Sort:
快速排序之觀念，找資料之中間值，將小於中間值放右邊，大於中間值放左邊，再以相同方法分左右兩邊序列，直到排序完成。

【分析】

1.時間複製度，最差O(n2)與平均時間O(nlog2n)。
2.需要額外堆疊空間。
3.為不穩定排序。
4.快速排序是平均時間最快之內部排序法。

【原理】

1.取第一個記錄為鍵值K0，當中間值。
2.由左而右找第一個Ki，使得Ki≧K0。由右而左找第一個Kj，使得Kj≦K0。也就是說，從左邊找比K0大，從右邊找比K0小。
3.若i<j則Ki與Kj對調位置繼續步驟2；否則K0與Kj對調位置，並以j為基準，分為兩個未排序之序列。以遞迴呼叫方式對左右兩邊進行排序，直道完成排序。
4.由最大(最小)逐回合比較至最小(最大)。
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

    // 將數量慢慢地從1擴增至 size 大小，逐步增加已排序的陣列大小。
    QuickSort(arr, 0, 9);

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
void QuickSort(int *arr, int left, int right)
{
    int i, j, s, Temp;

    if (left < right)
    {
        s = arr[(left + right) / 2];
        i = left - 1;
        j = right + 1;
        while (1)
        {
            while (arr[++i] < s) ; // 向右找
            while (arr[--j] > s); // 向左找

            if (i >= j)
                break;
            Temp = arr[i];
            arr[i] = arr[j];
            arr[j] = Temp;
        }
        QuickSort(arr, left, i - 1); // 對左邊進行遞迴
        QuickSort(arr, j + 1, right); // 對右邊進行遞迴
    }
}