#include <bits/stdc++.h>

using namespace std;




string isBalanced(string s) {
    std::stack<char> cont;
    int lenght = s.length();
    for(int i = 0;i<lenght;i++){
        if(s[i] == '(' || s[i] =='{' || s[i] == '['){
            cont.push(s[i]);
        }
        else if((cont.empty() && s[i] == ')') || (cont.empty()&&  s[i] == '}') ||(cont.empty() &&  s[i] == ']'))return "NO";
        else{
            if(s[i] == ')'){
                char element = cont.top();
                cont.pop();
                if(element == '(')continue;
            }
            if(s[i] == '}'){
                char element = cont.top();
                cont.pop();
                if(element == '{')continue;
            }
            if(s[i] == ']'){
                char element = cont.top();
                cont.pop();
                if(element == '[')continue;
            }
            else return "NO";
        }
        
    }
    if (!cont.empty())return "NO";
    return "YES";
    
}


