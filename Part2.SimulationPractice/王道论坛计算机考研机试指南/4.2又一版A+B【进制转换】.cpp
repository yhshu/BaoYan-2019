#include <cstdio>
int main() {
  long long a, b; // 使用 long long 确保不会溢出
  int m;
  while (scanf("%d", &m) != EOF) {
    if (m == 0)
      break;
    scanf("%lld%lld", &a, &b);
    a = a + b; // 下面将 a 转换为 m 进制
    int ans[50],
        size =
            0; // ans 用于保存依次转换得到的各个数位数字的值， size 表示其个数
    do {       // 依次求得各个数位上的数字值
      ans[size++] = a % m;
      a /= m;
    } while (a != 0); // 当 a 不为 0 时重复
    for (int i = size - 1; i >= 0; i--) {
      printf("%d", ans[i]);
    }             // 输出，注意顺序为从高位到低位
    printf("\n"); // 输出换行
  }
  return 0;
}
