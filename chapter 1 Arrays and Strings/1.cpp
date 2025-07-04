#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

//  brute : tc: O(n^2) sc: O(1)
// bool check(string &str){
// int n=str.length();
// for(int i=0;i<n-1;i++){
//     for(int j=i+1;j<n;j++){
//         if(str[i]==str[j]){
//             return false;
//         }
//     }
// }
// return true;
// }

bool check(string &str){
    int n=str.length();
    sort(begin(str), end(str));
    for(int i=1;i<n;i++){
        if(str[i-1]==str[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin>>str;
    if(check(str)){
        cout<<"All characters are unique."<<endl;
    }else{
        cout<<"Duplicate characters found."<<endl;
    }
    return 0;
}