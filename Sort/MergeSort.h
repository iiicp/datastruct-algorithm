/***********************************
* File:     MergeSort.h
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#ifndef SORTTEST_MERGESORT_H
#define SORTTEST_MERGESORT_H

void __merge(int *arr, int l, int mid, int r) {
    int *temp = new int[r - l + 1];

    int i = l, j = mid+1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
        }
    }

    if (i <= mid) {
        temp[k++] = arr[i++];
    }else if (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; ++i) {
        arr[l + i] = temp[i];
    }
}

void __mergeSort(int *arr, int l, int r) {
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

void mergeSort(int *arr, int n) {

    if (arr == nullptr || n <= 0)
        return;

    __mergeSort(arr, 0, n - 1);
}

#endif //SORTTEST_MERGESORT_H
