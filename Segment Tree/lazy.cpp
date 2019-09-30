// Segment Tree with Lazy Propagation
// Author: ashishkr23438

int tree[4*N], lazy[4*N];

void update(int n, int s, int e, int l, int r, int v) {
	if (lazy[n]) {
		tree[n] += (e - s + 1) * lazy[n];
		if (s != e) {
			lazy[n*2] += lazy[n];
			lazy[n*2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (s > e || e < l || s > r) return;
	if (s >= l && e <= r) {
		tree[n] += (e - s + 1) * v;
		if (s != e) {
			lazy[2*n] += v;
			lazy[2*n+1] += v;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, l, r, v);
	update(n * 2 + 1, mid + 1, e, l, r, v);
	tree[n] = tree[n*2] + tree[n*2 + 1];
}

int query(int n, int s, int e, int l, int r) {
	if (lazy[n]) {
		tree[n] += (e - s + 1) * lazy[n];
		if (s != e) {
			lazy[2*n] += lazy[n];
			lazy[2*n+1] += lazy[n];
		}
		lazy[n] = 0;
	}
	if (e < s || l > e || s > r) return 0;
	if (s >= l && e <= r)
		return tree[n];
	int mid = (s + e) / 2;
	return query(n * 2, s, mid, l, r) + query(n * 2 + 1, mid + 1, e, l, r);
}
