#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Bonuses
{
private:
  vector<int> _getTopEmployees(vector<int> points);
public:
  vector<int> getDivision(vector<int> points);
};

vector<int> Bonuses::_getTopEmployees(vector<int> points)
{
  vector<int> returnVector;
  map<int, int> pointsMap;
  for (int i = 0; i < points.size(); ++i)
    {
      pointsMap[i] = points[i];
    }
  while (!pointsMap.empty())
    {
      int top = (*pointsMap.begin()).first;
      for (map<int,int>::iterator it = pointsMap.begin(); it != pointsMap.end(); ++it)
	{
	  if ((*it).second > pointsMap[top])
	    {
	      top = (*it).first;
	    }
	}
      returnVector.push_back(top);
      pointsMap.erase(top);
    }
  
  return returnVector;
}

vector<int> Bonuses::getDivision(vector<int> points)
{
  vector<int> returnVector(points.size());
  int bonusSum = 0;
  double remainingPercentage = 100.00;

  for (vector<int>::iterator it = points.begin(); it != points.end(); ++it)
    {
      bonusSum += *it;
    }

  for (int i = 0; i < returnVector.size(); ++i)
    {
      double calculatedPercentage = (double)points[i] / bonusSum * 100.00;
      returnVector[i] = (int)floor(calculatedPercentage);
      remainingPercentage -= returnVector[i];
    }
  if (remainingPercentage >= 1.00)
    {
      vector<int> topEmployees = this->_getTopEmployees(points);
      int topPosition = 0;
      while (remainingPercentage >= 1.00)
	{
	  returnVector[topEmployees[topPosition]]++;
	  remainingPercentage -= 1.00;
	  topPosition++;
	}
    }
  
  return returnVector;
}
