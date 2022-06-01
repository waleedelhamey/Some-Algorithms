#include <bits/stdc++.h>
using namespace std;
int SequentialSearch(int a[], int n,int key)
{
    if(n<0)
        return -1;
    if(a[n]==key)
        return n;
    else
        return SequentialSearch(a,n-1,key);
}
int binarySearch(int A[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high)/2;
    if (x == A[mid])
        return mid;
    else if (x < A[mid])
        return binarySearch(A, low,  mid - 1, x);
    else
        return binarySearch(A, mid + 1,  high, x);
}
void print(int arr[],int n){
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
int main() {
    int *arr1;
    int *arr2;
    int *arr3;
    for(int i=0;i<1000;++i){
        arr1[i]=rand()%1000;
    }
    for(int i=0;i<10000;++i){
        arr2[i]=rand()%10000;
    }
    for(int i=0;i<100000;++i){
        arr3[i]=rand()%100000;
    }
    //////////////////////////////////////////For sequential search at size 1000
    int x1 = rand()%1000;
    clock_t  t1;
    t1=clock();
    int ans1 = SequentialSearch(arr1,1000,x1);
    t1=clock()-t1;
    cout<<"Time in sequential search is: "<<((double)t1)/ CLOCKS_PER_SEC<<"\n";
    if(ans1==-1)
        cout<<x1<<"was not found in the array \n";
    else
        cout<<"index of "<<x1<<" is "<<ans1;
    /////////////////////////////////////////////For binary search at size 1000
    clock_t b1;
    b1=clock();
    int ans2 = binarySearch(arr1,0,1000,x1);
    b1=clock()-b1;
    cout<<"Time in binary search is: "<<((double)b1)/ CLOCKS_PER_SEC<<"\n";
    if(ans2==-1)
        cout<<x1<<"was not found in the array \n";
    else
        cout<<"index of "<<x1<<" is "<<ans2;
    /////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////For sequential search at size 10000
    int x2 = rand()%10000;
    clock_t  t2;
    t2=clock();
    int ans3 = SequentialSearch(arr2,10000,x1);
    t2=clock()-t1;
    cout<<"Time in sequential search is: "<<((double)t2)/ CLOCKS_PER_SEC<<"\n";
    if(ans3==-1)
        cout<<x2<<"was not found in the array \n";
    else
        cout<<"index of "<<x2<<" is "<<ans3;
    /////////////////////////////////////////////For binary search at size 10000
    clock_t b2;
    b2=clock();
    int ans4 = binarySearch(arr2,0,10000,x2);
    b2=clock()-b2;
    cout<<"Time in binary search is: "<<((double)b2)/ CLOCKS_PER_SEC<<"\n";
    if(ans4==-1)
        cout<<x2<<"was not found in the array \n";
    else
        cout<<"index of "<<x2<<" is "<<ans4;
    /////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////For sequential search at size 100000
    int x3 = rand()%10000;
    clock_t  t3;
    t3=clock();
    int ans5 = SequentialSearch(arr3,100000,x3);
    t3=clock()-t3;
    cout<<"Time in sequential search is: "<<((double)t3)/ CLOCKS_PER_SEC<<"\n";
    if(ans5==-1)
        cout<<x3<<"was not found in the array \n";
    else
        cout<<"index of "<<x3<<" is "<<ans5;
    /////////////////////////////////////////////For binary search at size 100000
    clock_t b3;
    b3=clock();
    int ans6= binarySearch(arr3,0,100000,x3);
    b3=clock()-b3;
    cout<<"Time in binary search is: "<<((double)b3)/ CLOCKS_PER_SEC<<"\n";
    if(ans6==-1)
        cout<<x2<<"was not found in the array \n";
    else
        cout<<"index of "<<x3<<" is "<<ans6;
    return 0;
}
