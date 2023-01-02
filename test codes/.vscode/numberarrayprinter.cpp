#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i, j, min;
    cin >> N;
    cout << "Value of N: " << N << endl;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            min = i < j ? i : j;
            cout << N - min + 1 << " ";
        }
        for (j = N - 1; j >= 1; j--)
        {
            min = i < j ? i : j;
            cout << N - min + 1 << " ";
        }
        cout << endl;
    }
    for (i = N - 1; i >= 1; i--)
    {
        for (j = 1; j <= N; j++)
        {
            min = i < j ? i : j;
            cout << N - min + 1 << " ";
        }
        for (j = N - 1; j >= 1; j--)
        {
            min = i < j ? i : j;
            cout << N - min + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
