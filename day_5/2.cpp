#include<bits/stdc++.h>

using namespace std;

vector<int> parse_1(string linia){
    int mid = 0;
    for(int i=0; i<linia.size(); i++){
        if(linia[i]=='|'){
            mid = i;
        }
    }
    vector<int> ans;
    string a_1 = linia.substr(0, mid);
    string b_1 = linia.substr(mid+1, linia.size()-mid-1);
    int a = stoi(a_1);
    int b = stoi(b_1);
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

vector<int> parse_2(string linia){
    string liczba = "";
    vector<int>ans;
    for(int i=0;i<linia.size(); i++){
        if(linia[i]==','){
            ans.push_back(stoi(liczba));
            liczba = "";
        }
        else liczba +=linia[i];
    }
    ans.push_back(stoi(liczba));
    return ans;
}
int main(){
    ifstream input("input.txt");
    string linia;
    map <int, vector<int>> M;
    bool part = false;
    int suma=0;
    vector<vector<int>>V;
    while(getline(input,linia)){
        if(linia.size()<3){
            part=true;
            continue;
        }
        if(part == false){
            vector<int>x = parse_1(linia);
            M[x[0]].push_back(x[1]);
        }
        if(part==true){
            map <int,bool> odw;
            vector<int>x = parse_2(linia);
            for(int i=0; i<x.size(); i++){
                odw[x[i]] = true;
                bool check = true;
                for(int j=0; j<M[x[i]].size(); j++){
                    if(odw[M[x[i]][j]]==true){
                        check=false;
                        V.push_back(x);
                        break;
                    }
                }
                if(check==false) break;
            }
        }
    }

    for(vector<int> x: V){
        map <int,bool> odw;
        map<int,int>xd;
        for(auto it:x){
            odw[it]=true;
        }
        for(auto it:x){
            xd[it]++;
            for(auto k:M[it]){
                if(odw[k]==true){
                    xd[it]++;
                }
            }
        }
        vector<pair<int,int>> P;
        for(auto it:xd){
            P.push_back({it.second,it.first});
        }
        sort(P.begin(), P.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });

        suma+=P[P.size()/2].second;

    }
    cout<<suma;
    return 0;
}