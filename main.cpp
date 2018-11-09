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

/**
 * 返回俩个字符串的长度的差值
 * @param numberI
 * @param numberII
 * @return
 */
int number(string numberI, string numberII) {
    int number = -1;
    bool key = whoseLonger(numberI, numberII);
    if (key) {
        number = numberI.length() - numberII.length();
    } else {
        number = numberII.length() - numberI.length();
    }
    return number;
}

/**
 * 为一个数字类型的字符串 补充 '0'
 * @param number
 * @param num
 * @return
 */
string returnNumber(string number, int num) {
    string numberStr = number;
    for (int i=0;i<num;i++) {
        numberStr = "0" + numberStr;
    }
    return numberStr;
}

/**
 * 获取俩个小于10的char型的数的和的余数
 * @param charI
 * @param charII
 * @return
 */
int getNumber_0(char charI, char charII, int num) {
    int number = 0;
    int numberI = (int)(charI - '0');
    int numberII = (int)(charII - '0');
    number = numberI + numberII + num;
    //取余
    number = number % 10;
    return number;
}

/**
 * 获取俩个小于10的char型的数的和是10的几倍的整数
 * @param charI
 * @param charII
 * @return
 */
int getNumber10(char charI, char charII, int num) {
    int number = 0;
    int numberI = (int)(charI - '0');
    int numberII = (int)(charII - '0');
    number = numberI + numberII + num;
    //取倍数
    number = number / 10;
    return number;
}

/**
 * 将int行数据转化为string
 * @param num
 * @return
 */
string intToString(int num) {
    string number = "";
    number = (char) (num + '0');
    return number;
}

/**
 * 去掉字符串前面的0
 * @param number
 * @return
 */
string subzero(string number) {
    string str = "";
    if (number[0] == '0') {
        for (int i=1;i<number.length();i++) {
            str = str + number[i];
        }
    } else {
        str = number;
    }
    return str;
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
    string strI = "";
    string strII = "";
    // 补齐 计算， 页可以不补齐
    if(whoseLonger(numberI, numberII)) {
        //第一个字符串长
        strI = numberI;
        strII = returnNumber(numberII, number(numberI, numberII));
    } else {
        //第二个字符串长
        strI = returnNumber(numberI, number(numberI, numberII));
        strII = numberII;
    }
    // for 循环里 计算
    int number_0 = 0;
    int number10 = 0;
    char tempI = '0';
    char tempII = '0';
    for (int i=strI.length()-1;i>=0;i--) {
        tempI = strI[i];
        tempII = strII[i];
        number_0 = getNumber_0(tempI, tempII, number10);
        number10 = getNumber10(tempI, tempII, number10);
        results = intToString(number_0) + results;
    }
    results = intToString(number10) + results;
    //转化结果
    results = subzero(results);
    //返回
    return results;
}
//-------------------------------------------------------------------------- 以上为大数加法
/**
 * 比较来个数的大小
 * @param numberI
 * @param numberII
 * @return
 */
bool whoseBigger(string numberI, string numberII) {
    //默认第一个比较大
    bool returnKey = true;
    // 1. 长短
    // 2. 逐位比较
    //function()

    return returnKey;
}

/**
 * 计算第一个大数减去第二个大数
 * @param numberI
 * @param numberII
 * @return
 */
string trueSubNumber(string numberI, string numberII) {

}


/**
 * 计算俩个大数的差
 * @param numberI
 * @param numberII
 * @return
 */
string subNumber(string numberI, string numberII) {
    string results = "";
    //比较大小
    bool key = whoseBigger(numberI, numberII);
    //计算
    if (key) {
        results = trueSubNumber(numberI, numberII);
    } else {
        results = trueSubNumber(numberII, numberI);
    }
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

