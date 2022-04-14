#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>

using namespace std;

// Disjoint set union

vll parent(2e5 + 1);
vll siz(2e5 + 1);

int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);

}

void make_set(int n)
{
    For(i, 1, n + 1)
    {
        parent[i] = i;
        siz[i] = 1;

    }

}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);

        parent[b] = a;
        siz[a] += siz[b];

    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    return 0;
}
