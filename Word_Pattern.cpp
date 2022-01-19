#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        stringstream ss (s);
        string temp;
        int l = pattern.size();
        int i = 0;
        while (ss >> temp) {
            if (i == l)
                return false;
            char ch = pattern[i];
            if (m.count(ch) != n.count(temp))
                return false;
            if (m.count(ch)) {
                if (n[temp] != ch || m[ch] != temp)
                    return false;
            }
            else {
                m.insert({ ch,temp });
                n.insert({ temp,ch });
            }
            i++;
        }
        return i == l;
    }
};

int main() {
    Solution obj;
    cout<<obj.wordPattern("abba", "dog cat cat dog");
    return 0;
}