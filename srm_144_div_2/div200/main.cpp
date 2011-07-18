#include <iostream>
#include <memory>

#include "Time.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  auto_ptr<Time> time (new Time());
  cout << "Dla 0 sekund " << time->whatTime(0) << endl;
  cout << "Dla 3661 sekund " << time->whatTime(3661) << endl;
  cout << "Dla 5436 sekund " << time->whatTime(5436) << endl;
  cout << "Dla 86399 sekund " << time->whatTime(86399) << endl;
  return 0;
}
