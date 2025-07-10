#include<bits/stdc++.h>
using namespace std;

// brutest : tc: O(n*m(n+m)) sc: O(n*m);
// void setMatZero(vector<vector<int>>&matrix, int n, int m){
//     vector<vector<int>>copy_mat=matrix;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     for(int k=0;k<n;k++){
//                         copy_mat[k][j]=0;
//                     }
//                     for(int k=0;k<m;k++){
//                         copy_mat[i][k]=0;
//                     }
//                 }
//             }
//         }
//         matrix=copy_mat;
// }

// brute again, but better brute as its not taking extra space
// tc: O(n*m*(n+m)) + O(n*m), sc:o(1)
// void setMatZero(vector<vector<int>>&matrix, int n, int m){
//  for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     for(int k=0;k<n;k++){
//                        if(matrix[k][j]!=0){
//                          matrix[k][j]=-1001001;
//                        }
//                     }
//                     for(int k=0;k<m;k++){
//                        if( matrix[i][k]!=0){
//                          matrix[i][k]=-1001001;
//                        }
//                     }
//                 }
//             }
//         }
//        for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]==-1001001){
//                 matrix[i][j]=0;
//             }
//         }
//        }
// }

// better, taking row and col 1d arrays : tc: O(n*m), sc: O(n+m)
// void setMatZero(vector<vector<int>>&matrix, int n, int m){
//      vector<bool> row(n, false);
//         vector<bool> col(m, false);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=true;
//                     col[j]=true;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(row[i]==true || col[j]==true){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
// }
 
// optimal approach: taking extra 1d row and col but inside matrix 
//  tc:O(n*m) , sc: O(1)
void setMatZero(vector<vector<int>>&matrix, int n, int m){
     int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else col0=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
             if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
}

void printMatrix(vector<vector<int>>&matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int m;
    cout<<"Enter m: ";
    cin>>m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"OG is "<<endl;
    printMatrix(matrix, n, m);
    setMatZero(matrix, n, m);
    cout<<"After setting row col zero is "<<endl;
    printMatrix(matrix, n, m);
    return 0;
}