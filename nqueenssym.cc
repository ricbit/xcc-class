// Started at 11:36
// Finished at 13:20

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <variant>

using namespace std;

class NQueens {
 public:
  NQueens(int n) : n(n) {
  }

  int solutions() {
    seen.clear();
    return solutions(0);
  }

 private:
  using Solution = vector<pair<int, int>>;

  int solutions(int i) {
    if (i == n) {
      if (!has_solution(current)) {
        insert_solution();
        return 1;
      }
      return 0;
    }
    int ans = 0;
    int limit = i == 0 ? (n - 1) / 2 : n - 1;
    for (int j = 0; j <= limit; j++) {
      auto match = [j, i](auto pos) {
        return pos.first == j ||
               j + i == pos.first + pos.second ||
               j - i == pos.first - pos.second;
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

  void print_solution(Solution &sol) {
    cout << "\n";
    for (int j = 0; j < n; j++) {
      cout << "(" << sol[j].first << "," << sol[j].second << ") ";
    }
    cout << "\n";
    for (int j = 0; j < n; j++) {
      string out(n, '.');
      for (int i = 0; i < n; i++) {
        if (sol[i].first == j) {
          out[sol[i].second] = 'O';
        }
      }
      cout << out << "\n";
    }
  }

  void insert_solution() {
    auto rotate90 = [n = n](auto p) {
      return make_pair(p.second, n - 1 - p.first);
    };
    auto flipy = [n = n](auto p) {
      return make_pair(n - 1 - p.first, p.second);
    };
    Solution sol(current);
    for (int i = 0; i < 4; i++) {
      insert_solution(sol);
      Solution next(current);
      transform(sol.begin(), sol.end(), next.begin(), flipy);
      insert_solution(next);
      transform(sol.begin(), sol.end(), sol.begin(), rotate90);
    }
  }

  void insert_solution(Solution sol) {
    sort(sol.begin(), sol.end());
    seen.insert(sol);
  }

  bool has_solution(Solution sol) {
    sort(sol.begin(), sol.end());
    return seen.find(sol) != seen.end();
  }

  int n;
  Solution current;
  set<Solution> seen;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "usage: nqueens n\n";
    return 1;
  }
  string nstr(argv[1]);
  istringstream iss(nstr);
  int n;
  iss >> n;
  NQueens nqueens(n);
  cout << "Solutions: " << nqueens.solutions() << "\n";
  return 0;
}
