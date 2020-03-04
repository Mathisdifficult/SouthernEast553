#include <iostream>
using namespace std;
int fun(){
    static int count=0;
    for(int i=1;i<=9;i++)
        for(int j=0;j<=9;j++)
            for (int k=0; k<=9; k++) {
                if (i!=j&&i!=k&&j!=k) {
                    count++;
                }
            }
    return count;
}

int main() {
    cout<<"一共有"<<fun()<<"个"<<endl;
}
