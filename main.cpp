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
    //个位数
    int number_0 = 0;
    //十位数
    int number10 = 0;

    char tempI = '0';
    char tempII = '0';

    for (int i=strI.length()-1;i>=0;i--) {
        //获取值
        tempI = strI[i];
        tempII = strII[i];
        //转化和
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


/*
 * 01223
 *  1223
 *
 * 60027
 * 22344
 *       1
 *    11
 *
 */
//-------------------------------------------------------------------------- 以上为大数加法


/**
 * 输入：
 * 1. 字符串类型的，数字格式的，字符串1
 * 2。字符串类型的，数字格式的，字符串2
 * 输出：
 * 3. int值
 * 函数功能
 * 比较俩个字符串的长短
 * 如果第一个字符串长，--> 返回1
 * 如果第二个字符串长，--> 返回-1
 * 如果一样长， --> 返回0
 * @param numberI
 * @param numberII
 * @return
 */
int Longer(string numberI, string numberII) {
    int lengthI = numberI.length();
    int lengthII = numberII.length();
    int returnKey = 2;
    if (lengthI > lengthII) {
        //第一个长
        returnKey = 1;
    } else if (lengthI < lengthII) {
        //第二个长
        returnKey = -1;
    } else if (lengthI == lengthII) {
        //一样长
        returnKey = 0;
    }
    return returnKey;
}

/**
 * 判断俩个字符的大小
 * 默认 第一个大
 * 第一个大 ： 1
 * 第二个大 ： -1
 * 一样大   ： 0
 * @param a
 * @param b
 * @return
 */
int big(char a, char b) {
    int returnKey = 1;
    int numberI = (int)(a - '0');
    int numberII = (int)(b - '0');
    if (numberI > numberII) {
        returnKey = 1;
    } else if (numberI < numberII) {
        returnKey = -1;
    } else if (numberI == numberII){
        returnKey = 0;
    }
    return returnKey;
}

/**
 * 判断（【俩个】（相同长度的）字符串的）大小
 * @param numberI
 * @param numberII
 * @return
 */
bool bigger(string numberI, string numberII) {
    bool returnKey = true;
    for (int i=0;i<numberI.length();i++) {
        char a = numberI[i];
        char b = numberII[i];
        //cout << a << " " << b << " : ";
        if (big(a, b) == 1) {
            //第一个字符串 大
            returnKey = true;
            break;
        } else if (big(a, b) == -1) {
            //第二个字符串 大
            returnKey = false;
            break;
        } else if (big(a, b) == 0){
            //一样大，继续判断次高位
            continue;
        }
    }
    return returnKey;
}

/**
 * 比较俩个数的大小
 * 参数：
 * 1。 字符串1
 * 2。 字符串2
 * 返回值：
 * bool型数据
 * 如果1大-> true
 * 如果2大-> false
 * @param numberI
 * @param numberII
 * @return
 */
bool whoseBigger(string numberI, string numberII) {
    //默认第一个比较大
    bool returnKey = true;
    // 1. 长短
    if(Longer(numberI, numberII) == 1) {
        //第一个长
        returnKey = true;
    } else if (Longer(numberI, numberII) == -1){
        //第二个长
        returnKey = false;
    } else if (Longer(numberI, numberII) == 0){
        //一样长
        // 2. 逐位比较
        returnKey = bigger(numberI, numberII);
    }
    return returnKey;
}

/**
 * 借位
 * 参数：
 * char 型数据*2
 *
 * @param a
 * @param b
 * @return
 */
int borrow(char a, char b) {
    int number = 0;
    int numberI = (int) (a - '0');
    int numberII = (int) (b - '0');
    if (numberI >= numberII) {
        number = 0;
    } else {
        number = 1;
    }
    return number;
}


/**
 * 计算减法的中间步骤
 * 计算俩个位数的差值
 * @param a
 * @param b
 * @return
 */
int sub(char a, char b) {
    int number = 0;
    int numberI = (int) (a - '0');
    int numberII = (int) (b - '0');
    if (numberI >= numberII) {
        number = numberI - numberII;
    } else {
        number = numberI + 10 - numberII;
    }
    return number;
}


/**
 * 还上借位用去的数
 * @param number
 * @param borrow
 * @return
 */
char addsub(char number, int borrow) {
    int num = (int)(number - '0');
    num = num - borrow;
    char charNumber = (char)(num + '0');
    return charNumber;
}

/**
 * 返回一个字符串的逆序
 * @param str
 * @return
 */
string nverseString(string str) {
    string number = "";
    for (int i=str.length()-1;i>=0;i--) {
        number = number + str[i];
    }
    return number;
}

/**
 * 计算第一个大数减去第二个大数
 * @param numberI
 * @param numberII
 * @return
 */
string trueSubNumber(string numberI, string numberII) {
    string results ;
    int lengthI = numberI.length();
    int lengthII = numberII.length();
    //逆序
    numberI = nverseString(numberI);
    numberII = nverseString(numberII);
    //标志借位
    int tempNumber = 0;
    int temp = 0;
    for (int i=0;i<lengthII; i++) {
        char strI = numberI[i];
        char strII = numberII[i];
        //补上 上次 借位的数
        strI = addsub(strI, tempNumber);
        //本次 借位
        tempNumber = borrow(strI, strII);
        temp = sub(strI, strII);
        results = intToString(temp) + results;
    }
    return results;
}

//  234
//-  56
//-------
//  178

//  432
//- 650
//-------
//  871


// 8
// 78
// 178

/**
 * 补齐位数
 * @param numberI
 * @param numberII
 * @return
 */
string fillingString(string numberI, string numberII) {
    int longthI = numberI.length();
    int longthII = numberII.length();
    for (int i=0;i<longthI - longthII;i++) {
        numberII = "0" + numberII;
    }
    return numberII;
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
        //补齐计算
        numberII = fillingString(numberI, numberII);
        //计算
        results = trueSubNumber(numberI, numberII);
    } else {
        //补齐计算
        numberI = fillingString(numberII, numberI);
        //计算
        results = trueSubNumber(numberII, numberI);
        //负数
        results = "-" + results;
    }
    return results;
}

