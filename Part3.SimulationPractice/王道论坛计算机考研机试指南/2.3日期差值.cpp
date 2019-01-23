/*
样例输入：
20110412
20110422

样例输出：
11
*/

#include <iostream>
#define ISYEAP(x) (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) ? 1 : 0
using namespace std;

int buf[5001][13][32];
int dayOfMonth[13][2] = {0,  0,  31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30,
                         30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31};

struct Date {
  int day;
  int month;
  int year;
  void nextDay() {
    day++;
    if (day > dayOfMonth[month][ISYEAP(year)]) {
      day = 1;
      month++;
      if (month > 12) {
        month = 1;
        year++;
      }
    }
  }
};

int main() {
  Date date;
  int cnt = 0;
  date.day = 1;
  date.month = 1;
  date.year = 0;
  while (date.year != 5001) {
    buf[date.year][date.month][date.day] = cnt;
    date.nextDay();
    cnt++;
  }
  int y1, y2, m1, m2, d1, d2;
  while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
    scanf("%4d%2d%2d", &y2, &m2, &d2);
    cout << abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1 << endl;
  }
  return 0;
}
