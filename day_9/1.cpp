#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("input.txt");
    string linia;
    vector<int>l;
    int iterator=-1;
    int col_it=0;
    while(getline(input,linia)){
        linia;
    }
    for(int i=0; i<linia.size(); i++){
        if(i%2==0){
            for(int j=0; j<int(linia[i])-48; j++){
                l.push_back(i/2);
            }
        }
        else{
            for(int j=0; j<int(linia[i])-48; j++){
                l.push_back(-1);
            }
        }
    }
    for(int i=l.size()-1; i>1; ){
        if(i==-1){
            i--;
            continue;
        }
        int rozmiar=1;
        int ostatni=i;
        int obecny = l[i];
        i--;
        while(l[i]==obecny){
            i--;
        }
        for(int j=0; j<=i; j++){
            if(l[j]!=-1)continue;
            int poczatkowy=j;
            j++;
            while(l[j]==-1 && j-poczatkowy<ostatni-i){
                j++;
            }
            if(j-poczatkowy==ostatni-i){
                for(int d=poczatkowy; d<j; d++){
                    l[d]=l[ostatni-(d-poczatkowy)];
                    l[ostatni-(d-poczatkowy)]=-1;
                }
            }
            else{
                continue;
            }
        }
    }
    long long suma = 0;
    for(int i=0; i<l.size(); i++){
        if(l[i]!=-1){
            suma+=static_cast<long long>(i*l[i]);
        }
    }
    cout<<suma;
    return 0;
}