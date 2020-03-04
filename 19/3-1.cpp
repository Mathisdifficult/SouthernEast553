//编程题1.cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int GetFigures(int n)//向上取整 4取10 80取100 889取1000以此来推
{
    if (n==0)
    {
        return 1;
    }
    int count=0;
    while (n!=0)
    {
        count++;
        n/=10;
    }
    
    return count;
}

int main(){
    for(int i =1;i<=10000;i++){
        int ii=i*i;
        int p = static_cast<int>(pow(10.0,GetFigures(i)));
        while(ii>1){
        if((ii-i)%p==0){
            cout<<i<<endl;
            break;
        }
        else
            ii=ii/10;
        }
        
    }
}

