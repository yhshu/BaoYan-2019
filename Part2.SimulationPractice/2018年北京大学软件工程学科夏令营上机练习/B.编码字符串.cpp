/*
总时间限制: 1000ms 内存限制: 65536kB
描述
在数据压缩中，一个常用的方法是行程长度编码压缩。对于一个待压缩的字符串，我们可以依次记录每个字符及重复的次数。例如，待压缩的字符串为"aaabbbbcbb"，压缩结果为(a,3)(b,4)(c,1)(b,2)。这种压缩对于相邻数据重复较多的情况有效，如果重复状况较少，则压缩的效率较低。

现要求根据输入的字符串，首先将字符串中所有大写字母转化为小写字母，然后将字符串进行压缩。

输入
一个字符串，长度大于0，且不超过1000，全部由大写或小写字母组成。
输出
输出为编码之后的字符串，形式为：(a,3)(b,4)(c,1)(d,2)，即每对括号内分别为小写字符及重复的次数，不含任何空格。
样例输入
aAABBbBCCCaaaaa
样例输出
(a,3)(b,4)(c,3)(a,5)
来源
cs10116 final exam
*/
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      str[i] = str[i] + 'a' - 'A';
    }
  }
  int count = 1;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] == str[i - 1]) {
      count++;
    } else {
      cout << "(" << str[i - 1] << "," << count << ")";
      count = 1;
    }
  }
  cout << "(" << str[str.size() - 1] << "," << count << ")";
  return 0;
}
