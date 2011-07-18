#include <iostream>
#include <vector>
#include <memory>

#include "Bonuses.cpp"

using namespace std;

void printIntVector(vector<int> vectorToPrint)
{
  cout << "{";
  for (vector<int>::iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); ++it)
    {
      cout << *it << " ,";
    }
  cout << "}" << endl;
}


int main(int argc, char *argv[])
{
  auto_ptr<Bonuses> bonuses (new Bonuses());
  
  int test1Array[] = {1,2,3,4,5};
  vector<int> test1Vec (test1Array, test1Array + sizeof(test1Array) / sizeof(int) );
  cout << "Dla {1,2,3,4,5}" << endl;
  printIntVector(bonuses->getDivision(test1Vec));

  int test2Array[] = {5,5,5,5,5,5};
  vector<int> test2Vec (test2Array, test2Array + sizeof(test2Array) / sizeof(int) );
  cout << "Dla {5,5,5,5,5,5}" << endl;
  printIntVector(bonuses->getDivision(test2Vec));

  int test3Array[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296, 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
  vector<int> test3Vec (test3Array, test3Array + sizeof(test3Array) / sizeof(int) );
  cout << "Dla {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296, 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}" << endl;
  printIntVector(bonuses->getDivision(test3Vec));

  return 0;
}

