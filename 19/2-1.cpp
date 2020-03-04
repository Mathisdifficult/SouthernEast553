#include <iostream>
using namespace std;
int func(char* str){
    int d,num,len;
    while(*str!='\0'){
        d=num=0;
        len=strlen(str);
        for (int i=0; i<len; i++) {
            d=d*10+str[i]-static_cast<int>('0');
        }
        num+=d;
        len--;
        str=&str[len+1];
    }
    return num;
}

int main() {
    cout<<"字符串转数字为"<<func("123321")<<endl;
}
