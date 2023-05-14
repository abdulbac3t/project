#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to get input from user and write to file
void askQuestion(string user) {
    string username;

    cout << " Enter the name of the user: "<< endl;
    cin >> username;
  string question;
  cout << "\nAsk a question: " << endl;
  cin.ignore();
  if (cin.fail()) {
    cerr << "Error: Failed to read input from std::cin" << endl;
    return;
}
  getline(cin, question, '\n');
  if (std::cin.fail()) {
        std::cerr << "Error: Failed to read input from std::cin" << std::endl;
        return;
    }
 string filename = username + "_qs.txt";
  fstream outfile;
  cout << "User selected : "<< filename << endl;
outfile.open(filename, ios::in | ios:: out | ios_base::app); // Append to file
   if(!outfile.is_open()) {
        cout << "error opening file";
        return ;
    }
    if (!outfile.is_open() || !(outfile.good() && outfile.is_open())) {
  cout << "Error: file is not open for writing" << endl;
  return ;
}

  int count = 1;
  bool asked = false;
  while(true) {
    count++;
    string word;
    outfile >> word;
    if(word == user) {
        string line;
        getline(outfile , line);
        if(line == "") {
            outfile << question << endl;
            outfile << " \n " ;
            asked = true;
            cout << "\n question asked";
            break;
        }

        
    }
    if(count == 100)
    break;
    
  }
  if(asked == false)
  {
    outfile << user << endl;
    outfile << question;
    outfile << "\n";
    cout << "\nquestion asked" << endl;
  }
  outfile.close();
}

// Function to read questions from file and display them
void viewQuestions(string username) {
  ifstream infile;
  infile.open(username + ".txt");

  if (infile) {
    string question;
    while (getline(infile, question)) {
      cout << question << endl;
    }
    infile.close();
  } else {
    cout << "No questions found." << endl;
  }
}

int main() {
  string username;
  cout << "Enter your username: ";
  cin >> username;

  int choice;
  do {
    cout << "1. Ask a question" << endl;
    cout << "2. View questions" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
if (choice == 1) {
  askQuestion(username);
} else if (choice == 2) {
  viewQuestions(username);
} else if (choice == 3) {
  cout << "Goodbye!" << endl;
} else {
  cout << "Invalid choice. Try again." << endl;
}

  } while (choice != 3);

  return 0;
}
