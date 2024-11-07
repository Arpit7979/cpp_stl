#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false;
  if(p1.first > p2.first) return true;
  return false;
}

int main(){
 string s = "231";
  sort(s.begin(), s.end());
  do{
    cout<< s << endl;
  }while (next_permutation(s.begin(),s.end())); 
  return 0;
}