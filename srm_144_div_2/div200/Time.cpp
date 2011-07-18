#include <string>
#include <cstdio>

using namespace std;

const int HOUR = 3600;
const int MINUTE = 60;

class Time
{
public:
  string whatTime(int seconds);
};

string Time::whatTime(int seconds)
{
  
  int h = 0;
  int m = 0;
  int s = 0;
  int rest = 0;

  h = seconds / HOUR;
  rest = seconds % HOUR;
  m = rest / MINUTE;
  s = rest % MINUTE;

  char tempStr [] = "";
  sprintf(tempStr, "%d", h);
  string returnString = string(tempStr);
  returnString += string(":");
  sprintf(tempStr, "%d", m);
  returnString += string(tempStr);
  returnString += string(":");
  sprintf(tempStr, "%d", s);
  returnString += string(tempStr);

  return returnString;
}
