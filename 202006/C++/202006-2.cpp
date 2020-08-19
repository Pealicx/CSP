/*
    类似二路归并的思想


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 15;
struct Node
{
    LL idx, val;
} va[maxn], vb[maxn];
int n, a, b;
int main ()
{
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= a; i++)
    {
        scanf("%lld %lld", &va[i].idx, &va[i].val);
    }
    for(int i = 1; i <= b; i++)
    {
        scanf("%lld %lld", &vb[i].idx, &vb[i].val);
    }
    int ida = 1, idb = 1;
    LL sum = 0;
    while(ida <= a && idb <= b)
    {
        if(va[ida].idx == vb[idb].idx)
        {
            sum += va[ida].val * vb[idb].val;
            ida++, idb++;
        }

        else if (va[ida].idx < vb[idb].idx)
            ida ++;
        else
            idb ++;
    }
    printf("%lld\n", sum);
    return 0;
}
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/
