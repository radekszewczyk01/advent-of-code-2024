#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("1_1_input.txt");
    vector<int>V;
    map <int,long long>M;
    int a,b;
    while(input>>a>>b){
        V.push_back(a);
        M[b]++;
    }
    long long suma = 0;
    for(int i=0; i<V.size(); i++){
        int x = V[i];
        suma+=static_cast<long long>(x*M[x]);
    }
    cout<<suma;
    return 0;
}