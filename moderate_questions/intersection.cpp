#include <utility>
#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

struct coords {
  float x;
  float y;
  bool parallel;
  bool same;
};

struct coords intersection(pair<float, float> s1,pair<float, float> s2,
    pair<float, float> e1,pair<float, float> e2) {
  float slope1 = (get<1>(e1) - get<1>(s1))/(get<0>(e1) - get<0>(s1));
  float slope2 = (get<1>(e2) - get<1>(s2))/(get<0>(e2) - get<0>(s2));

  float int1 = get<1>(e1) - slope1*get<0>(e1);
  float int2 = get<1>(e2) - slope2*get<0>(e2);

  struct coords re;

  if (fabs(slope1-slope2) <= numeric_limits<double>::min()*fabs(slope1)) {
    if (fabs(int1-int2) <= numeric_limits<double>::min()*fabs(int1)) {
      re.parallel = false;
      re.same = true;
    } else {
      re.parallel = true;
      re.same = false;
    }
    return re;
  }
  re.x = (int2-int1)/(slope1-slope2);
  re.y = slope1*re.x+int1;
  return re;
}

int main() {
  cout << numeric_limits<double>::min() << endl;
  struct coords re;
  re = intersection(make_pair(1.111111,1.111111), make_pair(1.111111,1.111111), make_pair(0,0), make_pair(0,0));
  cout << re.same << endl;
  cout << re.parallel << endl;
  return 0;
}

