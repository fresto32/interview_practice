// One Away
#include <string>
#include <cassert>


int NumberOfEditsNeededToEquate(
  const std::string& one, 
  const std::string& other)
{
  int editsUsed = 0;

  for (int i = 0, j = 0; i < one.length(), j < other.length();) {
    if (one[i] != other[j]) {
      editsUsed++;

      if (one.length() == other.length()) {
        i++; 
        j++; 
      }
      if (one.length() > other.length()) {
        i++;
      } else {
        j++;
      }
    } else {
      i++;
      j++;
    }
  }

  return editsUsed;
}

bool AreStringsWithinOneEditOfEachother(
  const std::string& one, 
  const std::string& other)
{
  if (abs(one.length() - other.length()) > 1) return false;
  return NumberOfEditsNeededToEquate(one, other) <= 1;
}

bool OneAwayReplacement(const std::string& one, const std::string& other)
{
  bool foundDifference = false;
  for (int i = 0; i < one.length(); i++) {
    if (one[i] != other[i]) {
      if (foundDifference) return false;
      else foundDifference = true;
    }
  }
  return true;
}

bool OneAwayInsert(const std::string& longer, const std::string& shorter)
{
  if (longer.length() == 0 || shorter.length() == 0) {
    if (abs(longer.length() - shorter.length()) == 1) return true;
    else return false;
  }

  bool foundDifference = false;

  for (int i = 0, j = 0; i < longer.length(), j < shorter.length();) {
    if (longer[i] != shorter[j]) {
      if (foundDifference) return false;
      foundDifference = true;
      i++;
    } else {
      i++;
      j++;
    }
  }
  return true;
}

bool OneAway(const std::string& one, const std::string& other)
{
  if (one.length() == other.length()) {
    return OneAwayReplacement(one, other);
  } else if (one.length() + 1 == other.length()) {
    return OneAwayInsert(other, one);
  } else if (one.length() - 1 == other.length()) {
    return OneAwayInsert(one, other);
  }

  return false;
}

int main()
{
  //assert(AreStringsWithinOneEditOfEachother("a", "a"));
  //assert(AreStringsWithinOneEditOfEachother("a", "b"));
  //assert(AreStringsWithinOneEditOfEachother("a", ""));
  //assert(AreStringsWithinOneEditOfEachother("pa", "pb"));
  //assert(AreStringsWithinOneEditOfEachother("pall", "pll"));

  //assert(!AreStringsWithinOneEditOfEachother("pall", "pbllllll"));
  //assert(!AreStringsWithinOneEditOfEachother("ac", "pb"));
  //assert(!AreStringsWithinOneEditOfEachother("ac", ""));

  assert(OneAway("a", "a"));
  assert(OneAway("a", "b"));
  assert(OneAway("a", ""));
  assert(OneAway("pa", "pb"));
  assert(OneAway("pall", "pll"));

  assert(!OneAway("pall", "pbllllll"));
  assert(!OneAway("ac", "pb"));
  assert(!OneAway("ac", ""));
}