#include <bits/stdc++.h>

using namespace std;
 
int main(){
    vector<int>ans;
    map<int,int> map_arr;
    map<int,int> map_brr;
    int n,m;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;cin >> x;
        map_arr[x]++;
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        int x;cin >> x;
        map_brr[x]++;
    }
    
    
    for(const auto& pair:map_brr){
        int    key = pair.first;
        int frequency = pair.second;
        auto it = map_arr.find(key);
        if(it!=map_arr.end()){
            if(it->second != frequency){
                ans.push_back(key);
            }
        }
        else ans.push_back(key);
    }
    sort(ans.begin(),ans.end());
    auto unique_values = unique(ans.begin(),ans.end());
    for(auto it = ans.begin();it!=unique_values;++it){
        cout << *it << " ";
    }
    
    
    
    
    return 0;
}
