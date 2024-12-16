#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
    return {a.first - b.first, a.second - b.second};
}

bool operator==(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first == b.first && a.second == b.second);
}

vector<string> V;
vector<vector<bool>> visited;
vector<pair<pair<int, int>, pair<int, int>>> edges;

pair<int, int> pole(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    pair<int, int> p = {1, 0}; // {pole powierzchni, liczba krawędzi}

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; // Używamy poprawnego odwołania
        q.pop();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions) {
            int dx = dir.first, dy = dir.second;
            int nx = x + dx, ny = y + dy;

            // Jeśli wychodzimy poza tablicę
            if (nx < 0 || ny < 0 || nx >= V.size() || ny >= V[0].size()) {
                edges.push_back({{x, y}, {dx, dy}});
                p.second++;
                continue;
            }

            if (V[nx][ny] == V[x][y] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                p.first++; // Zwiększamy pole powierzchni
            } else if (V[nx][ny] != V[x][y]) {
                edges.push_back({{x, y}, {dx, dy}});
                p.second++; // Liczymy krawędź
            }
        }
    }

    return p;
}

int substract_edges() {
    int suma=0;;
    set<pair<pair<int, int>, pair<int, int>>> widziane;
    for (int i=0; i<edges.size(); i++) {
       pair<int,int>cords = edges[i].first;
       pair<int,int>direc = edges[i].second;
       for(pair<pair<int, int>, pair<int, int>> it: widziane){
            if(it.first == cords && it.second == direc) continue;
            widziane.insert(edges[i]);
            if(direc.second==0){

            }
       }
    }
    return suma;

}


int main() {
    ifstream input("input.txt");
    string linia;
    while (getline(input, linia)) {
        V.push_back(linia);
    }

    visited = vector<vector<bool>>(V.size(), vector<bool>(V[0].size(), false));

    int suma = 0;
    for (int i = 0; i < V.size(); i++) {
        for (int j = 0; j < V[i].size(); j++) {
            if (visited[i][j]) continue;

            edges.clear(); // Zerujemy krawędzie
            pair<int, int> pi = pole(i, j);
            suma += pi.first * (pi.second - substract_edges());
            break;
        }
        break;
    }

    cout << suma;

    return 0;
}
