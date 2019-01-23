/*
样例输入：
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03

样例输出：
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19
*/

#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int n, m;
#define MAXN 1010
#define MAXM 10010

struct Student {
  char ID[10];
  char name[50];
  char sex[10];
  int age;
  bool operator<(const Student &b) const { return strcmp(this->ID, b.ID) < 0; }
} students[MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> students[i].ID >> students[i].name >> students[i].sex >>
        students[i].age;
  }
  sort(students, students + n);

  cin >> m;
  char ID[10];
  for (int i = 0; i < m; i++) {
    cin >> ID;
    int low = 0, high = n - 1;
    int mid = (n - 1) / 2;
    while (low <= high) {
      mid = (low + high) / 2;
      int tmp = strcmp(ID, students[mid].ID);
      if (tmp < 0) {
        high = mid - 1; // 不要遗漏 -1
        continue;
      } else if (tmp > 0) {
        low = mid + 1; // 不要遗漏 +1
        continue;
      } else
        break;
    }
    cout << students[mid].ID << " " << students[mid].name << " "
         << students[mid].sex << " " << students[mid].age << endl;
  }
  return 0;
}
