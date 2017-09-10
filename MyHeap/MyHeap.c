#include <stdio.h>

int h[101];     // 用来存储堆的数组
int n;          // 用来存储堆中元素个数，也就是堆的大小

void swap1(int* x, int* y)
{
    int* tmp = NULL;
    tmp = x;
    x = y;
    y = tmp;
}

// 交换函数
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 向下调整
void shiftDown(int i)
{
    int t, flag=0;  // flag 标记是否需要继续向下调整
    while (i*2<=n && flag == 0) {
        if (h[i] < h[i*2]) {
            t = i*2;
        } else {
            t = i;
        }
        if (i*2+1 <= n) { // 如果有右儿子
            if (h[t] < h[2*i+1]) {
                t = 2*i+1;
            }
        }
        if (t != i) {
            swap(&h[t], &h[i]);
            i = t;
        } else {
            flag = 1;
        }
    }
    return;
}

// 建堆
void createHeap()
{
    int i;
    for(i=n/2; i>=1; i--) {
        shiftDown(i);
    }
    return;
}

// 堆排序
// 如果想要得到由小到大顺序的数组，则需要创建一个最大堆
void heapSort()
{
    while(n>1)
    {
        swap(&h[1], &h[n]);
        n--;
        shiftDown(1);
    }
    return;
}

int main(void) 
{
    int i, num;
    // 输入 num 个数字
    scanf("%d", &num);
    for(i=1; i<=num; i++) {
        scanf("%d", &h[i]);
    }
    n = num;
    // 建堆
    createHeap();
    for(i=1; i<=num; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
    heapSort();
    for(i=1; i<=num; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
    return 0;
}