#include <bits/stdc++.h>
using namespace std;

#define tourist ios::sync_with_stdio(false); cin.tie(nullptr)

#define ll long long
#define ull unsigned long long
#define ld long double

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)

#define pb push_back
#define eb emplace_back
#define chris return 0

#define fi first
#define se second

const ll MOD = 998244353;
const int SZ = 6;

void solve() {
    ull a;
    int n;
    cin >> a >> n;
    vector<int> D(n);
    rep(i, 0, n) {
        cin >> D[i];
    }

    if (n == 1 && D[0] == 0) {
        cout << a << "\n";
        return;
    }

    string S = to_string(a);
    int L = sz(S);

    int M = D.back();
    int m = D.front();
    int m_nz = -1;
    for (int d : D) {
        if (d > 0) {
            m_nz = d;
            break;
        }
    }

    vector<ull> cands;

    if (L > 1) {
        string c = "";
        rep(i, 0, L - 1) c += to_string(M);
        cands.pb(stoull(c));
    }

    {
        string c = to_string(m_nz);
        rep(i, 0, L) c += to_string(m);
        cands.pb(stoull(c));
    }

    string pref = "";
    rep(i, 0, L + 1) {
        if (i == L) {
            cands.pb(stoull(S));
            break;
        }

        int best_less = -1;
        for (int d : D) {
            if (d < S[i] - '0') best_less = max(best_less, d);
        }
        if (best_less != -1) {
            if (!(i == 0 && best_less == 0 && L > 1)) {
                string c = pref;
                c += to_string(best_less);
                rep(j, i + 1, L) c += to_string(M);
                cands.pb(stoull(c));
            }
        }

        int best_greater = 10;
        for (int d : D) {
            if (d > S[i] - '0') best_greater = min(best_greater, d);
        }
        if (best_greater != 10) {
            string c = pref;
            c += to_string(best_greater);
            rep(j, i + 1, L) c += to_string(m);
            cands.pb(stoull(c));
        }

        bool found = false;
        for (int d : D) {
            if (d == S[i] - '0') {
                found = true;
                break;
            }
        }
        if (!found) break;
        pref += S[i];
    }

    ull ans = ULLONG_MAX;
    for (ull b : cands) {
        ull dist = (a > b) ? (a - b) : (b - a);
        ans = min(ans, dist);
    }

    cout << ans << "\n";
}

int main() {
    tourist;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    chris;
}