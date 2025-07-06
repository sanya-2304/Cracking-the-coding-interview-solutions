#include<bits/stdc++.h>
using namespace std;

// brute - tc: O(n^2), sc: O(1)
// bool isUniq(string &s){
//     int n=s.length();
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(s[i]==s[j]) return false;
//         }
//     }
//     return true;
// }

// better : Sort and Check Neighbors
//  tc: O(n log n), sc: O(1)
// bool isUniq(string &s){
// sort(begin(s), end(s));
// for(int i=1;i<s.size();i++){
//     if(s[i-1]==s[i]){
//         return false;
//     }
// }
// return true;
// }

// optimal : extra bool array of constant space
// tc: O(n), sc: O(1) (128 = constant)
// bool isUniq(string &s){
//     if(s.length()>128) return false;
//     bool visited[128]={false};
//     for(char ch:s){
//         if(visited[ch]) return false;
//         visited[ch]=true;
//     }
//     return true;
// }

// general approach using extra space : HASHMAP
// tc: O(n), sc: O(n)
bool isUniq(string &s){
    unordered_map<char, int>mappy;
    for(char ch:s){
        if(mappy[ch]==1) return false;
        mappy[ch]++;
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    if(isUniq(s)){
        cout<<"Yes uniq";
    }else cout<<"Not uniq";
}