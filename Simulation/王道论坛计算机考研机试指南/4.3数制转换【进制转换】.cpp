#include <cstdio>
#include <cstring>

// 超过十进制的进制转换问题，注意对数字和字母分别进行处理
// 将m进制转换为十进制，由各位数字或字母获取十进制数值，乘以对应权重
// 将十进制转换为n进制，不断对n取模并转换为数字或字母，再除以n

int main() {
    int a, b;
    char str[40];
    while (scanf("%d %s %d", &a, &str, &b) != EOF) {
        int tmp = 0;            // tmp是将要计算的a进制对应的十进制数；
        int len = strlen(str);  // len是字符串长度，便于从数字低位到高位遍历每个数位上的数；
        int c = 1;              // c为各个数位的权重，初始化为1，表示最低位数位权重为1，之后每位权重都是前一位权重的a倍
        for (int i = len - 1; i >= 0; i--) {
            int x;
            if (str[i] >= '0' && str[i] <= '9') {
                x = str[i] - '0'; // 计算其代表的数字
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                x = str[i] - 'a' + 10;
            } else {
                x = str[i] - 'A' + 10;
            }
            tmp += x * c;
            c *= a;
        }
        char ans[40], size = 0;
        do {
            int x = tmp % b; // 计算该位数字
            ans[size++] = (x < 10) ? (x + '0') : (x - 10 + 'A'); // 数字转换为字符
            tmp /= b;
        } while (tmp);
        for (int i = size - 1; i >= 0; i--) { // 注意遍历顺序
            printf("%c\n", ans[i]);
        }
    }
    return 0;
}
