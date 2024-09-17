#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ft_read_string() {
    string s1;

    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}

vector<string> ft_split_string(string s1, string delim) {
    vector<string> v_string;
    short pos = 0;
    string s_word;

    while ((pos = s1.find(delim)) != std::string::npos) {
        s_word = s1.substr(0, pos);
        if (s_word != "") {
            v_string.push_back(s_word);
        }
        s1.erase(0, pos + delim.length());
    }
    if (s1 != "") {
        v_string.push_back(s1);
    }

    return v_string;
}

int main() {
    vector<string> v_string;

    v_string = ft_split_string(ft_read_string(), " ");
    cout << "\nTokens = " << v_string.size() << endl << endl;
    for (string& s : v_string) {
        cout << s << endl;
    }
    return 0;
}
