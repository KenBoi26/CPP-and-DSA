// Question 1

#include <iostream>
using namespace std;


int findMax(int arr[], int size){
    int max = arr[0];

    for(int i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}



int main(){
    int arr[] = {1,3,2,4,5,5,4,3,6};

    int size = sizeof(arr)/sizeof(arr[0]);

    int max = findMax(arr, size);

    cout << max;
}

// Question 2

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &str1){
    int left = 0;
    int right = str1.length() - 1;

    while(left < right){
        while(left < right && ! isalpha(str1[left]) && !isdigit(str1[left])){
            left++;
        }
        while(left < right && ! isalpha(str1[right]) && !isdigit(str1[right])){
            right--;
        }

        if(tolower(str1[left]) != tolower(str1[right])){
            return false;
        }

        left++;
        right--;
    }

    return true;
}


int main(){
    
    string str1 = "A man, a plan, a canal, Panama";

    cout << isPalindrome(str1);
    
    
    return 0;
}