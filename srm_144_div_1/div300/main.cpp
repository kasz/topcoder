#include <iostream>
#include <memory>
#include "BinaryCode.cpp"
// #include <stdio.h>

int main(int argc, char *argv[])
{
  // BinaryCode *bc = new BinaryCode();
  auto_ptr<BinaryCode> bc (new BinaryCode());
  string str1 ("123210122");
  vector<string> str1Response = bc->decode(str1);
  cout << "Dla stringa: " << str1 << endl;
  cout << "Pierwsza wartość: " << str1Response[0] << endl;
  cout << "Druga wartość: " << str1Response[1] << endl << endl;
  
  string str2 ("11");
  vector<string> str2Response = bc->decode(str2);
  cout << "Dla stringa: " << str2 << endl;
  cout << "Pierwsza wartość: " << str2Response[0] << endl;
  cout << "Druga wartość: " << str2Response[1] << endl << endl;;
  
  string str3 ("22111");
  vector<string> str3Response = bc->decode(str3);
  cout << "Dla stringa: " << str3 << endl;
  cout << "Pierwsza wartość: " << str3Response[0] << endl;
  cout << "Druga wartość: " << str3Response[1] << endl << endl;;
  
  string str4 ("123210120");
  vector<string> str4Response = bc->decode(str4);
  cout << "Dla stringa: " << str4 << endl;
  cout << "Pierwsza wartość: " << str4Response[0] << endl;
  cout << "Druga wartość: " << str4Response[1] << endl << endl;;
  
  string str5 ("3");
  vector<string> str5Response = bc->decode(str5);
  cout << "Dla stringa: " << str5 << endl;
  cout << "Pierwsza wartość: " << str5Response[0] << endl;
  cout << "Druga wartość: " << str5Response[1] << endl << endl;;
  
  string str6 ("12221112222221112221111111112221111");
  vector<string> str6Response = bc->decode(str6);
  cout << "Dla stringa: " << str6 << endl;
  cout << "Pierwsza wartość: " << str6Response[0] << endl;
  cout << "Druga wartość: " << str6Response[1] << endl << endl;;
  return 0;
}
