#include<bits/stdc++.h>
using namespace std;

// brute: tc: O(n^2) , sc: O(n^2)
void rotate1(vector<vector<int>>&matrix){
    int n=matrix.size();
vector<vector<int>>copy_mat(n, vector<int>(n));
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copy_mat[j][n-1-i]=matrix[i][j];
        }
    }
    matrix=copy_mat;
}

// optimal : transpose & reverse : tc: O(n^2), sc: O(1)
void rotate2(vector<vector<int>>&matrix){
 int n=matrix.size();
        // transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse every row basically
        for(int i=0;i<n;i++){
           reverse(matrix[i].begin(), matrix[i].end());
        }
}
void printMatrix(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n; cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"og is :"<<endl;
    printMatrix(matrix);
    // rotate1(matrix);
     rotate2(matrix);
    cout<<"After rotation: "<<endl;
    printMatrix(matrix);
    return 0;
}