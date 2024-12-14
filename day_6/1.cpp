#include<bits/stdc++.h>

using namespace std;


bool check_if_loop(vector<string> w, string direction){
    for(auto it:w){
        if(it==direction) return true;
    }
    return false;
}

int lupa(vector<vector<char>> V, pair<int,int> current_position){
    vector<vector<vector<string>>> odw(V.size(), vector<vector<string>>(V[0].size(), vector<string>(0)));
    string current_direction = "up";
    while((!(current_direction=="up" && current_position.first==0)) && (!(current_direction=="left" && current_position.second==0)) && (!(current_direction=="right" && current_position.second==V[0].size()-1)) && (!(current_direction=="down" && current_position.first==V.size()-1))){
        if(check_if_loop(odw[current_position.first][current_position.second], current_direction)){
            return true;
        }
        odw[current_position.first][current_position.second].push_back(current_direction);
        if(current_direction=="up" && V[current_position.first-1][current_position.second]=='#'){
            current_direction = "right";
            continue;
        }
        if(current_direction=="right" && V[current_position.first][current_position.second+1]=='#'){
            current_direction = "down";
            continue;
        }
        if(current_direction=="down" && V[current_position.first+1][current_position.second]=='#'){
            current_direction = "left";
            continue;
        }
        if(current_direction=="left" && V[current_position.first][current_position.second-1]=='#'){
            current_direction = "up";
            continue;
        }
        
        if(current_direction=="up" && V[current_position.first-1][current_position.second]=='.'){
            current_position.first-=1;
            continue;
        }
        if(current_direction=="right" && V[current_position.first][current_position.second+1]=='.'){
            current_position.second+=1;
            continue;
        }
        if(current_direction=="down" && V[current_position.first+1][current_position.second]=='.'){
            current_position.first+=1;
            continue;
        }
        if(current_direction=="left" && V[current_position.first][current_position.second-1]=='.'){
            current_position.second-=1;
            continue;
        }
    }
    return false;

}

int main(){
    ifstream input("input.txt");
    string linia;
    vector<vector<char>>V;
    int iterator=-1;
    pair<int,int> current_position = {0,0};
    while(getline(input,linia)){
        vector<char>x;
        V.push_back(x);
        iterator++;
        int current_position_col=-1;
        for(char it:linia){
            current_position_col++;
            if(it=='.') V[iterator].push_back('.');
            if(it=='#') V[iterator].push_back('#');
            if(it=='^' || it=='>' || it=='<' || it=='v'){
                current_position = {iterator, current_position_col};
                V[iterator].push_back('.');
            }
        }
    }
    int suma = 0;
    for(int i=0; i<V.size(); i++){
        for(int j=0; j<V[0].size(); j++){
            if(i==current_position.first && j==current_position.second) continue;
            vector<vector<char>>V1 = V;
            if(V1[i][j]=='#') continue;;
            V1[i][j] = '#';
            if(lupa(V1, current_position)) suma++;
        }
    }
    cout<<suma;
    
    
    return 0;
}