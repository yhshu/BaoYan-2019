//
// Created by Yiheng Shu on 2019/8/31.
//

#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 510;
const int inf = 0x3f3f3f3f;

struct station {
    double dis;
    double price;
} st[maxn];

bool disCmp(station a, station b) {
    return a.dis < b.dis;
}

int main() {
    double Cmax, D, Davg;  // 最大容量，行驶距离，每单元汽油行驶距离
    int n;                 // 加油站数量
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }

    st[n].dis = D;          // 虚拟终点为最后一站
    st[n].price = 0;        // 最后一站无需价格
    sort(st, st + n, disCmp);
    if (st[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int curSt = 0;               // 当前的加油站
    double cost = 0;             // 总花费
    double curTank = 0;          // 当前油箱余量
    double maxDis = Cmax * Davg; // 最大行驶距离

    while (curSt < n) {
        // 先查找下一个可达范围内的合适的加油站
        int nextSt = -1;
        double minPrice = inf;
        for (int i = curSt + 1; i <= n && st[i].dis - st[curSt].dis <= maxDis; i++) {
            if (st[i].price < minPrice) {
                minPrice = st[i].price;
                nextSt = i;
                if (st[i].price < st[curSt].price) {
                    // 如果该加油站油价小于当前加油站油价，不再继续查找后面的加油站，到达这个更便宜的加油站后可能有更好的选择
                    break;
                }
            }
        }
        if (nextSt == -1) // 没有找到合适的下一个加油站，即可达范围内的更便宜的加油站
            break;

        // 找到了下一个可达范围内的更便宜的加油站
        double tankCost = (st[nextSt].dis - st[curSt].dis) / Davg; // 到下一站所需油量
        if (minPrice < st[curSt].price) {   // 如果到下一站加油是比当前加油更好的选择
            if (curTank < tankCost) {       // 如果当前油量不支持到达下一站
                // 油箱加到可以到达下一站的位置
                cost += (tankCost - curTank) * st[curSt].price;
                curTank = 0;
            } else {                        // 如果当前油量支持到达下一站
                curTank -= tankCost;        // 扣除油量
            }
        } else {                            // 如果下一站加油比当前站加油更贵，在当前站加满
            cost += (Cmax - curTank) * st[curSt].price;
            curTank = Cmax - tankCost;
        }
        curSt = nextSt;
    }

    if (curSt == n) {
        printf("%.2f\n", cost);
    } else {
        printf("The maximum travel distance = %.2f\n", st[curSt].dis + maxDis);  // 最远距离是在当前站加满油，走到耗尽为止
    }

    return 0;
}