#include <bits/stdc++.h>
using namespace std;

unordered_map<string, long long> memo; 

long long solve(long long x, int iteration) {
    if (iteration == 75) { 
        return 1;
    }

    string key = to_string(x) + "_" + to_string(iteration);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (x == 0) {
        return memo[key] = solve(1, iteration + 1);
    }

    string s = to_string(x);
    if (s.size() % 2 == 0) {
        long long half_size = s.size() / 2;
        long long left = stoll(s.substr(0, half_size));
        long long right = stoll(s.substr(half_size));
        return memo[key] = solve(left, iteration + 1) + solve(right, iteration + 1);
    }

    return memo[key] = solve(x * 2024, iteration + 1);
}

int main() {
    ifstream input("input.txt");
    string linia;
    vector<long long> V;

    while (getline(input, linia)) {
        string n = "";
        for (auto it : linia) {
            if (it == ' ') {
                V.push_back(stoll(n));
                n = "";
                continue;
            }
            n += it;
        }
        V.push_back(stoll(n));
    }

    long long suma = 0;
    for (auto it : V) {
        suma += solve(it, 0);
    }
    cout << suma;
    return 0;
}
