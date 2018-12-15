#include <iostream>
using namespace std;

void bubble(int *a, int length)
{
    int temp;
    for (int i = 0; i < length-1; i++)
        for (int j = 0; j < length-i-1; j++)
            if (a[j] >= a[j+1]) {  // swap(a[j],a[j+1]);
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
}
int main()
{
    int a[10] = {8, 7, 4, 3, 2, 1, 5, 6, 9, 10};
    int length = sizeof(a)/sizeof(a[0]);
    bubble(a, length);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
