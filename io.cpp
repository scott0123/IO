#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "io.h"

using namespace std;

void prompt_int(int &input){
    cout << "Input (int): " << endl;
    cin >> input;
}

void prompt_string(string &input){
    cout << "Input (string): " << endl;
    cin >> input;
}



void answer_int(int &answer){
    cout << "Answer: " << answer << endl;
}

void answer_string(string &answer){
    cout << "Answer: " << answer << endl;
}



string readfile(const string &filename, int line){

    ifstream in(filename);

    string s;

    //skip N lines
    for(int i = 0; i < line; i++)
        getline(in, s);

    getline(in,s);
    
    cout << "Input (from file): " << s << endl;
   
    return s; 
}

vector<int> int_vector_from_file_with_separator(const string &filename, char separator){

    vector<int> vec;
    ifstream in(filename);

    string s;

    cout << "Input (from file): " << endl;
    
    // get the next line
    getline(in, s);
    cout << s << endl;

    // if line isnt empty, parse it
    if(!s.empty()){

        // initially the number is zero
        vec.push_back(0);
        for(int i = 0; i < (int) s.length(); i++){

            if(s[i] == separator){
                vec.push_back(0);
                continue;
            }

            if(s[i] < '0' || s[i] > '9') continue;

            vec.back() *= 10;
            vec.back() += s[i] - '0';

            if(i == (int) s.length() - 1 && s[0] == '-'){
                vec.back() = -vec.back();
            }
        }
    } // finished parsing line

    return vec; 
}

vector<string> string_vector_from_file_with_separator(const string &filename, char separator){

    vector<string> vec;
    ifstream in(filename);

    string s;

    cout << "Input (from file): " << endl;

    // get the next line
    getline(in, s);
    cout << s << endl;

    // if line isnt empty, parse it
    if(!s.empty()){

        // initially the number is zero
        vec.push_back("");
        for(int i = 0; i < (int) s.length(); i++){

            if(s[i] == separator){
                vec.push_back("");
                continue;
            }

            vec.back() += s[i];
        }
    } // finished parsing line

    return vec; 
}

vector<vector<int> > int_matrix_from_file_with_separator(const string &filename, char separator){

    vector<vector<int> > matrix;
    ifstream in(filename);

    string s;

    cout << "Input (from file): " << endl;
    
    while(true){

        // get the next line
        getline(in, s);
        cout << s << endl;

        // if line isnt empty, parse it
        if(!s.empty()){

            vector<int> row;
            // initially the number is zero
            row.push_back(0);
            for(int i = 0; i < (int) s.length(); i++){

                if(s[i] == separator){
                    row.push_back(0);
                    continue;
                }

                if(s[i] < '0' || s[i] > '9') continue;

                row.back() *= 10;
                row.back() += s[i] - '0';

                if(i == (int) s.length() - 1 && s[0] == '-'){
                    row.back() = -row.back();
                }
            }
            // add the row to the matrix
            matrix.push_back(row);
        } // finished parsing line

        // if it reached the end break
        if(in.eof()) break;
    }

    return matrix; 
}

vector<vector<string> > string_matrix_from_file_with_separator(const string &filename, char separator){

    vector<vector<string> > matrix;
    ifstream in(filename);

    string s;

    cout << "Input (from file): " << endl;
    
    while(true){

        // get the next line
        getline(in, s);
        cout << s << endl;

        // if line isnt empty, parse it
        if(!s.empty()){

            vector<string> row;
            // initially the number is zero
            row.push_back("");
            for(int i = 0; i < (int) s.length(); i++){

                if(s[i] == separator){
                    row.push_back("");
                    continue;
                }

                row.back() += s[i];
            }
            // add the row to the matrix
            matrix.push_back(row);
        } // finished parsing line

        // if it reached the end break
        if(in.eof()) break;
    }

    return matrix; 
}

int string_to_int(string s){

    int output = 0;
    for(int i = 0; i < (int) s.length(); i++){

        if(s[i] < '0' || s[i] > '9') continue;

        output *= 10;
        output += s[i] - '0';

        if(i == (int) s.length() - 1 && s[0] == '-'){
            output = -output;
        }
    }
    return output;
}
