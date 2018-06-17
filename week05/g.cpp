#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <unsigned long long> tree (4 * (1e6+1));
vector <unsigned long long> A (3 * (1e5+1));
vector <unsigned long long> lazy (4 * (1e6+1));

void updateRange(unsigned long long node, unsigned long long start,
    unsigned long long end, unsigned long long l, unsigned long long r,
    unsigned long long val) {
    if(lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r) {
        tree[node] += (end - start + 1) * val;
        if(start != end) {
            lazy[node << 1] += val;
            lazy[(node << 1) + 1] += val;
        }
        return;
    }
    unsigned long long mid = (start + end) / 2;
    updateRange(node << 1, start, mid, l, r, val);
    updateRange((node << 1) + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

unsigned long long queryRange(unsigned long long node, unsigned long long start,
                                unsigned long long end, unsigned long long l,
                                unsigned long long r) {
    if((start > end) || (start > r) || (end < l))
        return 0;
    if(lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    unsigned long long mid = (start + end) / 2;
    unsigned long long p1 = queryRange(node << 1, start, mid, l, r);
    unsigned long long p2 = queryRange((node << 1) + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main() {
    unsigned long long t;
    cin >> t;

    unsigned long long action, p, q, v;
    unsigned long long v_size, n_commands;
    while (t--) {
        scanf("%llu %llu", &v_size, &n_commands);

        for (unsigned long long i = 1; i < v_size + 2; i++) {
            A[i] = 0;
        }
        for (unsigned long long i = 0; i < (v_size << 2) + 1; i++) {
            tree[i] = 0;
            lazy[i] = 0;
        }

        while (n_commands--) {

            scanf("%llu %llu %llu", &action, &p, &q);

            if (action == 0) {
                scanf("%llu", &v);

                updateRange(1, 1, v_size, p, q, v);
            }
            else {
                cout << queryRange(1, 1, v_size, p, q) << endl;
            }
        }
    }

    return 0;
}