#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<ctime>
#include<algorithm>

using namespace std;

#define MAX 100010

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

typedef long long int ll;


ll A[MAX];
ll c[MAX];
ll d[MAX];



//求最小幂
int Lowbit(int t)
{
	return t&(-t);
}


//求和
ll getSum(int n)
{
	ll sum = 0;
	while (n>0)
	{
		sum += c[n];
		n -= Lowbit(n);
	}
	return sum;
}

//求和
ll getSumD(int n)
{
	ll sum = 0;
	while (n>0)
	{
		sum += d[n];
		n -= Lowbit(n);
	}
	return sum;
}


//更新
void Change(int i, int v, int n)
{
	while (i <= n)
	{
		c[i] += 1;
		d[i] += v;
		i += Lowbit(i);
	}
}

int main()
{
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	int n;
	while (scanf("%d", &n) != EOF)
	{
		ll ans = 0;
		ll sum = 0;
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
			Change(A[i], A[i], n);
			sum += A[i];
			ans += ((i - getSum(A[i]))*A[i]);
			ans += (sum - getSumD(A[i]));
		}
		printf("%I64d\n", ans);
	}
#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
