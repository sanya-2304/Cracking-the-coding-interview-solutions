#include<bits/stdc++.h>
using namespace std;

// brute : tc: O(n log n + n × n!) = O(n × n!), sc: 
bool compare1(string s1, string s2){
    if(s1.length()!=s2.length()) return false;
    sort(s1.begin(), s1.end());
    do{
        if(s1==s2) return true;
    }while(next_permutation(begin(s1), end(s1)));
    return false;
}

// better: in place sorting
// tc: O(n log n), sc:O(1)
bool compare2(string s1, string s2){
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    return s1==s2;
}

// optimal tc: O(n) , sc: O(1) == 2* 128 constant space
bool compare3(string s1, string s2){
    if(s1.length()!=s2.length()) return false;
    vector<int> cnt1(128, 0);
    vector<int> cnt2(128, 0);
    for(char ch:s1){
        cnt1[ch]++;
    }
    for(char ch:s2){
        cnt2[ch]++;
    }
    return cnt1==cnt2;
}
// optimal tc: O(n) , sc: O(1) == 1* 128 constant space
bool compare4(string s1, string s2){
    if(s1.length()!=s2.length()) return false;
    vector<int> cnt1(128, 0);
    for(char ch:s1){
        cnt1[ch]++;
    }
    for(char ch:s2){
        cnt1[ch]--;
        if(cnt1[ch]<0) return false;
    }
    return true;
}

int main(){
    string s1, s2;
    cout<<"enter string1: ";
    cin>>s1;
    cout<<"enter string2: ";
    cin>>s2;
    if(compare1(s1, s2)) cout<<"Two strings are permutation."<<endl;
    else cout<<"No Permutation"<<endl;
}