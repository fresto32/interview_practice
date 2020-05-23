#include <cassert>
#include <string>
#include <array>

bool arePermutations(const std::string& one, const std::string& other)
{
  std::array<int, 256> oneCharacters;
  oneCharacters.fill(0);

  for (char c : one) oneCharacters[c]++;

  for (char c : other) {
    oneCharacters[c]--;
    if (oneCharacters[c] < 0) return false;
  }

  return true;
}

int main()
{
  assert(arePermutations("h", "h"));
  assert(arePermutations("ha", "ha"));
  assert(arePermutations("ah", "ah"));

  assert(!arePermutations("a", "h"));
  assert(!arePermutations("hb", "ha"));
  assert(!arePermutations("ak", "ah"));
}