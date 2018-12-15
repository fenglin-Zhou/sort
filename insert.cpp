#include <iostream>
using namespace std;

void insert(int *a, int length)
{
    for (int j = 1; j < length; j++){
        int key = a[j];
        int i = j-1;
        while (i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }
}
int main()
{
    int a[10] = {8, 7, 4, 3, 2, 1, 5, 6, 9, 10};
    int length = sizeof(a)/sizeof(a[0]);
    insert(a, length);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

