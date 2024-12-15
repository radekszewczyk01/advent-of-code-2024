#include<bits/stdc++.h>

using namespace std;
map<pair<int,int>,bool> M_base;
map<pair<int,int>,bool> M;
vector<vector<int>>V;

long long solve(int i, int j){
    long long suma=0;
    if(V[i][j]==9){
        if(!M[{i,j}]){
            M[{i,j}]=true;
            return 1;
        }
    }
    if(i-1>=0){
        if(V[i-1][j]==V[i][j]+1){
            suma+=solve(i-1,j);
        }
    }
    if(j-1>=0){
        if(V[i][j-1]==V[i][j]+1){
            suma+=solve(i,j-1);
        }
    }
    if(i+1<V.size()){
        if(V[i+1][j]==V[i][j]+1){
            suma+=solve(i+1,j);
        }
    }
    if(j+1<V[i].size()){
        if(V[i][j+1]==V[i][j]+1){
            suma+=solve(i,j+1);
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
            if(int(it)-48==9) M_base[{iterator_i,iterator_j}]=false;
            x.push_back(int(it)-48);
        }
        V.push_back(x);
    }
    long long suma = 0;
    for(int i=0; i<V.size(); i++){
        for(int j=0; j<V[i].size(); j++){
            if(V[i][j]==0){
                M = M_base;
                suma+=solve(i,j);
            }
        }
    }
    cout<<suma;
    return 0;
}