// Started at 10:30
// Finished at 10:36

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class NEmpress {
 public:
  NEmpress(int n) : n(n) {
  }

  int solutions() {
    return solutions(0);
  }

 private:
  int solutions(int i) {
    if (i == n) {
      return 1;
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
      auto match = [j, i](auto pos) {
        bool present = pos.first == j;
        constexpr auto disp = {-2, -1, 1, 2};
        for (auto x : disp) {
          auto y = 3 ^ abs(x);
          present |= pos.first == j + y && pos.second == i + x;
          present |= pos.first == j - y && pos.second == i + x;
        }
        return present;
      };
      if (current.end() != find_if(current.begin(), current.end(), match)) {
        continue;
      }
      current.push_back(make_pair(j, i));
      ans += solutions(i + 1);
      current.pop_back();
    }
    return ans;
  }

  int n;
  vector<pair<int, int>> current;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "usage: nempress n\n";
    return 1;
  }
  string nstr(argv[1]);
  istringstream iss(nstr);
  int n;
  iss >> n;
  NEmpress nempress(n);
  cout << "Solutions: " << nempress.solutions() << "\n";
  return 0;
}
