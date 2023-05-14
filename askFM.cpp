#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>

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
    bool login_status;     // true if logged in or false
    int choice = menu_1(); // menu presented to user for signing or loggin in

    if(choice == 1)
    login_status = Login();
    if(choice == 2)
     SignUp();
    

    if(login_status == true) {
    int choice = menu();
    if (choice == 5)
    AskQuestion();
    }
   }

   int menu() {
    int choice = -1;
    while( choice == -1) {
        cout << setw(20) <<" "<< "1: Print Questions To Me" << endl;
        cout << setw(20) <<" "<< "2: Print Questions From Me" << endl;
        cout << setw(20) <<" "<< "3: Answer Question" << endl;
        cout << setw(20) <<" "<< "4: Delete Question" << endl;
        cout << setw(20) << " "<<"5: Ask Question" << endl;

        cin >> choice;
        if(!(choice<=8 && choice>=1)) {
            cout << " Invalid Choice " << endl;
            choice = -1;
        }
    }
    return choice;
   }
   int menu_1() {
    int choice = -1;
    while(choice == -1) {
        cout << "Menu : " << endl;
        cout << setw(20) << " " << "1: Login " << endl;
        cout << setw(20) << " " << "2: Sign Up" << endl;

        cout <<"Enter your choice: " ;

        cin >> choice;
          
    }
    return choice;
   }

   bool Login() {
    ifstream id_ip_file;
    id_ip_file.open("user_ids.txt");
    string name;
    string list_name;
    int id;
    int list_pin;
    int PIN;
    cout << " Enter user name & PIN :" ;
    cin >> name >> PIN;
    cin.ignore();

    string user;

    while(true) {
       id_ip_file >> list_name;

       if(list_name == "")
       return false;

       id_ip_file >> list_pin;
     //  cout << endl <<  " entered the loop" << list_name << endl << list_pin<< endl;

    if(list_name == name && (int)list_pin == PIN) {
            cout << "Logged In" << endl;

             return true;
    }
   


   }
   }

   void  SignUp() {
    ofstream o_file_a;
    ofstream o_file_q;
    ofstream o_file_mq;
    string name;
    int PIN;

   /* string line_to_replace = "end_of_file";
    string line;
    string a_next_line = "";
    streampos old_pos = 0;
    while(getline(id_file_in, line)) {
        if(line == line_to_replace) {
          old_pos = id_file_in.tellg();
          id_file_in.seekp(old_pos - static_cast<streamoff>(line_to_replace.length()) - static_cast<streamoff>(1) );
          id_file_in.write(a_next_line.c_str(), a_next_line.length());
        }

    }*/
    cout << " Enter your name: " ;
    cin >> name;
    id_file_in << name << endl;

    cout << " Enter your pin: ";
    cin >> PIN ;

    id_file_in << PIN << endl;
    string full_name_q = name + "_qs.txt";
    string full_name_a = name + "_as.txt"; 
    string full_name_mq = name + "_mqs.txt";

    o_file_q.open(full_name_q);
    o_file_a.open(full_name_a);
    o_file_mq.open(full_name_mq);
    cout <<" heart beat at file creation" << endl;
    o_file_a << "File Created \n" << endl;
    o_file_a.close();
    o_file_q.close();
    o_file_mq.close();
    return;

   } 
   
   void AskQuestion() {
    string name;
    cout << "Enter the user_name: ";
    cin >> name;
    string question;

    string full_name = name + "_qs.txt";

    fstream user_file(full_name, ios::app);   
    if(!user_file.is_open()) {
        cout << "error opening file";
        return ;
    }
    int q_cnt = q_count(name);

  cin.ignore();
  getline(cin, question, '\n');
  user_file << question << " \n";

  user_file.close();

   }
   int q_count(string file_name) {
    ifstream user_file;
    string full_name = file_name + ".txt";
    user_file.open(full_name);
    string word;
    int q_cnt;
    while(user_file >> word) {
        if(word == "Question_count")
        break;
    }
    user_file >> q_cnt;
    return q_cnt;
   }

   void close_files() {
     id_file_in.close();
     
     
   }
};



int main() {
   //---- YOU WRITE YOUR CODE BELOW THIS LINE----
    askFM app;
    app.run();
    app.close_files();

    return 0;


}