#include<bits/stdc++.h>

using namespace std;

string valid="MAS";
bool ddr(vector<vector<char>>V, int i, int j, int a, int b){
    int k=0;
    for(int t=0; t<valid.size(); t++){
        if(j<0 || i<0 || j>=V[0].size() || i>=V.size()) return false;
        if(V[i][j]!=valid[k]) return false;
        k++;
        i+=a;
        j+=b;
    }
    return true;
}

int sol(vector<vector<char>>V, int i, int j){
    int suma = 0;
    suma+=(ddr(V,i,j,1,1)&&ddr(V,i+2,j,-1,1));
    suma+=(ddr(V,i,j,1,-1)&&ddr(V,i+2,j,-1,-1));
    suma+=(ddr(V,i,j,1,1)&&ddr(V,i,j+2,1,-1));
    suma+=(ddr(V,i,j,-1,1)&&ddr(V,i,j+2,-1,-1));
    return suma;
}

int main(){
    ifstream input("input.txt");
    string linia;
    vector<vector<char>>V;
    while(getline(input,linia)){
        vector<char>w;
        for(char it:linia){
            w.push_back(it);
        }
        V.push_back(w);
    }
    int suma=0;
    for(int i=0; i<V.size(); i++){
        for(int j=0; j<V[0].size(); j++){
            if(V[i][j]==valid[0]) suma+=sol(V, i,j);
        }
    }
    cout<<suma;

    return 0;
}