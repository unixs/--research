#include <list>

using namespace std;

static void
fu(list<pair<int, int>> &st, size_t counter, int n)
{
  size_t pos = counter;
  list<pair<int, int>> tmp{};

  for (auto it = st.rbegin(); it != st.rend(); it++) {
    if (pos == counter || pos == n) {
      tmp.push_front(*it);
      pos--;
      continue;
    }

    if (pos == 1) {
      tmp.push_front(*it);
      break;
    }

    pos--;
  }

  // отрезать хвост
  auto itRmFrom = st.begin();
  auto itRmTo = st.begin();
  auto fromOffset = st.size() - counter;
  auto toOffset = st.size();
  advance(itRmFrom, fromOffset);
  advance(itRmTo, toOffset);

  // deleting range of elements from index [fromOffset, toOffset)
  st.erase(itRmFrom, itRmTo);

  // прицепить новый хвост
  auto tail = tmp.begin();
  st.insert(st.end(), tmp.begin(), tmp.end());
}

list<pair<int, int>>
sparse(list<pair<int, int>> &in)
{
  std::list<std::pair<int, int>> result{};
  size_t counter = {0};

  for (auto current : in) {
    if (result.empty()) {
      result.push_back(current);
      counter++;
      continue;
    }

    if (current.second == result.back().second) {
      result.push_back(current);
      counter++;
      continue;
    }

    if (current.second != result.back().second) {
      if (counter > 2) {
        // тут обрабатываем накопленную полседовательность
        fu(result, counter, 3);
      }

      result.push_back(current);
      counter = 1;
      continue;
    }
  }

  return result;
}
