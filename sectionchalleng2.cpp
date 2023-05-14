#include<iostream>
#include<fstream>

using namespace std;

int string_score(string &key, string &student_ans) {
    int score = 0;
    for (int i = 0; i < key.size(); i++) {
        if(key[i] == student_ans[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    ifstream in_file;
    in_file.open("test1.txt");

    if(!in_file.is_open()) {
        cout << " Error opening file"<< endl;
        return 1;
    }

    string key, name, score_string;
    int score, total_score = 0, count = 0;

    in_file >> key;

    while(in_file >> name >> score_string) {
        score = string_score(score_string, key);
        cout << name << " : " << score << endl;
        count++;
        total_score += score;

    }

    cout << "The average student score is : " <<(double) total_score/count << endl;

    

    in_file.close();
    return 0;
}