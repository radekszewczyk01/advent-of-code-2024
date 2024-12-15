#include<bits/stdc++.h>

using namespace std;

pair<long long, long long> operator+(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return {a.first + b.first, a.second + b.second};
}

vector<string>V;
vector<vector<bool>> visited;


int ilosc_zakretow(int startujace_i, int startujace_j, string startujacy_dir,string direction, int i, int j){

    if(i==startujace_i && j==startujace_j,)

    if(direction == "right"){
        if(j<V[i].size()-1){
            if(V[i][j+1]==V[i][j]) {
                return ilosc_zakretow(startujace_i, startujace_j, startujacy_dir, direction, i,j+1);
            }
        }
        else{
            return 1 + ilosc_zakretow(startujace_i, startujace_j, startujacy_dir, "down", i,j);
        }
    }

    return p;
}


int main(){
    ifstream input("input.txt");
    string linia;
    while(getline(input,linia)){
        V.push_back(linia);
    }

    vector<vector<bool>>odw(V.size(), vector<bool>(V[0].size(),false));
    visited = odw;
    long long suma=0;
    for(int i=0; i<V.size(); i++){
        for(int j=0; j<V[i].size(); j++){
            if(visited[i][j]) continue;
            pair<long long, long long>pi = pole(i,j);
            suma+=pi.first*pi.second;
        }
    }
    cout<<suma;

    return 0;
}