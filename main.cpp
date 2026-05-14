#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;

// helper function to check if word is compounded
bool checkCompound(string& word, unordered_set<string>& dict, vector<int>& memo, int start) {
    if (start == word.length()) {
        return true;
    }
    
    if (memo[start] != -1) {
        return memo[start] == 1;
    }
    
    // len to check. if start is 0, we can't take the whole word
    int limit = word.length() - start;
    if (start == 0) {
        limit--; // leave at least 1 char
    }
    
    for (int len = 1; len <= limit; len++) {
        string sub = word.substr(start, len);
        if (dict.find(sub) != dict.end()) {
            // found prefix, check the rest
            if (checkCompound(word, dict, memo, start + len)) {
                memo[start] = 1;
                return true;
            }
        }
    }
    
    memo[start] = 0;
    return false;
}

void solve(string filename) {
    auto start_time = chrono::high_resolution_clock::now();

    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening " << filename << "\n";
        return;
    }

    vector<string> arr;
    unordered_set<string> dict;
    string s;
    
    while (fin >> s) { // reading word by word automatically ignores \r and \n
        arr.push_back(s);
        dict.insert(s);
    }
    fin.close();

    // sort by length descending
    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        if (a.length() == b.length()) {
            return a < b; // alphabetical for same length
        }
        return a.length() > b.length();
    });

    string ans1 = "", ans2 = "";

    for (int i = 0; i < arr.size(); i++) {
        vector<int> memo(arr[i].length(), -1);
        if (checkCompound(arr[i], dict, memo, 0)) {
            if (ans1 == "") {
                ans1 = arr[i];
            } else if (ans2 == "") {
                ans2 = arr[i];
                break; // found both
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "--- " << filename << " ---\n";
    cout << "Longest Compound Word: " << ans1 << "\n";
    cout << "Second Longest Compound Word: " << ans2 << "\n";
    cout << "Time taken: " << time_taken << " milliseconds\n\n";
}

int main() {
    solve("Input_01.txt");
    solve("Input_02.txt");
    return 0;
}
