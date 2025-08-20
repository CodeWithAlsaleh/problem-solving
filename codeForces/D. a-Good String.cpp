// I can't prove why my code works
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cout << #x << " = " << x << '\n';
using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;

const ll N = 1e7 + 1;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;

// Just use a backTrack approach without even using dp
int n;
string s;
vector<char> ch;
int backTrack(int st, int en, int cur = 0)
{
  if (st >= en)
    return 0;

  int cnt1 = 0, cnt2 = 0;
  int len = (en - st) / 2;
  if (len == 1)
  {
    int ind1 = st, ind2 = en - 1;
    if (s[ind1] == ch[cur] and s[ind2] == ch[cur + 1])
      return 0;
    if (s[ind1] == ch[cur + 1] and s[ind2] == ch[cur])
      return 0;

    if (s[ind1] == ch[cur])
      return 1;
    if (s[ind1] == ch[cur + 1])
      return 1;
    if (s[ind2] == ch[cur])
      return 1;
    if (s[ind2] == ch[cur + 1])
      return 1;

    return 2;
  }

  for (int i = st; i < st + len; ++i)
    if (s[i] == ch[cur])
      cnt1++;

  for (int i = st + len; i < en; ++i)
    if (s[i] == ch[cur])
      cnt2++;

  int firstP = backTrack(st + len, en, cur + 1) + (len - cnt1);
  int secondP = backTrack(st, en - len, cur + 1) + (len - cnt2);

  return min(firstP, secondP);
}

void solve()
{
  cin >> n;
  cin >> s;

  if (n == 1)
  {
    cout << 1 - (s[0] == 'a') << '\n';
    return;
  }

  cout << backTrack(0, n) << '\n';
}

int main()
{
  FAST;
  int t = 1;
  cin >> t;
  for (int i = 0; i < 26; ++i)
    ch.push_back(char(97 + i));
  while (t--)
    solve();
  return 0;
}
