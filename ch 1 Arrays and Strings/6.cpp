#include<bits/stdc++.h>
using namespace std;

void compressString(string &str){
int j=0, i=0, n=str.length();
while(i<n){
    int cnt=0;
    char cur_char=str[i];
    while(i<n && cur_char==str[i]){
        i++; cnt++;
    }
    str[j]=cur_char;
    j++;
    //now assign cnt
    if(cnt>1){
        string count=to_string(cnt);
        for(char ch: count){
            str[j]=ch;
            j++;
        }
    }
}
 str.resize(j);
}
int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    compressString(str);
    cout<<str<<endl;
    return 0;
}