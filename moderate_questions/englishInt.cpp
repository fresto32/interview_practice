#include <iostream>
#include <string>
#include <map>

using namespace std;

// English Int: Given any int, print an English phrase that describes the int.
// 
// Example:     Input: 214   Output: Two Hundred and Fourteen
//              Input: 1,210 Output: One thousand, two hundred and ten


// Find the remainder of each order of magnitude and use that as a key value to
// a dictionary that maps keys to words
//
// Rules: 
//         Exceptions: First two orders: put together as keys -> 
//         if second is 0/1
//                     00 -> zero
//                     01 -> one
//                     ...
//                     10 -> ten
//                     14 -> fourteen
//         Normal Map of Map: (dictionary)
//                     [0] 0 -> zero
//                     ...
//                     [1] 1 -> ten
//                     [1] 2 -> twenty
//                     ...
//                     [2] 1 -> one hundred
//                     [2] 2 -> two hundred...
//
// Is there a better way to do this... 
// 19,499,089
//
//      parse(19) + "million" + parse(499) + "thousand" + parse(089)



void englishIntNaive(int n) {
  // Build dictionary -> map of maps
  map<int, map<int, string> > dictionary;
  fillMap(&dictionary);
  map<int, string> exception_dict;
  fillException(&exception_dict)

  bool exception = ((n/10)%10 <= 1) ? true : false;
  
  vector<string> re; //reverse at end

  if (exception) re.push_back(exception_dict(((n/10) %10)*10 + n%10));

  for (int start = (exception) ? 100 : 1; n / start > 0; start *= 10) {
    re.push_back(dictionary[start][(n/start)%10]);
  }
  reverse(re.begin(), re.end());

  for (int i = 0; i < re.size()-1; i++) cout << re[i] << ", ";
  cout << re[re.size() - 1] << endl;
}




