//
// Created by syh on 19-4-24.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    string s1, s2, s1Concat;
    cin >> s1 >> s2;
    if (s1.size() < s2.size())
        s1.swap(s2);
    s1Concat = s1 + s1;
    if (s1Concat.find(s2) == string::npos) // s1Concat 中没有找到 s2
        cout << "false";
    else
        cout << "true";
    return 0;
}