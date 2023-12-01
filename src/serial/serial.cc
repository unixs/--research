#include <iostream>
#include <list>

#include <sparse.hpp>

using namespace std;

static void
print(list<pair<int, int>> &l)
{
  for (auto f : l) {
    cout << f.first << " " << f.second << " ";
  }

  cout << std::endl;
}

int
main(int argc, char *argv[])
{
  list<pair<int, int>> in{{1, 10}, {2, 11}, {3, 11}, {4, 11},  {5, 11}, {6, 10},
                          {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10}};

  print(in);

  auto out = sparse(in);

  print(out);

  return 0;
}
