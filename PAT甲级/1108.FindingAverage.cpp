//
// Created by Yiheng Shu on 2019/9/7.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

bool judge(char in[], char out[], int len) {
    for (int i = 0; i < len; i++) {
        if (in[i] != out[i]) return false;
    }
    return true;
}

bool judge(double num) {
    if (num > 1000 || num < -1000) return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int numCnt = 0;
    double numSum = 0.0;
    double num;
    char in[100] = {};
    char out[100] = {};

    for (int i = 0; i < n; i++) {
        scanf("%s", in);
        sscanf(in, "%lf", &num);     // 从字符串 in 输入到变量 num
        sprintf(out, "%.2lf", num);  // 从变量 num 输出到字符串 out
        if (judge(in, out, strlen(in)) && judge(num)) {
            numCnt++;
            numSum += num;
        } else {
            printf("ERROR: %s is not a legal number\n", in);
        }
    }

    if (!numCnt) printf("The average of 0 numbers is Undefined");
    else if (numCnt == 1) printf("The average of 1 number is %.2f", numSum);
    else printf("The average of %d numbers is %.2f", numCnt, numSum / numCnt);
    return 0;
}
