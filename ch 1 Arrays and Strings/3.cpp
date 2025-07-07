#include<bits/stdc++.h>
using namespace std;

// brute : tc: O(n) , sc: O(n)
string urlify(string &str){
    string result;
    for(char ch:str){
        if(ch==' '){
            result+="%20";
        }else result+=ch;
    }
    return result;
}

// better: tc: O(), sc: O()
// stringbuilder or vector<char> to reduce string copying
string urlify2(string &str, int trueLen){
    vector<char>result;
    for(int i=0;i<trueLen;i++){
        if(str[i]==' '){
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
        }else result.push_back(str[i]);
    }
    return string(begin(result), end(result));
}

// optimal : char array : tc: O(n), sc: O(1)
void urlify3(char str[], int len){
    int cntSpaces=0;
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            cntSpaces++;
        }
    }
    int index=len+cntSpaces*2;
    str[index]='\0';

    //start replacing spaces with %20 from the end;
    for(int i=len-1;i>=0;i--){
        if(str[i]==' '){
            str[index-1]='0';
            str[index-2]='2';
            str[index-3]='%';
            index-=3;
        }else{
            str[index-1]=str[i];
            index--;
        }
    }
}

int main(){
    // string str;
    char str[100];
    cout<<"Enter string: ";
    // cin>>str;
    cin.getline(str, 100);  // Use getline to read spaces
    int trueLen;
    cout<<"Enter len: ";
    cin>>trueLen;
    // string ans=urlify2(str, trueLen);
    // cout<<ans<<endl;
    urlify3(str, trueLen);
    cout<<str<<endl;
    return 0;
}