//---------------------------------------------以上为大数减法

/**
 * 返回字符的（所表示的）值
 * @param c
 * @return
 */
int charToInt(char c) {
    int number = (int) (c - '0');
    return number;
}



/**
 * 7 * 3 + 4
 * 被乘数 * 乘数 + 进位数
 * @param charI
 * @param charII
 * @return
 */
int getNumber_0I(char charI, int charII, int num) {
    int number = 0;
    int numberI = (int)(charI - '0');
    number = numberI * charII + num;
    //取余
    number = number % 10;
    return number;
}


/**
 * 获取进位数
 * @param charI
 * @param charII
 * @return
 */
int getNumber10I(char charI, int charII, int num) {
    int number = 0;
    int numberI = (int)(charI - '0');
    number = numberI * charII + num;
    //取倍数
    number = number / 10;
    return number;
}

/**
 * 函数功能
 * 123456789 * 3
 * @param numberI
 * @param number
 * @return
 */
string temp01multiplication(string numberI, int number) {
    string results;
    //进位数
    int num = 0;
    //逆序数
    numberI = nverseString(numberI);
    //987654321
    for (int i=0;i<numberI.length();i++) {
        char c = numberI[i];
        //结果
        int temp = getNumber_0I(c, number, num);
        //进位数
        num = getNumber10I(c, number, num);

        results = intToString(temp) + results;
    }
    return results;
}

/**
 * 大数乘法
 * @param numberI
 * @param numberII
 * @return
 */
string multiplication(string numberI, string numberII) {
    string results = "0";

    string tempNumber;

    //剥离位数
    for(int i=0;i<numberII.length();i++) {
        char charNumber = numberII[i];
        int number = charToInt(charNumber);
        tempNumber = temp01multiplication(numberI, number);
        for (int j=0;j<i;j++) {
            tempNumber = tempNumber + "0";
        }
        //cout << tempNumber << endl;
        results = addNumber(results, tempNumber);
    }
    return results;
}


// 123456789
// *   45678
//------------

