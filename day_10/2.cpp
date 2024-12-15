#include<bits/stdc++.h>

using namespace std;
map<pair<int,int>,vector<vector<pair<int,int>>>> M_base;
map<pair<int,int>,vector<vector<pair<int,int>>>> M;
vector<vector<int>>V;

bool czy_zawiera(vector<vector<pair<int,int>>> Mi, vector<pair<int,int>>odw){
    for(auto it:Mi){
        bool check=true;
        for(int i=0; i<odw.size(); i++){
            if(odw[i]!=it[i]){
                check = false;
                break;
            }
        }
        if(check){
            return true;
        }
    }
    return false;
}

long long solve(int i, int j, vector< pair<int,int> >odw){
    long long suma=0;
    if(V[i][j]==9){
        if(!czy_zawiera(M[{i,j}],odw)){
            M[{i,j}].push_back(odw);
            return 1;
        }
    }
    if(i-1>=0){
        if(V[i-1][j]==V[i][j]+1){
            vector<pair<int,int>> odw1 = odw;
            odw1.push_back({i-1,j});
            suma+=solve(i-1,j, odw1);
        }
    }
    if(j-1>=0){
        if(V[i][j-1]==V[i][j]+1){
            vector<pair<int,int>> odw1 = odw;
            odw1.push_back({i,j-1});
            suma+=solve(i,j-1,odw1 );
        }
    }
    if(i+1<V.size()){
        if(V[i+1][j]==V[i][j]+1){
            vector<pair<int,int>> odw1 = odw;
            odw1.push_back({i+1,j});
            suma+=solve(i+1,j, odw1);
        }
    }
    if(j+1<V[i].size()){
        if(V[i][j+1]==V[i][j]+1){
            vector<pair<int,int>> odw1 = odw;
            odw1.push_back({i,j+1});
            suma+=solve(i,j+1,odw1);
        }
    }
    return suma;
}

int main(){
    ifstream input("input.txt");
    string linia;

    int iterator_i=-1;
    while(getline(input,linia)){
        iterator_i++;
        vector<int>x;
        int iterator_j=-1;
        for(auto it:linia){
            iterator_j++;
            vector<vector<pair<int,int>>> vp;
            if(int(it)-48==9) M_base[{iterator_i,iterator_j}]=vp;
            x.push_back(int(it)-48);
        }
        V.push_back(x);
    }
    long long suma = 0;
    for(int i=0; i<V.size(); i++){
        for(int j=0; j<V[i].size(); j++){
            if(V[i][j]==0){
                M = M_base;
                vector<pair<int,int>>odw;
                odw.push_back({i,j});
                suma+=solve(i,j,odw);
            }
        }
    }
    cout<<suma;
    return 0;
}