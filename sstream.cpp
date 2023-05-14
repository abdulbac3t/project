#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

int main() {
    string str {" hello 020 4.34"};
    string alphb;
    int num;
    double pointed;

    istringstream iss { str };

    iss >> alphb >> num >> pointed;
   

   ostringstream oss;

   oss << pointed <<" "<< alphb << " " << num ;
   cout << oss.str() << endl;
    return 0;
}