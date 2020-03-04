#include <iostream>
using namespace std;

template<typename T>
int findMin(T a[], int last) {
    static int minpos=last;
    if(last>=0){
        if(a[minpos]>a[last])
            minpos=last;
        findMin(a, last-1);
    }
    return minpos;
}

int main() {
    int a[10] = { -1, 1, -10, 9, 8, 4, 6, -5 };
    int pos = findMin(a, 8);
    cout << a[pos]<<endl;
    return 0;
    
}
