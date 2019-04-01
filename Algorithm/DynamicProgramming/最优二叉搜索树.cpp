//
// Created by syh on 19-4-1.
//

// 算法导论第三版 229 页有伪代码

/*
5
0.15 0.10 0.05 0.10 0.20
0.05 0.10 0.05 0.05 0.05 0.10
*/

#include <bits/stdc++.h>

using namespace std;

const double inf = 0x3f3f3f3f;

/**
 * 最优二叉搜索树
 * @param p 关键字的概率列表，p1到pn
 * @param q 伪关键字的概率列表，q0到qn
 * @param n 规模
 */
void optimalBST(vector<double> &p, vector<double> &q, int n, vector<vector<double> > &w, vector<vector<double> > &e,
                vector<vector<int> > &root) {
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            e[i][j] = inf;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                // e[i][j] = min(e[i][j], e[i][r - 1] + e[r + 1][j] + w[i][j])
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    vector<vector<double> > w(n + 2,
                              vector<double>(n + 1)); // Probability sum of in-interval keywords and pseudo-keywords
    vector<vector<double> > e(n + 2, vector<double>(n + 1)); // Expected value of search cost
    vector<vector<int> > root(n + 1, vector<int>(n + 1)); // the root of optimal binary search tree

    vector<double> p; // Keyword probability0.
    vector<double> q; // Pseudo keyword probability
    p.push_back(0);
    for (int i = 0; i < n; i++) {
        double t;
        cin >> t;
        p.push_back(t);
    }
    for (int i = 0; i <= n; i++) {
        double t;
        cin >> t;
        q.push_back(t);
    }

    optimalBST(p, q, n, w, e, root);

    cout << "root" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << root[i][j] << "\t\t";
        }
        cout << endl;
    }

    cout << "w" << endl;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << w[i][j] << "\t\t";
        }
        cout << endl;
    }

    cout << "e" << endl;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << e[i][j] << "\t\t";
        }
        cout << endl;
    }
    return 0;
}
