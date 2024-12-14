#include<bits/stdc++.h>

using namespace std;

int check(string l, int* it){
    string valid = "mul(,)";
    string n1="";
    string n2="";
    int k=0;
    for(;;){
        if(*it>=l.size()) return -1;
        if(valid[k]==l[*it]){
            if(valid[k]=='('){
                for(;;){
                    (*it)++;
                    if(*it>=l.size()) return -1;
                    int x=(int)l[*it]-48;
                    if(x>=0&&x<=9){
                        n1+=l[*it];
                    }
                    else{
                        *it=*it-1;
                        break;
                    }
                }
            }
            if(valid[k]==','){
                for(;;){
                    (*it)++;
                    if(*it>=l.size()) return -1;
                    int x=(int)l[*it]-48;
                    if(x>=0 && x<=9){
                        n2+=l[*it];
                    }
                    else{
                        *it=*it-1;
                        break;
                    }
                }
            }
            if(valid[k]==')'){
                if(n1.size()>0 && n2.size()>0) return stoi(n1)*stoi(n2);
                else return -1;
            }
        }
        else{
            return -1;
        }
        k++;
        *it = *it + 1;
    }
    return -1;
}

int dodo(string l, int it){
    string valid2 = "don't()";
    string valid1 = "do()";
    int k=0;
    int i=it;
    for(;;){
        if(i>=l.size()) return 0;
        if(valid1[k]==')') return 1;
        if(valid1[k]!=l[i]) break;
        i++;
        k++;
    }
    k=0;
    i=it;
    for(;;){
        if(i>=l.size()) return 0;
        if(valid2[k]==')') return 2;
        if(valid2[k]!=l[i]) break;
        i++;
        k++;
    }
    return 0;
}

int main(){
    ifstream input("input.txt");
    string linia;
    int suma=0;
    string recent="";
    while(getline(input,linia)){
        for(int i=0; i<linia.size(); i++){
            if(linia[i]=='d'){
                if(dodo(linia, i)==1) recent="do";
                if(dodo(linia, i)==2) recent="dont";
            }
            if(linia[i]=='m'){
                int x=check(linia, &i);
                if(x>-1){
                    if(recent == "do" || recent == "") suma+=x;
                }
            }        
        }
    }
    cout<<suma;
    return 0;
}