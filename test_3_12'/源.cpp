#include <iostream>
#include<string>
using namespace std;
int main()
{
    int k;
    string s;
    char c1, c2;
    cin >> k;
    cin >> s;
    cin >> c1 >> c2;
    int n = s.size();
    int arr[10];
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == c1 && s[j] == c2)
            {
                if (arr[j] - arr[i] - 1 >= k)
                {
                    sum++;
                }
            }
        }
    }
    cout << sum;
    // 请在此输入您的代码
    return 0;
}