/*
样例输入：
9 October 2001
14 October 2001

样例输出：
Tuesday
Sunday
*/

#include <iostream>
#include <string.h>
#define ISYEAP(x) (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) ? 1 : 0

using namespace std;

int dayOfMonth[13][2] = {0,  0,  31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30,
                         30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31};
char weekName[7][20] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                        "Thursday", "Friday", "Saturday"};
char MonthName[12][20] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};

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
int buf[3001][13][32];

int main() {
  Date date;
  date.year = 0;
  date.month = date.day = 1;
  int cnt = 0;
  while (date.year != 3001) {
    buf[date.year][date.month][date.day] = cnt;
    date.nextDay();
    cnt++;
  }
  int y, m, d;
  char month[20];

  while (cin >> d >> month >> y) {
    for (int i = 0; i < 12; i++) {
      if (strcmp(month, MonthName[i]) == 0) {
        m = i + 1;
        break;
      }
    }
    // 2019 年 6 月 2 日 星期日
    cout << weekName[((buf[y][m][d] - buf[2019][6][2]) % 7 + 7) % 7]
         << endl; // 注意被减数与减数是什么，减法可能得到负数
    memset(month, 0, sizeof(month));
  }

  return 0;
}
