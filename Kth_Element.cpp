#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r)
{
    int p = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= p) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int kth(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {

        int pos = partition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kth(arr, l, pos - 1, k);
        return kth(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

 int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kth(arr, 0, n - 1, k);

    return 0;
}
