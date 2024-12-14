#include<bits/stdc++.h>

using namespace std;

vector<long long> parse(string line){
    int i=0;
    string n1;
    vector<long long> ans;
    while(line[i]!=':'){
        n1+=line[i];
        i++;
    }
    ans.push_back(stoll(n1));
    i+=2;
    n1="";
    for(i; i<line.size(); i++){
        if(line[i]==' '){
            ans.push_back(stoll(n1));
            n1="";
            continue;
        }
        n1+=line[i];
    }
    ans.push_back(stoll(n1));
    return ans;
}

bool solve(long long ans, stack<long long> S, long long suma) {
    if (S.empty()) {
        return ans == suma;
    }

    long long x = S.top();
    S.pop();
    bool a = false, b = false, c = false;
    if (suma != 0) {
        a = solve(ans, S, suma*x);
    }

    b = solve(ans, S, suma+x);

    string s1 = to_string(suma);
    string s2 = to_string(x);
    if (to_string(ans).size()>= (s1+s2).size()) {
        long long concatenated = stoll(s1 + s2);
        c = solve(ans, S, concatenated);
    }



    return a || b || c;
}

int main(){
    ifstream input("input.txt");
    string linia;
    vector<long long>V;
    long long suma=0;
    while(getline(input,linia)){
        V = parse(linia);
        long long ans = linia[0];
        stack<long long>S;
        for(int i=V.size()-1; i>0; i--){
            S.push(V[i]);
        }
        if(solve(V[0], S, 0)) suma+=V[0];
    }

    cout<<suma;

    return 0;
}