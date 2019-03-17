/*
样例输入：
3
abc 20 99
bcd 19 97
bed 20 97

样例输出：
bcd 19 97
bed 20 97
abc 20 99
*/

#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 1005
int n;
struct Student {
  char name[105];
  int age;
  int score;
  bool operator<(const Student &b) const {
    if (score != b.score)
      return score < b.score;
    int t = strcmp(name, b.name);
    if (t != 0)
      return t < 0;
    return age < b.age;
  }
} students[MAXN];

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> students[i].name >> students[i].age >> students[i].score;
    }
    sort(students, students + n);
    for (int i = 0; i < n; i++) {
      cout << students[i].name << " " << students[i].age << " "
           << students[i].score << endl;
    }
  }
  return 0;
}
