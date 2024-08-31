// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  vector<int> arr = {1,2,3,4,5,1,1,1,2,3,4,4,5,5,5,5,7,6,6,7,8,8,7};
  int max=INT_MIN;
  int s_max = INT_MIN;
  for(int i:arr){
      if(i > max){
          s_max = max;
          max = i;
      }else if(i<max && i>s_max){
          s_max = i;
      }
  }
  
  cout << max << " " << s_max;

    return 0;
}