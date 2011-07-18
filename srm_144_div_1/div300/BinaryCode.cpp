#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int CHARDISTANCE = 48;
class BinaryCode
{
private:
  string _internalDecode(vector<int> convertedMessage, int start=0);
  vector<int> _convertStringToIntVector(string str);
  string _convertIntVectorToString(vector<int> str);
public:
  vector<string> decode(string message);
};

string BinaryCode::_internalDecode(vector<int> convertedMessage, int start)
{
  vector<int> originalMessageVector(convertedMessage.size());
  originalMessageVector[0] = start;
  for (int i = 0; i < convertedMessage.size(); ++i)
  {
    int tempVar = 0;
    if (i == 0)
    {
      tempVar = convertedMessage[i] - originalMessageVector[i];
    }
    else if (i == convertedMessage.size() - 1) {
      if (originalMessageVector[i] + originalMessageVector[i-1] == convertedMessage[i])
      {
	break;
      }
      else
      {
	return string("NONE");
      }
    }
    else
    {
      tempVar = convertedMessage[i] - originalMessageVector[i] - originalMessageVector[i-1];
    }

    if (tempVar > 1) {
      return string("NONE");
    }
    originalMessageVector[i+1] = tempVar;
  }
  return this->_convertIntVectorToString(originalMessageVector);
}

vector<int> BinaryCode::_convertStringToIntVector(string str)
{
  vector<int> returnVector(str.length());
  for (int i = 0; i < str.length(); ++i)
  {
    returnVector[i] = (int)str[i] - CHARDISTANCE;
  }
  return returnVector;
}

string BinaryCode::_convertIntVectorToString(vector<int> intVec) {
  string returnString;
  for (int i = 0; i < intVec.size(); ++i)
  {
    returnString.push_back(char(intVec[i]) + CHARDISTANCE);
  }
  return returnString;
}

vector<string> BinaryCode::decode(string message)
{
  vector<string> returnVector(2);
  vector<int> convertedMessage = this->_convertStringToIntVector(message);

  // returnVector[0] = string("wartość 1");
  returnVector[0] = this->_internalDecode(convertedMessage);
  // returnVector[1] = string("wartość 2");
  returnVector[1] = this->_internalDecode(convertedMessage, 1);
  return returnVector;
}
