#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word, ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        for (int i = words.size() - 1; i > 0; i--) {
            ans += words[i];
            ans += ' ';
        }
        ans += words[0];

        return ans;
    }

    string reverseWords_1(string s) {
    // 先去除字符串两端的空格
    int n = s.length(), start = 0, end = n - 1;
    while (start <= end && s[start] == ' ') start++;
    while (end >= start && s[end] == ' ') end--;

    // 移除字符串中多余的空格
    string trimmed;
    bool inWord = false;
    for (int i = start; i <= end; i++) {
        if (s[i] != ' ' || (s[i] == ' ' && inWord)) {
            trimmed += s[i];
            inWord = true;
        }
        if (s[i] == ' ' && inWord) {
            inWord = false;
        }
    }

    reverseString(trimmed, 0, trimmed.length() - 1);

    int wordStart = 0;
    for (int i = 0; i <= trimmed.length(); i++) {
        if (i == trimmed.length() || trimmed[i] == ' ') {
            reverseString(trimmed, wordStart, i - 1);
            wordStart = i + 1;
        }
    }

    return trimmed;
    }

    void reverseString(string& s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
};

int main() {
    Solution sol;
    string s = "Hello World!";
    cout << sol.reverseWords(s) << endl;
    cout << sol.reverseWords_1(s) << endl;

    return 0;
}
