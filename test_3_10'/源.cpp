#include <iostream>
using namespace std;
#include<vector>
bool check(int x, int y)
{
    int flag1 = 0;
    int flag2 = 0;
    if (x % 2 == 0)
    {
        flag1 = 1;
    }
    if (y % 2 == 0)
    {
        flag2 = 1;
    }
    if ((flag1 == 1 && flag2 == 1) || (flag1 == 0 && flag2 == 0))
    {
        return true;
    }
    return false;
}
//int main()
//{
//    // 请在此输入您的代码
//    int n = 0;
//    cin >> n;
//    vector<int>arr(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = 0; j < n - i - 1; j++)
//        {
//            if (check(arr[j], arr[j + 1]))
//            {
//                if (arr[j] > arr[j + 1])
//                {
//                    int tmp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = tmp;
//                }
//            }
//            else
//            {
//                if (arr[j] / 2 == 0)
//                {
//                    int tmp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = tmp;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    return 0;
//}

int main()
{
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    int n = 9;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}