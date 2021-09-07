#include <vector>
#include <iostream>

using namespace std;
// Write any include statements here

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
// Write your code here
  vector<long long> seats (N,0);
  int nseats = 0;
  
  for(int i = 0; i< M; i++){
    seats[S[i]-1] = 1;
  }
  
  bool add = false;
  for (int i = 0; i < N ; i++){
     for(int j = 1; j <= K; j++){

      if(i == 0){
          if (seats[i + j] == 0){
              add = true;
          }else{
              add = false;
          }
      } else if (i == N-1){
          if (seats[i - j] == 0){
              add = true;
          }else{
              add = false;
          }
      } else if(seats[i - j] == 0 && seats[i + j] == 0){
        add = true;
      }else{
        add = false;
        break;
      }
    }
    
    if (add){
      seats[i] = 1;
      nseats += 1;
    }
  }

  nseats -= M;

  return nseats;
}

int main(){

    vector<long long> S;
    S.push_back(11);
    S.push_back(6);
    S.push_back(14);

    long long N = 15;
    long long K = 2;
    int M = 3;
    cout<<getMaxAdditionalDinersCount(N,K,M,S);
}