#include<bits/stdc++.h>

using namespace std;

bool czy_rosnace(vector<int> V){
    int x = V[0];
    for(int i=1; i<V.size(); i++){
        if(V[i]-x<1) return false;
        if(V[i]-x>3) return false;
        x = V[i];
    }
    return true;
}
bool czy_malejace(vector<int> V){
    int x = V[0];
    for(int i=1; i<V.size(); i++){
        if(x-V[i]<1) return false;
        if(x-V[i]>3) return false;
        x = V[i];
    }
    return true;
}

bool check(vector<vector<int>>W){
    bool t=false;
    for(vector<int> it:W){
        if(czy_malejace(it)){
            t=true;
            break;
        }
        if(czy_rosnace(it)){
            t=true;
            break;
        }
    }
    if(t==true) return true;
    return false;
}
int main(){
    ifstream input("2_1_input.txt");
    string line;
    int suma=0;
    while(getline(input,line)){
        istringstream iss(line);
        int num;
        vector<int>V;
        while(iss>>num){
            V.push_back(num);
        }
        vector<vector<int>>W(V.size());
        int j=0;
        for(int t=0; t<V.size(); t++){
            for(int k=0; k<V.size(); k++){
                if(k!=j){
                    W[k].push_back(V[j]);
                }
            
            }
            j++;
        }        
        suma+= check(W) ? 1:0; 

    }
    cout<<suma;
    return 0;
}