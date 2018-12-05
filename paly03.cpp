//
// Created by 刘鹏 on 2018/12/5.
//

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int paly3(int number) {
    int count = 0;
    int list[10] = {1, 3, 4, 5, 6, 8, 12, 35, 43, 56};
    for (int i=0;i<10;i++) {
        if (list[i] <= number) {
            count = count + 1;
        } else {
            return count;
        }
    }
    return count;
}

void index03() {
    int number  = 0;
    cin >> number;
    int count = 0;
    count = paly3(number);
    cout << number << "元素在该序列中在第" << count << "位！" << endl;
}

