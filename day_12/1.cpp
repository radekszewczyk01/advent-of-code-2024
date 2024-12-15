#include<bits/stdc++.h>

using namespace std;

pair<long long, long long> operator+(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return {a.first + b.first, a.second + b.second};
}

vector<string>V;
vector<vector<bool>> visited;


pair<long long,long long> pole(int i, int j){
    visited[i][j]=true;
    pair<long long, long long> p={1,0};
    if(i>0){
        if(V[i-1][j]==V[i][j] && !visited[i-1][j]){
            p = p + pole(i-1,j);
        }
        if(V[i-1][j]!=V[i][j]){
            p.second++;
        }
    }
    else{
            p.second++;
        }
    if(i<V.size()-1){
        if(V[i+1][j]==V[i][j] && !visited[i+1][j]){
            p = p + pole(i+1,j);
        }
        if(V[i+1][j]!=V[i][j]){
            p.second++;
        }
    }
    else{
            p.second++;
        }
    if(j>0){
        if(V[i][j-1]==V[i][j] && !visited[i][j-1]){
            p = p + pole(i,j-1);
        }
        if(V[i][j-1]!=V[i][j]){
            p.second++;
        }
    }
    else{
            p.second++;
    }
    if(j<V[0].size()-1){
        if(V[i][j+1]==V[i][j] && !visited[i][j+1]){
            p = p + pole(i,j+1);
        }
        if(V[i][j+1]!=V[i][j]){
            p.second++;
        }
    }
    else{
            p.second++;
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