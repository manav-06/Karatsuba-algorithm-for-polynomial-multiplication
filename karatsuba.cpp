#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>

// void printvec(vi &a)
// {
// 	for (int x : a)
// 		cout << x << ' ';
// 	cout << '\n';
// }

vi sum(vi &a, vi &b, int n)
{
    vi res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = a[i] + b[i];
    }
    return res;
}
vi subtract(vi &a, vi &b, int n)
{
    vi res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = a[i] - b[i];
    }
    return res;
}

vi multiply(vi &a, vi &b, int n)
{
    if (n == 1)
        return {a[0] * b[0], 0};
    vi al(n / 2), ar(n / 2), bl(n / 2), br(n / 2);
    // 1 1 0 0
    // -1 1 0 0

    // printvec(a);

    for (int i = 0; i < n / 2; i++)
    {
        al[i] = a[i + n / 2];
        bl[i] = b[i + n / 2];
        ar[i] = a[i];
        br[i] = b[i];
    }
    // printvec(al);
    // printvec(ar);
    // return a;

    vi s1 = sum(al, ar, n / 2), s2 = sum(bl, br, n / 2);
    // printvec(s1);
    // printvec(s2);
    // return a;

    vi A = multiply(al, bl, n / 2), B = multiply(s1, s2, n / 2), C = multiply(ar, br, n / 2);
    assert(A.size() == n);
    assert(B.size() == n);
    assert(C.size() == n);
    // printvec(A);
    // printvec(B);
    // printvec(C);
    // return a;

    vi temp = sum(A, C, n);
    B = subtract(B, temp, n);
    vi res(2 * n);

    for (int i = 0; i < n; i++)
    {
        res[i + n] += A[i];
        res[i] += C[i];
        res[i + n / 2] += B[i];
    }
    return res;
}

vi karatsuba(vi a, vi b)
{
    int n1 = a.size(), n2 = b.size(), n = 1;
    while (n < n1 + n2)
        n *= 2;
    a.resize(n);
    b.resize(n);

    vi res = multiply(a, b, n);
    return res;
}

void test_case()
{
    vi a = {1, 0, 0, 2, 1}, b = {1, -4, -9};
    vi res = karatsuba(a, b);
    for (int x : res)
    {
        cout << x << ' ';
    }
}

signed main()
{
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        test_case();
    }
}
