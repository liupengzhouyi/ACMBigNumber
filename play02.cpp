//
// Created by 刘鹏 on 2018/12/5.
//
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void paly2(int numbers[][2], int number, string bangform, string bangtemp, string bangend) {
    if (number == 1) {
        cout << "从" << bangform << "移动到" << bangend << endl;
    } else {
        paly2(numbers, number-1, bangform, bangend, bangtemp);
        paly2(numbers, 1, bangform, bangtemp, bangend);
        paly2(numbers, number-1, bangtemp, bangform, bangend);

    }
}

void index02(){
    int number  = 0;
    cin >> number;
    int numbers[100][2];
    for (int i=1;i<=number;i++) {
        numbers[i][0] = i;
        numbers[i][1] = number - i + 1;
    }
    paly2(numbers, number, "第一根棒子", "第二根棒子", "第三根棒子");
}
