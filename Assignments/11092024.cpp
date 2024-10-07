// Question 1
// Ques 1: You are given a image in n*m matrix now you have to rotate the image by 90 degree. 
// Input : n=3, m=3 , image[3][3]={[1, 2, 3],[4,5,6],[7,8,9]}. 
// Output =7 4 1
//         8 5 2
//         9 6 3
// Take all input from user.


#include<iostream>
using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    int arr2[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr2[i][j];
        }
    }

    cout << "Rotated Image: " << endl;

    for(int i=0 ;i<m; i++){
        for(int j=n-1; j>=0; j--){
            cout << arr2[j][i] << "\t";
        }

        cout << endl;
    }



    return 0;
}


// Ques 2: Write a C++ program that take 2D array from user and then sort this array. 
// Input n=3, m=3 array=7 4 1
//                      8 5 2
//                      9 6 3

// output :- 1 2 3
//           4 5 6
//           7 8 9

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    
        int n,m;
        cin >> n >> m;
        int arr2[n][m];
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr2[i][j];
            }
        }
    
        int arr[n*m];
        int k = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[k++] = arr2[i][j];
            }
        }
    
        sort(arr, arr+n*m);
    
        k = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr2[i][j] = arr[k++];
            }
        }
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }
    
        return 0;
}