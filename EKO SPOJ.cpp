#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<long long int> trees, long long int m, long long int currentSawBladeHeight){
  long long int woodCollected = 0;
  for(int i = 0; i<trees.size(); i++){
    if(trees[i] > currentSawBladeHeight){
      woodCollected += trees[i] - currentSawBladeHeight;
    }
  }
  return woodCollected>=m; // m is the min amount of wood reqd. by lumberjack
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m){
  long long int start = 0, end = *max_element(trees.begin(), trees.end()), ans = -1; // max_element returns address of max element

  while(start <= end){
    long long int mid = start + (end - start)/2;
    if(isPossibleSol(trees, m, mid)){
      ans = mid;
      start = mid + 1;
    }
    else{
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  long long int n, m;
  cin>>n>>m;
  vector<long long int> trees;
  while(n--){
    long long int height;
    cin>>height;
    trees.push_back(height);
  }
  cout << maxSawBladeHeight(trees, m)<<endl;

  return 0;
}