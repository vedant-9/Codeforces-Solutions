// Author - Vedant Valsangkar
// BELIEVE
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long
#define rep(i, s, e) for (int i = s; i < e; i++)
#define repr(i, s, e) for (int i = s; i >= e; i--)
#define uniq(a) a.erase(unique(all(a)), a.end())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define endl '\n'

template <typename T>
istream& operator>>(istream& istream, vector<T>& v) {
    for (auto& it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream& operator<<(ostream& ostream, const vector<T>& c) {
    for (auto& it : c)
        cout << it << " ";
    return ostream;
}

bool per_square(ld x) {
    if (x < 0) return 0;
    ll sr = sqrt(x);
    return (sr * sr == x);
}
bool is_prime(ll x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

template <typename T>
class SegmentTree {
   private:
    int n;
    vector<T> arr;
    vector<T> segment_tree;
    vector<T> lazy;

    void build_segment_tree(int node, int start, int end) {
        if (start == end) {
            segment_tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build_segment_tree(2 * node + 1, start, mid);
        build_segment_tree(2 * node + 2, mid + 1, end);
        segment_tree[node] = (segment_tree[2 * node + 1] & segment_tree[2 * node + 2]);
    }

    void update_point(int node, int start, int end, int index, T value) {
        if (start == end) {
            arr[index] = value;
            segment_tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update_point(2 * node + 1, start, mid, index, value);
        } else {
            update_point(2 * node + 2, mid + 1, end, index, value);
        }

        segment_tree[node] = (segment_tree[2 * node + 1] & segment_tree[2 * node + 2]);
    }

    void update_range(int node, int start, int end, int left, int right, T value) {
        if (lazy[node] != 0) {
            segment_tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left) {
            return;
        }

        if (left <= start && end <= right) {
            segment_tree[node] += (end - start + 1) * value;

            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }

            return;
        }

        int mid = (start + end) / 2;
        update_range(2 * node + 1, start, mid, left, right, value);
        update_range(2 * node + 2, mid + 1, end, left, right, value);
        segment_tree[node] = segment_tree[2 * node + 1] + segment_tree[2 * node + 2];
    }

    T query_segment_tree(int node, int start, int end, int left, int right) {
        if (lazy[node] != 0) {
            segment_tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left) {
            return (1LL << 32) - 1;  // For range sum, change this to 0 for other queries
        }

        if (left <= start && end <= right) {
            return segment_tree[node];
        }

        int mid = (start + end) / 2;
        T left_sum = query_segment_tree(2 * node + 1, start, mid, left, right);
        T right_sum = query_segment_tree(2 * node + 2, mid + 1, end, left, right);
        return left_sum & right_sum;
    }

   public:
    SegmentTree(const vector<T>& input_arr) {
        arr = input_arr;
        n = arr.size();
        segment_tree.resize(4 * n, 0);  // Adjust size based on the maximum number of elements
        lazy.resize(4 * n, 0);
        build_segment_tree(0, 0, n - 1);
    }

    void update_point(int index, T value) {
        update_point(0, 0, n - 1, index, value);
    }

    void update_range(int left, int right, T value) {
        update_range(0, 0, n - 1, left, right, value);
    }

    T query(int left, int right) {
        return query_segment_tree(0, 0, n - 1, left, right);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    SegmentTree<int> st(a);
    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;
        int low = l, high = n - 1, ans = -2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (st.query(l, mid) >= k)
                ans = max(ans, mid), low = mid + 1;
            else
                high = mid - 1;
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
