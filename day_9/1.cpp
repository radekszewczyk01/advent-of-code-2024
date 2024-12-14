#include<bits/stdc++.h>

using namespace std;

std::string addStrings(string num1, string num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string multiplyStringByInt(const std::string& num, int factor) {
    if (factor == 0 || num == "0") return "0";
    std::string result;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int digit = num[i] - '0';
        int prod = digit * factor + carry;
        carry = prod / 10;
        result.push_back((prod % 10) + '0');
    }
    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}


int main(){
    ifstream input("input.txt");
    string linia;
    vector<pair<int,int>>V;
    int iterator=-1;
    int col_it=0;
    while(getline(input,linia)){
        for (int i = 0; i < linia.size(); i++)
        {
            if(i%2==0){
                V.push_back({i/2, int(linia[i])-48});
            }
        }
        
    }

    int k=0;
    long long suma = 0;
    int d=0;
    for(auto it:V){
        if(it!=-1){
        long long term = static_cast<long long>(k*it);
        suma = term+suma;
        }
        k++;
    }
    cout<<"\n"<<suma;
    return 0;
}