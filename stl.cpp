#include<bits/stdc++.h>
using namespace std;

//pairs
void explainPair(){
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    //nested pairs
    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout << p1.first << "" << p1.second.first << " " << p1.second.second << endl;
    
    //pair array
    pair<int,int> arr[] = {{1,2}, {2,5}, {5,6}};
    cout << arr[0].first << ' '<< arr[0].second << endl;
}

//arrays are const in nature 
//vectors
void explainVector(){
  vector<int> v;
  v.push_back(1);
  v.emplace_back(2); //pushes the element at the end of the vector and it is faster than push_back

  vector<pair<int, int>> vec; //vector of pairs
  vec.push_back({1,2});
  vec.emplace_back(3,4);

  vector<int> v(5, 10); //vector of size 5 with all elements as 10
  vector<int> v0(5); //vector of size 5 with all elements as 0

  vector<int> v1(3,5); //{5,5,5}
  vector<int> v2(v); //copy of vector v
  //we can always increase the size of the vector

  //how to access elements of a vector
  v1[2]; //5 same as array

  //ways to iterate over a vector - another way to access elements
  vector<int>::iterator it = v.begin(); // v.begin() give memory address of the first element
  it++;
  cout << *it << endl; //5

  //vector having different values
  vector<int> vect{10, 20, 30, 40};
  vector<int>::iterator it1 = vect.begin();
  it1 = it1 + 2;
  cout<< *it1 << endl; //30

  //some more itterators
  vector<int>::iterator it2 = vect.end(); //points to the next of the last element, it not point to 40, if we do it2-- it will point to 40

  cout<< vect.back() << endl; //40

  //how to print the vector using for loop
  for(vector<int>::iterator it3 = vect.begin(); it3 != vect.end(); it3++){
    cout << *it3 << " ";
  }

  //short of writing the above loop
  for(auto it3 = vect.begin(); it3 != vect.end(); it3++){
    cout << *it3 << " ";
  }

  //using for each loop, it is used to access the elements of the vector
  for(auto it4: vect){
    cout<< it4 << " ";
  }

  //how to delete in vector
  vect.erase(vect.begin()+1); //{10, 30, 40}
  vect.erase(vect.begin()+1, vect.begin()+3); //[start, end) - {10, 40}, start is included and end is not included

  //insert in vector
  vect.insert(vect.begin(), 5); //{5, 10, 20, 30, 40}
  vect.insert(vect.begin()+1, 2, 7); //{5, 7, 7, 10, 20, 30, 40}

  //how to insert a vector into another vector
  vector<int> copy(2, 50);
  vect.insert(vect.begin(),copy.begin(),copy.end()); //{50, 50, 5, 7, 7, 10, 20, 30, 40}

  cout << vect.size() << endl; //9
  vect.pop_back(); //{50, 50, 5, 7, 7, 10, 20, 30}
  vect.clear(); //clears the vector, {}
  cout << vect.empty() << endl; //1
}


//list
void explainList(){
  list<int> ls;
  ls.push_back(2); //{2}
  ls.emplace_back(5); //{2, 5}
  ls.push_front(1); //{1, 2, 5} // push_front is used to insert at the beginning of the list, it is cheap than insert in vector
  ls.emplace_front(7); //{7, 1, 2, 5}

  //rest same as vector
}

void explainDeque(){
  deque<int> dq;
  dq.push_back(1); //{1}
  dq.emplace_back(2); //{1, 2}
  dq.push_front(3); //{3, 1, 2}
  dq.emplace_front(4); //{4, 3, 1, 2}

  dq.pop_back(); //{4, 3, 1}
  dq.pop_front(); //{3, 1}
  dq.back(); //1
  dq.front(); //3

  //rest same as vector
}

//it work on last in first out principle
void explainStack(){
  stack<int> st;
  st.push(1); //{1}
  st.push(2); //{1, 2}
  st.push(3); //{1, 2, 3}
  st.push(4); //{1, 2, 3, 4}
  st.push(5); //{1, 2, 3, 4, 5}

  cout << st.top() << endl; //whtat is at the top of the stack - 5
  st.pop(); //{1, 2, 3, 4}
  st.size(); //4
  st.empty(); //false, because stack has 4 elements
  stack<int>st1,st2;
  st1.swap(st2); //swaps the elements of the stack
}

//it works on first in first out principle
void explainQueue(){
  queue<int> q;
  q.push(1); //{1}
  q.push(2); //{1, 2}
  q.push(3); //{1, 2, 3}
  q.push(4); //{1, 2, 3, 4}
  
  cout << q.front() << endl; //1
  cout << q.back() << endl; //4
  q.back()+= 10; //{1, 2, 3, 14}
  q.pop(); //{2, 3, 14} - removes the first element
}

