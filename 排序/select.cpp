#include <iostream>
using namespace std;

void select(int *a, int length)
{
    for (int i = 0; i < length - 1; i++) {
        int minindex = i;
        int minvalue = a[i];
        for (int j = i+1; j < length; j++) {
            if (minvalue > a[j]) {
                minvalue = a[j];
                minindex = j;
            }
        }
        int temp;
        temp = a[minindex];
        a[minindex] = a[i];
        a[i] = temp;
    }
}
int main()
{
    int a[10] = {8, 7, 3, 4, 2, 1, 5, 6, 9, 10};
    int length = sizeof(a)/sizeof(a[0]);
    select(a, length);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
