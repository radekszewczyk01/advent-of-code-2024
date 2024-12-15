#include<bits/stdc++.h>

using namespace std;
long long suma;
long long solve(long long x, int iteration){
    if(iteration==25){
        return 1;
    }
    if(x==0){
        return solve(1,iteration+1);
    }
    if(to_string(x).size()%2==0){
        long long suma=0;
        suma += solve(stoll(to_string(x).substr(0, to_string(x).size()/2)), iteration+1);
        suma+=solve(stoll(to_string(x).substr(to_string(x).size()/2, to_string(x).size()/2)), iteration+1);
        return suma;
    }
    return solve(x*2024, iteration+1);
}

int main(){
    ifstream input("input.txt");
    string linia;
    vector<long long>V;
    while(getline(input,linia)){
        string n="";
        for(auto it:linia){
            if(it==' '){
                V.push_back(stoll(n));
                n="";
                continue;
            } 
            n+=it;
        }
        V.push_back(stoll(n));
    }
    long long suma=0;
    for(auto it:V){
        suma+=solve(it,0);
    }
    cout<<suma;
    return 0;
}