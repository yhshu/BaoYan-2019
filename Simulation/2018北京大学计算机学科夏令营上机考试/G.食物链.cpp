//
// Created by syh on 19-3-18.
//

/*
 * G:食物链
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是"1 X Y"，表示X和Y是同类。
第二种说法是"2 X Y"，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1）	当前的话与前面的某些真的话冲突，就是假话；
2）	当前的话中X或Y比N大，就是假话；
3）	当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。
输入
第一行是两个整数N和K，以一个空格分隔。
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。
输出
只有一个整数，表示假话的数目。
样例输入
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
样例输出
3
来源
Noi 01
 */

// 本题考察并查集

#include <iostream>

using namespace std;

const int minSum = 50010 * 3; // 三类动物分别存储
int N, K;
int cnt; // 假话计数
int F[minSum];

/**
 * 并查集中查找类别
 * @param x 待查找的类
 * @return 父类别
 */
int find(int x) {
    int a = x;
    while (x != F[x]) {
        x = F[x];
    }
    // 路径压缩
    while (a != x) {
        int z = a;
        F[a] = x;
        a = F[z];
    }
    return x;
}

/**
 *
 * 合并两类别
 * @param x 类别1
 * @param y 类别2
 */
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        F[fx] = fy;
    }
}

int main() {
    cin >> N >> K;
    int op, X, Y;
    for (int i = 0; i <= 3 * N; i++) { // 并查集初始化
        F[i] = i;
    }

    for (int i = 0; i < K; i++) { // K 句话
        cin >> op >> X >> Y;
        if (X < 0 || X > N || Y < 0 || Y > N) {
            cnt++;
            continue;
        }
        if (op == 1) { // X 和 Y 是同类
            if (find(X) == find(Y + N) || find(X) == find(Y + 2 * N)) // 假话
                cnt++;
            else { // 认为真话
                unite(X, Y);
                unite(X + N, Y + N);
                unite(X + 2 * N, Y + 2 * N);
            }
        } else if (op == 2) { // X 吃 Y
            if (find(X) == find(Y) || find(X) == find(Y + 2 * N)) // 假话
                cnt++;
            else { // 认为真话
                unite(X, Y + N);
                unite(X + N, Y + 2 * N);
                unite(X + 2 * N, Y);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}