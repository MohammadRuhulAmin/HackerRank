#include<bits/stdc++.h>
using namespace std;

string is_hackerrank(string str){
    string basic_string = "hackerrank";
    int index_greater_than = -1;
    for(int i = 0;i<basic_string.size();i++){
        char s = basic_string[i];
        bool found_pair = false;
        for(int j = 0;j<str.size();j++){
            if(index_greater_than<j){
                if(s == str[j]){
                    index_greater_than  = j;
                    found_pair = true;
                    break;
                }
                else continue;
            }
        }
        if(!found_pair)return "NO";
        
            
    }
    return "YES";
}

int main(){
    int testcase;
    cin >> testcase;
    for(int i= 1;i<=testcase;i++){
        string str;
        cin >> str;
        cout << is_hackerrank(str) << endl;
    }
    
    
    return 0;
}
