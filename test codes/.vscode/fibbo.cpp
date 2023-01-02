#include <iostream>
using namespace std;

int main()
{
    int fir = 0, sec = 1, tir, num;
    int arr[40], j = 0, c, m = 0;
    cout << "Enter the number of terms of the series: ";
    cin >> num;
    for (int i = 0; i < num - 2; i++)
    {
        if (i <= 1)
        {
            cout << i << endl;
        }
        tir = fir + sec;
        fir = sec;
        sec = tir;
        cout << tir << endl;

        if (tir - fir > 1)
        {
            for (c = fir + 1; c < tir; c++)
            {
                arr[j] = c;
                m++;
                j++;
            }
        }
    }
    cout<<"The missing terms are:"<<endl;
    for (int n = 0; n < m; n++)
    {
        cout << arr[n] << " ";
    }
    return 0;
}
