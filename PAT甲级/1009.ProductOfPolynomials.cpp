//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:

3 3 3.6 2 6.0 1 1.6
 */

#include <iostream>
#include <vector>

using namespace std;

class Term {
public:
    int exp;
    double coef;

    Term(int exp, double coef) : exp(exp), coef(coef) {}
};

int k;
int exp;
double coef;
vector<Term> poly1;
vector<Term> poly2;
const int maxn = 2010;
double res[maxn];

void input() {
    for (int line = 0; line < 2; line++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> exp >> coef;
            if (line == 0)
                poly1.push_back(Term(exp, coef));
            else if (line == 1)
                poly2.push_back(Term(exp, coef));
        }
    }
}

/**
 * 两个多项式相乘
 */
void solve() {
    for (int i = 0; i < poly1.size(); i++) {
        for (int j = 0; j < poly2.size(); j++) {
            // 指数相加，系数相乘
            int newExp = poly1[i].exp + poly2[j].exp;
            double newCoef = poly1[i].coef * poly2[j].coef;
            res[newExp] += newCoef;
        }
    }
}

/**
 * 输出结果多项式
 */
void output() {
    int cnt = 0;
    for (int i = maxn - 1; i >= 0; i--) {
        if (res[i]) {
            cnt++;
        }
    }
    cout << cnt;

    if (!cnt) return;
    for (int i = maxn - 1; i >= 0; i--) {
        if (res[i]) {
            printf(" %d %.1f", i, res[i]);
        }
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}