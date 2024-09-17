#include <iostream>
#include <string>
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
    string word;

    while ((pos = s1.find(delim)) != std::string::npos) 
	{
        word = s1.substr(0, pos);
        if (word != "") 
            v_string.push_back(word);
        s1.erase(0, pos + delim.length());
    }

    if (s1 != "") 
        v_string.push_back(s1);

    return v_string;
}

string ft_reverse_words_in_string(string s1) 
{
    vector<string> v_string;
    string s2 = "";

    v_string = ft_split_string(s1, " ");

    vector<string>::iterator iter = v_string.end();
    while (iter != v_string.begin()) 
	{
        --iter;
        s2 += *iter + " ";
    }

    s2 = s2.substr(0, s2.length() - 1);
    return s2;
}

int main() {
    string s1 = ft_read_string();
    cout << "\n\nString after reversing words:\n";
    cout << ft_reverse_words_in_string(s1) << endl;
    return 0;
}
