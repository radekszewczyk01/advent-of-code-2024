#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("1_1_input.txt");
    vector<int>V1;
    vector<int>V2;
    int a,b;
    while(input>>a>>b){
        V1.push_back(a);
        V2.push_back(b);
    }
    input.close();
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    long long suma = 0;
    for(int i=0; i<V1.size(); i++){
        suma+=static_cast<long long>(abs(V1[i]-V2[i]));
    }
    cout<<suma;
    return 0;
}