void paluy() {
    int n = 0;
    cin >> n;
    while(n--) {
        int number[1000];
        for (int i=0;i<1000;i++) {
            number[i] = -1;
        }
        int num = 0;
        int sum = 0;
        cin >> num;
        for (int i=0;i<num;i++) {
            int t= 0;
            cin >> t;
            number[t] = t;
        }
        for (int i=0;i<1000;i++) {
            if (number[i] != -1) {
                sum = sum + 1;
            }
        }
        cout << sum << endl;
        for (int i=0;i<1000;i++) {
            if (number[i] != -1) {
                cout << number[i] << " ";
            }
        }
        for (int i=0;i<1000;i++) {
            number[i] = -1;
        }
    }
}



int getString3(double number) {
    number = number * 100;

    int a = (int)number % 100;

    //cout << a << endl;

    return a;

}

int getString2(double number) {
    double a = (int)number % 1;
    a = number - a;
    return a;
}

int addSomething(int a) {
    int key = 0;
    if (a >0 && a < 10) {
        key = 1;
    } else if (a == 0) {
        key = -1;
    }
    return key;
}

string sun0(string a) {
    string s = "";
    while(a[0] != '0') {
        for (int i=1;i<a.length();i++) {
            s = s + a[i];
        }
        a = s;
    }
    s = a;
    return s;
}

int bbb(char a, char b) {
    int key = false;
    if (a > b) {
        key = 1;
    } else if (a < b) {
        key = -1;
    } else if (a == b){
        key = 0;
    }
    return key;
}


bool wbig(string a, string b) {
    bool key = false;
    int numberI = a.length();
    int numberII = b.length();
    if (numberI > numberII) {
        for (int i=0;i<numberI ; i++) {
            char aa = a[i];
            char bb = b[i];
            int key1 = bbb(aa, bb);
            if (key1 == 1) {
                key = true;
                break;
            } else if (key1 == -1){
                key = false;
                break;
            } else if (key1 == 0) {
                continue;
            }
        }
    } else {
        for (int i=0;i<numberII ;i++) {
            char aa = a[i];
            char bb = b[i];
            int key1 = bbb(aa, bb);
            if (key1 == 1) {
                key = true;
                break;
            } else if (key1 == -1){
                key = false;
                break;
            } else if (key1 == 0) {
                continue;
            }
        }
    }
    return key;
}


int findP(string n) {
    bool key = false;
    int m=0;
    for (int i=0;i<n.length();i++) {
        if (key == true) {
            m = m + 1;
        }
        if (n[i] == '.') {
            key = true;
        }
    }
    return m;
}


string sunP(string n) {
    string s = "";
    for (int i=0;i<n.length();i++) {
        if (n[i] != '.') {
            s = s + n[i];
        }
    }
    return s;
}

string subaaa(string str, int a) {
    int l = str.length();
    int num = l - a;
    string string1 = "";
    for (int i=0;i<str.length();i++) {
        if (i == num) {
            string1 = string1 + ".";
        }
        string1 = string1 + str[i];
    }
    return string1;
}

string sss(string string1) {
    bool key = true;
    string s = "";
    for (int i=0;i<string1.length();i++) {
        if (string1[i] != '0') {
            key = false;
        }

        if (key == false) {
            s = s + string1[i];
        }
    }
    return s;
}


/**
 * 主函数
 * @return
 */
int main() {

    index02();


    return 0;
}








/*
double number1[12];

while(cin >> number1[0]) {
for (int i=1;i<12;i++) {
cin >> number1[i];
}

double sum = 0;

for (int i=0;i<12;i++) {
sum = sum + number1[i];
}
sum = sum /12;
*/

//cout << "$" << getString2(sum) << "." << getString3(sum) << endl;

/*//cout << sum << endl;
int key = addSomething(getString3(sum));
if (key == 1) {
    cout << "$" << getString2(sum) << "." << getString3(sum) << "0" << endl;
} else if (key == -1) {
    cout << "$" << getString2(sum) << "." << " 00" << endl;
}else if (key == 0){
    cout << "$" << getString2(sum) << "." << getString3(sum) << endl;
}*/

//cout << sum << endl;
/*
int key = addSomething(getString3(sum));
if (key == 1) {
cout << "$" << getString2(sum) << "." << getString3(sum) << endl;
} else if (key == -1) {
cout << "$" << getString2(sum) << endl;
}else if (key == 0){
cout << "$" << getString2(sum) << "." << getString3(sum) << endl;
}

}
*/

