#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    vector<string> colors = {"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};

    int maxColors = 0;

    // Iterate through all subsets of colors
    for (int mask = 1; mask < (1 << colors.size()); mask++) {
        string subset = "";
        unordered_map<char, int> requiredCharCount;

        for (int i = 0; i < colors.size(); i++) {
            if (mask & (1 << i)) { // Check if the color is in the subset
                subset += colors[i];
                for (char c : colors[i]) {
                    requiredCharCount[c]++;
                }
            }
        }

        bool valid = true;

        // Check if there are enough characters to form the colors in the subset
        for (char c : subset) {
            if (charCount[c] < requiredCharCount[c]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            maxColors = max(maxColors, __builtin_popcount(mask)); // Count the number of colors in the subset
        }
    }

    cout << maxColors << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}

