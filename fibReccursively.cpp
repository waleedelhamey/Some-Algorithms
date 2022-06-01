#include <bits/stdc++.h>
using namespace std;
int fibReccursively (int n)
{
    if (n <= 1)
        return n;
    else
        return fibReccursively (n - 1) + fibReccursively (n-2);
}
int fibDynamicProgramming(int n)
{
    int f[n];
    int i;

    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
void MatrixMultiply(int F[2][2], int M[2][2]) {
    int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}
void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    MatrixMultiply(F, F);
    if (n % 2 != 0)
        MatrixMultiply(F, M);
}
int FibonacciByMatrix(int n) {
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int main() {
    cout<<fibReccursively(8)<<endl;
    cout<<fibDynamicProgramming(8)<<endl;
    cout<<FibonacciByMatrix(8)<<endl;
    return 0;
}
