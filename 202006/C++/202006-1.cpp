
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> Pair;
vector<Pair> A, B;// 存放不同类别的点
int N, M; //点的个数，查询的个数
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		LL x, y;
		char c;
		scanf("%lld %lld %c", &x, &y, &c);
		if (c == 'A')
			A.push_back(Pair(x, y));
		else
			B.push_back(Pair(x, y));
	}
	for (int i = 1; i <= M; i++)
	{
		LL a, b, c; // 分别代表直线的三个参数
		scanf("%lld %lld %lld", &a, &b, &c);
		bool flag = true;
		LL dis_flag = 0;
		if (A.size())
			dis_flag = a + b * A[0].first + c * A[0].second;
		for (int j = 1; j < A.size() && flag; j++)
		{
			LL dis = a + b * A[j].first + c * A[j].second;
			if ((dis_flag < 0 && dis > 0) || (dis_flag > 0 && dis < 0))
				flag = false;
		}
		if (A.size() && flag)
			dis_flag = a + b * B[0].first + c * B[0].second;
		for (int j = 1; j < B.size() && flag; j++)
		{
			LL dis = a + b * B[j].first + c * B[j].second;
			if ((dis_flag < 0 && dis > 0) || (dis_flag > 0 && dis < 0))
				flag = false;
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
*/
