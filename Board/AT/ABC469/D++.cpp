#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> matches;

// 辅助单层函数：固定 x，在 1~N 中枚举寻找合法的 y
vector<int> find_partners(int x) {
    // 收集所有 x 没有参加的比赛
    vector<int> missed_matches;
    for (int i = 0; i < M; ++i) {
        if (matches[i].first != x && matches[i].second != x) {
            missed_matches.push_back(i);
        }
    }

    vector<int> valid_y;

    // 情况 A：x 参加了所有比赛，那么 1~N 中除了 x 自己，其他人全都是合法 partner
    if (missed_matches.empty()) {
        for (int y = 1; y <= N; ++y) {
            if (y != x) valid_y.push_back(y);
        }
        return valid_y;
    }

    // 情况 B：x 有漏掉的比赛，那 y 必须来自第一场漏掉的比赛 (u 或 v)
    int first_miss = missed_matches[0];
    int candidates[2] = {matches[first_miss].first, matches[first_miss].second};

    // 单层验证这两个候选人是否能覆盖剩余所有漏掉的比赛
    for (int cand : candidates) {
        bool ok = true;
        for (int idx : missed_matches) {
            if (matches[idx].first != cand && matches[idx].second != cand) {
                ok = false; // 有某场比赛 cand 也没参加，淘汰
                break;
            }
        }
        if (ok && cand != x) {
            valid_y.push_back(cand);
        }
    }

    return valid_y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    matches.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> matches[i].first >> matches[i].second;
    }

    int A1 = matches[0].first;
    int B1 = matches[0].second;

    // 两次独立的单层调用！
    vector<int> partners_A1 = find_partners(A1); // 第一次单层：找能与 A1 配对的 y
    vector<int> partners_B1 = find_partners(B1); // 第二次单层：找能与 B1 配对的 y

    long long total = partners_A1.size() + partners_B1.size();

    // 检查 {A1, B1} 这对组合是不是在两边都被统计了，是的话 -1 去重
    bool counted_in_A1 = false;
    for (int y : partners_A1) if (y == B1) counted_in_A1 = true;

    if (counted_in_A1) {
        total--;
    }

    cout << total << "\n";

    return 0;
}