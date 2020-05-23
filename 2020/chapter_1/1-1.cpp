#include <vector>
#include <string>
#include <cassert>
#include <unordered_set>
#include <iostream>
#include <bitset>

using namespace std;

bool containsUniqueCharacters(const string& str)
{
  unordered_set<char> characters;

  for (char c : str) {
    if (characters.count(c) > 0) return false;
    else characters.insert(c);
  }

  return true;
}

bool containsUniqueCharactersBitSet(const string& str)
{
  bitset<256> characters(0);

  for (char c : str) {
    if (characters[c]) return false;
    else characters[c] = 1;
  }

  return true;
}

bool containsUniqueCharactersNoDataStructures(const string& str)
{
  for (char c: str) {
    int numMatches = 0;

    for (char k : str) {
      if (c == k) numMatches++;
    }

    if (numMatches > 1) return false;
  }

  return true;
}

int main()
{
  assert(containsUniqueCharacters("a"));
  assert(containsUniqueCharacters("ab"));
  assert(!containsUniqueCharacters("aa"));
  assert(!containsUniqueCharacters("aba"));
  assert(containsUniqueCharacters("averylongz"));

  assert(containsUniqueCharactersBitSet("a"));
  assert(containsUniqueCharactersBitSet("ab"));
  assert(!containsUniqueCharactersBitSet("aa"));
  assert(!containsUniqueCharactersBitSet("aba"));
  assert(containsUniqueCharactersBitSet("averylongz"));

  assert(containsUniqueCharactersNoDataStructures("a"));
  assert(containsUniqueCharactersNoDataStructures("ab"));
  assert(!containsUniqueCharactersNoDataStructures("aa"));
  assert(!containsUniqueCharactersNoDataStructures("aba"));
  assert(containsUniqueCharactersNoDataStructures("averylongz"));

  cout << "success!";
}