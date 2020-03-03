//编程题3.cpp
#include <iostream>
using namespace std;
class SelfString{
    friend void findCommon(const SelfString& s1, const SelfString& s2);
private:
    char* dataStr;
    int Length;
public:
    static const int MAXN=100;
    SelfString(const char * const s);
    ~SelfString();
    
};
void findCommon(const SelfString& s1, const SelfString& s2) {
    char* ptrS1[SelfString::MAXN], * ptrS2[SelfString::MAXN];    // 存储分割后的单词
    int cnt1, cnt2;                // 记录分割单词个数
    char* temPtr;
    char workS1[SelfString::MAXN] = { 0 };
    char workS2[SelfString::MAXN] = { 0 };
    strcpy(workS1, s1.dataStr);    // strtok会改变原始字符串，转存来给strtok函数使用
    strcpy(workS2, s2.dataStr);
    
    // 将两个字符串的单词分别分割出来
    cnt1 = 0;
    temPtr = strtok(workS1, " ");
    while (temPtr) {
        ptrS1[cnt1++] = temPtr;
        temPtr = strtok(nullptr, " ");
    }
    cnt2 = 0;
    temPtr = strtok(workS2, " ");
    while (temPtr) {
        ptrS2[cnt2++] = temPtr;
        temPtr = strtok(nullptr, " ");
    }
    size_t maxLen = 0;        // 最长公共字符串长度
    temPtr = nullptr;
    for (int i = 0; i < cnt1; ++i) {
        for (int j = 0; j < cnt2; ++j) {
            if (strcmp(ptrS1[i], ptrS2[j]) == 0) {    // 如果两个字符串相等
                if (maxLen < strlen(ptrS1[i])) {    // 更新最长公共字符串信息
                    maxLen = strlen(ptrS1[i]);
                    temPtr = ptrS1[i];
                }
            }
        }
    }
    
    if (temPtr)        // 如果找到需要的字符串，这里也有可能未找到，未找到则temPtr中为空，不能直接输出，需要判断分支
        cout << temPtr << " " << maxLen<<endl;
    else
        cout << "Not Fuound!"<<endl;
}
SelfString::SelfString(const char * const s){
    cout<<"正在执行构造函数..."<<endl;
    for(int i=0;s[i] != '\0';i++)
        Length= i+1;
    dataStr=new char[Length+1];
    for (unsigned short i = 0; i<Length; i++)
        dataStr[i] = s[i];
    dataStr[Length]='\0';
}
SelfString::~SelfString(){
    cout<<"正在执行析构函数..."<<endl;
    delete dataStr;
    Length=0;
}
int main(){
    SelfString str1("abcd ssylzhand some");
    SelfString str2("sjsjsjsj some skfk");
    findCommon(str1, str2);
}
