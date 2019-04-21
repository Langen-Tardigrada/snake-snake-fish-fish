#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main(){
    _setmode(_fileno(stdout), _O_U16TEXT);
   // wcout << L"Hello, \U+00A3!\n";
    wcout<<L"\x2660"<<endl<<L"\x2665"<<endl<<L"\x2666"<<endl<<L"\x2663"<<endl;
    
  //  std::wcout << "\u07CA";
  //  std::wcout << L"?";
  return 0;
}