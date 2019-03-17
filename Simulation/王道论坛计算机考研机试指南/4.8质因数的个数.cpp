#include <iostream>
#define MAXN 100010
using namespace std;

bool mark[MAXN]; // 合数为 true 
int prime[MAXN];
int primeSize;

void init() // 素数筛法：筛选出2到100000内的所有素数 
{
	primeSize = 0;
	for(int i = 2; i <= 100000; i++)
	{
		if(mark[i] == true) continue;
		prime[primeSize++] = i;
		if(i >= 1000) continue;
		for(int j = i * i; j <= 100000; j += i)
		{
			mark[j] = true;
		} 
	}
}

int main() 
{
	init();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ansPrime[30] = {}; // 按顺序保存分解出的质因数
		int ansSize = 0; // 分解出的质因数个数
		int ansNum[30] = {}; // 保存分解出的质因数对应的幂指数
		for(int i = 0; i < primeSize; i++) // 依次测试素数 
		{
			if(n % prime[i] == 0) // 若该素数能整除被分解数
			{
				ansPrime[ansSize] = prime[i];
				while(n % prime[i] == 0)
				{
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if(n == 1) // 被分解为1 
					break;
			} 
		} 
		if(n != 1) // 测试完从2到100000的所有质因数，仍未分解到1，则剩余的因数是n，它是大于100000的质因数 
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		} 
		
		int ans = 0;
		for(int i = 0; i < ansSize; i++)
		{
			ans += ansNum[i];
		}
		cout << ans << endl;
	} 
	return 0;
}
