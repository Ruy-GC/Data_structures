#include <vector>
#include <iostream>
#include <algorithm>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findSignatureCounts(vector <int> arr) {
  // Write your code here
  vector<int> signatures (arr.size(),0);
  int n = arr.size();
  
  for(int i = 0; i<n; i++){
    if(signatures[i]==0){
      int index = i;
      int length = 0;
      do{
        length ++;
        index = arr[index]-1;
      }while(index != i);
      
      index = i;
      do{
        signatures[index] = length;
        index = arr[index]-1;
      }while(index != i);
    }
  }
  
  
  
  return signatures;
    
    

    
    
  }
    
  













// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  vector <int> arr_1{2, 1};
  vector <int> expected_1{2, 2};
  vector <int> output_1 = findSignatureCounts(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{1, 2};
  vector <int> expected_2{1, 1};
  vector <int> output_2 = findSignatureCounts(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}