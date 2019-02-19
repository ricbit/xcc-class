// Started at 11:07
// Finished at 11:34

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class NQueens {
 public:
  NQueens(int n) : n(n) {
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

  int n;
  vector<pair<int, int>> current;
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
