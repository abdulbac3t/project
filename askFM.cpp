#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

struct askFM {
  //ifstream in_file{"user_ids.txt"};
   fstream id_file_in;
   askFM() : id_file_in("user_ids.txt", ios::in | ios::out |ios::app) {
    if(!id_file_in) {
        cout << " Error opening file user_ids.txt" << endl;
    }
 
   }

   void run () {
    int choice = menu_1();
    if(choice == 1)
     Login();
    if(choice == 2)
     SignUp();
   }
     
   int menu_1() {
    int choice = -1;
    while(choice == -1) {
        cout << "Menu : " << endl;
        cout << setw(20) << "1: Login " << endl;
        cout << setw(21) << "2: Sign Up" << endl;

        cout <<"Enter your choice: " ;

        cin >> choice;
          
    }
    return choice;
   }

   void Login() {
    string name;
    string list_name;
    int list_pin;
    int PIN;
    cout << " Enter user name & PIN :" ;
    cin >> name >> PIN;
    while(true) {
       id_file_in >> list_name;

       if(list_name == "end_of_file")
       return;

       id_file_in >> list_pin;
     //  cout << endl <<  " entered the loop" << list_name << endl << list_pin<< endl;

    if(list_name == name && (int)list_pin == PIN) {
            cout << " Account Found" << endl;
             return;
    }
   


   }
   }

   void  SignUp() {
    string name;
    int PIN;

    cout << " Enter your name: " ;
    cin >> name;
    id_file_in << name << endl;

    cout << " Enter your pin: ";
    cin >> PIN ;

    id_file_in << PIN << endl;

   } 
   
};



int main() {
   //---- YOU WRITE YOUR CODE BELOW THIS LINE----
    askFM app;
    app.run();

    return 0;


}