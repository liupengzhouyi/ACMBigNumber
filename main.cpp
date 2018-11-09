#include <iostream>
#include <string.h>
#include <string>
using namespace std;

/**
 * 输入：
 * 1. 字符串类型的，数字格式的，字符串1
 * 2。字符串类型的，数字格式的，字符串2
 * 输出：
 * 3. bool值
 * 函数功能
 * 比较俩个字符串的长短
 * 如果第一个字符串长，--> 返回true
 * 如果第二个字符串长，--> 返回false
 * @param numberI
 * @param numberII
 * @return
 */
bool whoseLonger(string numberI, string numberII) {
    int longthI = numberI.length();
    int longthII = numberII.length();
    bool returnKey = false;
    if (longthI >= longthII) {
        returnKey = true;
    } else {
        returnKey = false;
    }
    return returnKey;
}

int number(string numberI, string numberII) {

}

string returnNumberI() {

}

string returnNumberII() {

}

/**
 * 计算俩个大数的和
 * 输入：
 * 1. 字符串类型的，数字格式的，字符串1
 * 2。字符串类型的，数字格式的，字符串2
 * 输出：
 * 3. 字符串类型的，数字格式的，字符串3
 * 功能：
 * 计算这俩个数的和
 * @param numberI
 * @param numberII
 * @return
 */
string addNumber(string numberI, string numberII) {
    string results = "";
    //1 比较长短
    bool key = whoseLonger(numberI, numberII);
    //2 补齐 计算， 页可以不补齐

    //3 for 循环里 计算


    //转化结果

    //返回
    return results;
}

/**
 * 主函数
 * @return
 */
int main() {

    //定义数据类型
    string numberI = "";
    string numberII = "";
    string results = "0";
    //数据输入
    cin >> numberI;
    cin >> numberII;
    //操作数据
    results = addNumber(numberI, numberII);
    //显示操作结果
    cout << results << endl;
    return 0;
}

