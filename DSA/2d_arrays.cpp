#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   
}

// max sum of the row in 2D array
#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int max_sum = INT_MIN;
    int max_index = -1;
    for (int i = 0; i < 3; i++){
        int row_sum=0;
        for (int j = 0; j < 3; j++){
            row_sum += arr[i][j];
        }
        if (row_sum > max_sum){
            max_sum = row_sum;
            max_index = i;
        }
    }  

    cout << "The row which has the highest sum is: " << max_index << " with the sum of: " << max_sum;

    return 0;
}


// 2d array wave printing
#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0; i<3; i++){
        if(i%2==0){
            for(int j=0; j<3; j++){
                cout << arr[i][j] << " ";
            }
        }else{
            for(int j=2; j>=0; j--){
                cout << arr[i][j] << " ";
            }
        }
    }
}


// sprial printing of 2D array
#include <iostream>
using namespace std;

int main(){
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int sr = 0;
    int er = 3;
    int sc = 0;
    int ec = 3;

    while(sr <= er && sc <= ec){
        
        for(int i=sc; i<=ec; i++){
            cout << arr[sr][i] << " ";
        }
        sr++;

        
        for(int i=sr; i<=er; i++){
            cout << arr[i][ec] << " ";
        }
        ec--;

        
        for(int i=ec; i>=sc; i--){
            cout << arr[er][i] << " ";
        }
        er--;

        
        for(int i=er; i>=sr; i--){
            cout << arr[i][sc] << " ";
        }
        sc++;
    }
}