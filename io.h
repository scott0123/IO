#include <vector>
#include <string>

using namespace std;

void prompt_int(int &input);
void prompt_string(string &input);

void answer_int(int &answer);
void answer_string(string &answer);

string readfile(const string &filename, int line);

vector<int> int_vector_from_file_with_separator(const string &filename, char separator);
vector<string> string_vector_from_file_with_separator(const string &filename, char separator);
vector<vector<int> > int_matrix_from_file_with_separator(const string &filename, char separator);
vector<vector<string> > string_matrix_from_file_with_separator(const string &filename, char separator);

int string_to_int(string s);