void explainPQ(){
  priority_queue<int> pq; //max heap
  pq.push(5);
  pq.push(1);
  pq.push(10);
  pq.push(30);

  cout << pq.top() << endl; //30 - gives the top element of the heap ie. the maximum element
  pq.pop(); //removes the top element
  cout << pq.top() << endl; //10

  //min heap
  priority_queue<int, vector<int>, greater<int>> pq1;
  pq1.push(5);
  pq1.push(1);
  pq1.push(10);
  pq1.push(30);

  cout << pq1.top() << endl; //1
}

//set is unique and sorted
void explainSet(){
  set<int> st;
  st.insert(1); //{1}
  st.insert(2); //{1, 2}
  st.insert(2); //{1, 2} - 2 is not inserted again because set is unique
  st.insert(3); //{1, 2, 3}
  st.emplace(4); //{1, 2, 3, 4}
  
  auto it = st.find(2); //returns the iterator to the element 2
  st.erase(it); //{1, 3, 4}
  st.erase(4); //{1, 3} 
  st.find(2); //returns st.end() because 2 is not present in the set, st.end() is the memory address after the last element

  int cnt = st.count(3); //1 - returns 1 if the element is present in the set else 0

  set<int> st1 = {1,2,3,4,5};
  auto it1 = st1.find(3);
  auto it2 = st1.find(5);
  st1.erase(it1, it2); //{1, 2, 5}

  //every thing happen in log(n) time
}

//multiset stores in sorted order but unique is not necessary
void explainMultiSet(){
  multiset<int> ms;
  ms.insert(1); //{1}
  ms.insert(1); //{1, 1}
  ms.insert(1); //{1, 1, 1}

  ms.erase(1); // erase all 1's
  ms.erase(ms.find(1)); //erase only one 1 because find returns the iterator to the first 1
  // ms.erase(ms.find(1), ms.find(1) + 2); //erase 2 1's
  // we can't perform arithmatic operations on the iterator of multiset so we use advance function to move the iterator

//   int main(){
//   multiset<int> ms{4,4,4,5,6};
//   auto it = ms.find(4);
//   auto it2 = it;
//   advance(it2, 2);
//   ms.erase(it, it2);
//   for(auto it: ms){
//     cout << it << " ";
//   }
//   return 0;
// }

}

//unordered set is not sorted but it is unique and everything happens in O(1) time and same as set
void explainUnorderedSet(){
  unordered_set<int> ust;
  //lower bound and upper bound is not present in unordered set
}

//map store unique keys in sorted order
void explainMap(){
  map<int, int> mpp;
  map<int, pair<int, int>> mpp1;
  map<pair<int,int>, int> mpp2;

  mpp[1] = 2; //{1:2}
  mpp.emplace(2,3); //{1:2, 2:3}
  mpp.insert({3,4}); //{1:2, 2:3, 3:4}
  mpp2[{4,5}] = 6;

  for(auto it: mpp){
    cout << it.first << " " << it.second << endl;
  }

  //how to access the elements of the map
  cout << mpp[1] << endl; //2
  cout << mpp[5] << endl; //0 - if the key is not present in the map then it will return 0
  
  auto it = mpp.find(2); //returns the iterator to the key 2
  cout << it->second << endl; 

  auto it = mpp.find(5); //returns mpp.end() because 5 is not present in the map
}

//multimap is same as map but it can have duplicate keys
void explainMultiMap(){

}

//unordered map is not sorted but have unique keys and everything happens in O(1) time
void explainUnorderedMap(){

}

bool comp(pair<int, int> p1, pair<int, int> p2){
   if(p1.second < p2.second) return true;
   if(p1.second > p2.second) return false;
   if(p1.first > p2.first) return true;
   return false;
  }
//now lets talk about sorting
void explainExtra(){
  int a[] = {1, 2, 3, 5, 4};
  vector<int> v = {1, 2, 5, 3, 4};
  sort(a, a+5); //sorts the array in ascending order {1, 2, 3, 4, 5}
  sort(v.begin(),v.end()); //sorts the vector in ascending order {1, 2, 3, 4, 5}
  sort(a+2,a+4); //sorts the array from index 2 to 4 {1, 2, 3, 5, 4}
  pair<int, int> p[] = {{1,2}, {2,3}, {1,3}};
  //sort it according to second elements
  //if second elements are same then sort according to first elements
  //first sort in descending order
  
  sort(p, p+3, comp);

  int num = 6;
  int cnt = __builtin_popcount(num); //4 - gives the number of set bits in the binary representation of the number
  long long num1 = 44546546464;
  int cnt1 = __builtin_popcountll(num1); //gives the number of set bits in the binary representation of the number

  // start from sorted to print all the permutations of the string
  string s = "123";
  sort(s.begin(), s.end());
  do{
    cout<< s << endl;
  }while (next_permutation(s.begin(),s.end())); //gives all the permutations of the string
  
  int maxElement = *max_element(a,a+3); //give maximum element in the array
}












