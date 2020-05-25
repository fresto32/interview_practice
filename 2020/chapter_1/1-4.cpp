#include <cassert>
#include <string>
#include <array>

using CharOccurenceArray = std::array<int, 256>;

CharOccurenceArray countCharOccurences(const std::string& InspectedString);
unsigned int numOddOccurences(const CharOccurenceArray& charOccurences);

bool isPalindromePermutation(const std::string& InspectedString)
{
  const auto charOccurences = countCharOccurences(InspectedString);
  if (numOddOccurences(charOccurences) > 1) return false;
  else return true;
}

CharOccurenceArray countCharOccurences(const std::string& InspectedString)
{
  CharOccurenceArray charOccurences;
  charOccurences.fill(0);

  for (char c : InspectedString) charOccurences[c]++;

  return charOccurences;
}

unsigned int numOddOccurences(const CharOccurenceArray& charOccurences)
{
  unsigned int numOddOccurences = 0; 

  for (unsigned int i = 0; i < 256; i++) {
    if (charOccurences[i] % 2 == 1) numOddOccurences++;
  }

  return numOddOccurences;
}


int main()
{
  assert(isPalindromePermutation("e"));
  assert(!isPalindromePermutation("ea"));
  assert(isPalindromePermutation("ee"));
  assert(isPalindromePermutation("eae"));
  assert(isPalindromePermutation("aee"));
  assert(isPalindromePermutation("a"));
}