#include<bits/stdc++.h>

using namespace std;
vector<vector<char>> tab(50, vector<char>(50,'.'));
int calc(pair<int,int> st, pair<int,int>nd, pair<int,int> n ){
    int suma=0;
    int div1 = nd.first-st.first;
    int div2 = nd.second-st.second;
    int p1 = nd.first + div1;
    int p2 = nd.second + div2;
    while(p1>=0 && p2>=0 && p1<=n.first && p2<=n.second){
        suma++;
        tab[p1][p2] = '#';
        p1+=div1;
        p2+=div2;
    }
    return suma;
}

int cal_2(pair<int,int> st, pair<int,int>nd, pair<int,int> n ){
    int suma = 0;
    suma+=calc(st, nd, n);
    suma+= calc(nd, st, n);
    return suma;
}
int main(){
    ifstream input("input.txt");
    string linia;
    vector<long long>V;
    map <int, vector<pair<int,int>>> M;
    int iterator=-1;
    int col_it=0;
    while(getline(input,linia)){
        iterator++;
        int col=-1;
        for(char it:linia){
            col++;
            if(col>col_it) col_it=col;
            if(it!='.' && it!='#'){
                M[it].push_back({iterator, col});
            }
        }

    }
    pair<int,int> n = {iterator, col_it};

    int suma=0;
    for(auto itm:M){
        for(int i=0; i<itm.second.size()-1; i++){
            for(int j=i+1; j<itm.second.size(); j++){
                suma+=cal_2(itm.second[i], itm.second[j], n);
                tab[itm.second[i].first][itm.second[i].second] = '#';
                tab[itm.second[j].first][itm.second[j].second] = '#';
            }
        }
    }
    suma = 0;
    for(auto it:tab){
        for(auto i:it){
            if(i=='#') suma++;
            cout<<i;
        }
        cout<<"\n";
    }
    cout<<suma;

    return 0;
}