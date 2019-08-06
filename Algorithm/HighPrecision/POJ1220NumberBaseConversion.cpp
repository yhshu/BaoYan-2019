// POJ 1220 number base conversion

// 进制转换的思路：将「源进制数」转换为「十进制数」，再将「十进制数」转换为「目标进制」数
// 注意输入和输出的形式是「字符串」，在进行数学运算时需要使用 int 型数组，它们存储数字的顺序不同

// 了解几个重要的 ASCII 码
// '0': 48
// 'A': 65
// 'a': 97

/*
Sample Input

8
62 2 abcdefghiz
10 16 1234567890123456789012345678901234567890
16 35 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 23 333YMHOUE8JPLT7OX6K9FYCQ8A
23 49 946B9AA02MI37E3D3MMJ4G7BL2F05
49 61 1VbDkSIMJL3JjRgAdlUfcaWj
61 5 dl9MDSWqwHjDnToKcsWE1S
5 10 42104444441001414401221302402201233340311104212022133030

Sample Output

62 abcdefghiz
2 11011100000100010111110010010110011111001001100011010010001

10 1234567890123456789012345678901234567890
16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2

16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 333YMHOUE8JPLT7OX6K9FYCQ8A

35 333YMHOUE8JPLT7OX6K9FYCQ8A
23 946B9AA02MI37E3D3MMJ4G7BL2F05

23 946B9AA02MI37E3D3MMJ4G7BL2F05
49 1VbDkSIMJL3JjRgAdlUfcaWj

49 1VbDkSIMJL3JjRgAdlUfcaWj
61 dl9MDSWqwHjDnToKcsWE1S

61 dl9MDSWqwHjDnToKcsWE1S
5 42104444441001414401221302402201233340311104212022133030

5 42104444441001414401221302402201233340311104212022133030
10 1234567890123456789012345678901234567890
 */

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1000;
int t[maxn];                 // 源进制数，每一位按十进制表示
int d[maxn];                 // 目标进制数，每一位按十进制表示
char str1[maxn], str2[maxn]; // 源进制数与目标进制数（数字、小写字母、大写字母）
int n, m;                    // 源进制与目标进制

/*
输入：
	n 源进制
	m 目标进制
	str1 源进制数
输出：
	str2 目标进制数
*/
void solve() {
    int i;
    int len1 = strlen(str1);
    int len2 = 0;

    // str1 到 t 数组
    for (i = len1 - 1; i >= 0; i--) {       // t[0] 是 t 最低位，str1[0] 是 str1 的最高位
        int cur;
        if (str1[i] <= '9')                 // str1[i] 是数字
            cur = str1[i] - '0';
        else if (str1[i] < 'a')             // str1[i] 是大写字母
            cur = str1[i] - 'A' + 10;
        else                                // str1[i] 是小写字母
            cur = str1[i] - 'a' + 36;
        t[len1 - 1 - i] = cur;              // 倒序存储
    }

    // 通过十进制计算，将源进制数转换为目标进制数
    while (len1) {
        for (i = len1 - 1; i >= 0; --i) {   // 从 t 高位开始
            t[i] += t[i + 1] % m * n;       // 高一位 模目标进制 乘源进制
            t[i + 1] /= m;
        }
        d[len2++] = t[0] % m;               // 数组 t 作为整体表示一个数，除法和取余针对 t[0]
        t[0] /= m;
        while (len1 > 0 && !t[len1 - 1])    // 去除前导 0，直到 len1 减为 0
            len1--;
    }

    // d 数组到 str2
    str2[len2] = '\0';
    for (i = 0; i < len2; i++) {             // str2[0] 是 str2 的最高位，循环从低位开始
        char cur;
        if (d[i] < 10)                       // 将以数字表示
            cur = (char) (d[i] + '0');
        else if (d[i] < 36)                  // 将以大写字母表示
            cur = (char) (d[i] - 10 + 'A');
        else                                 // 将以小写字母表示
            cur = (char) (d[i] - 36 + 'a');
        str2[len2 - 1 - i] = cur;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> str1;               // 源进制，目标进制，源进制数字
        solve();                             // 进制转换
        cout << n << " " << str1 << '\n' << m << " " << str2 << '\n' << '\n';
    }
    return 0;
}