#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream out_file;
    ifstream in_file;
    string line;
    int line_number = 1;

    in_file.open("test1.txt");

    out_file.open("o_sample.txt");

    while(getline(in_file, line)) { 
        if(line.size() != 0) {
             out_file << line_number++;
         
        }
         out_file <<" "<< line <<"\n";
    }
    out_file.close();
    in_file.close();
    cout <<  " hello sam" << endl;
    return 0;
}