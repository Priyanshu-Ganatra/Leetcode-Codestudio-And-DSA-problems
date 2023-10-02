#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> cRanks, int nP, int currentMaxTimeToCompleteOrder){
  int currP = 0; // initial cooked prata count
  for(int i = 0; i < cRanks.size(); i++){
    int R = cRanks[i], j = 1;
    int timeTaken = 0;

    while(true){
      if(timeTaken + j*R <= currentMaxTimeToCompleteOrder){
        currP++;
        timeTaken += j*R;
        j++;
      }
      else{ // if a cook takes more time than the currentMaxTimeToCompleteOrder then stop
        break;
      }
    }
    if(currP >= nP){
      return true;
    }
  }
  return false;
}

int minTimeToCompleteOrder(vector<int> cRanks, int nP){ // nP = no. of pratas to cook
  int start = 0, highestRank = *max_element(cRanks.begin(), cRanks.end());
  // suppose if we give 10 pratas of the order to the most inefficient cook i.e cook with highestRank R, then 
  // the total time taken would be 1R + 2R + 3R + ... + nP*R -> taking R common -> R(1+2+3+4+...+nP)
  // i.e. R[nP*(nP+1)/2] ....sum of nP pratas * cook with highestRank, which will be the end limit of
  // our answer, as the most inefficient cook (one with highest rank) is trying to cook all the pratas
  int end = highestRank * (nP * (nP + 1)/2);
  int ans = -1;

  while(start<=end){
    int mid = (start+end)/2;
    if(isPossibleSol(cRanks, nP, mid)){
      ans = mid;
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  int t; cin>>t;
  while(t--){
    int nP, nC;
    cin >> nP >> nC;
    vector<int> cRanks;
    while(nC--){
      int R;
      cin>>R;
      cRanks.push_back(R);
    }

    cout << minTimeToCompleteOrder(cRanks, nP) << endl;
  }
  return 0;
}