#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Add any helper functions you may need here


vector <int> findMedian(vector <int> arr) {
  // Write your code here
  vector<int> numbers (1,arr[0]);
  vector<int> medians;
  int median = 0;
  int n = 0;
  
  for(int i = 0; i < arr.size(); i++){

    sort(numbers.begin(),numbers.end());
    if(numbers.size() == 1){
      
      medians.push_back(numbers[i]);
      
    }else if(numbers.size()%2 == 0){
      
      n = numbers.size() /2;
      median = (numbers[n-1] + numbers[n])/2;
      medians.push_back(median);
      
    }else{
      
      n = (numbers.size())/2;
      median = numbers[n];
      medians.push_back(median);
      
    }
    numbers.push_back(arr[i+1]);
    
  }
  
  return medians;
  
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}