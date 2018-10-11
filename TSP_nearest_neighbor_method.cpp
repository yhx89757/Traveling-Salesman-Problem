#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>  // For srand() and rand()
#include <ctime>
#include <iomanip>

class Solution{
    public:
        vector<int> TSP(int n,int a[][2]){
          vector<int> result;// store order of route
          if(n == 0){
              return result;
          }
          result.push_back(0);// starting point is always 0
          if(n == 1){
              return result;
          }
          float total = 0;// store total distance
          int cur = 0;// 0 to 3
          // unvisited points, elements decreasing
          vector<int> unvisited;// value from 0 to 3
          for(int i = 1; i < n; i++){
              unvisited.push_back(i);
          }
          for(int j = 0; j < n-1; j++) {
              // check unvisited
            //   for(int i = 0; i < unvisited.size(); i++){
            //       cout << unvisited.at(i);
            //   }
            //   cout << endl;
              // if only 1 unvisited, than add distance 
              // from the last one to the starting point
              if(unvisited.size() == 1){
                  total += sqrt(pow(a[unvisited[0]][0]-a[0][0],2)+
                  pow(a[unvisited[0]][1]-a[0][1],2));
              }
              // compute distance, elements decresing
              float distance[unvisited.size()] = {};
              for(int i = 0; i < unvisited.size(); i++){
                  distance[i] = sqrt(pow(a[unvisited[i]][0]-a[cur][0],2)+pow(a[unvisited[i]][1]-a[cur][1],2));
              }
            //   // check distance
            //   for(int i = 0; i < unvisited.size(); i++){
            //       cout << distance[i] << endl;
            //   }
              // choose an unvisited point based on the smallest distance
              float smallest;
              for(int i = 0; i < unvisited.size(); i++){
                  if(i == 0){
                      smallest = distance[i];
                      cur = unvisited[i];
                  }else if(smallest > distance[i]){
                      smallest = distance[i];
                      cur = unvisited[i];
                  }
              }
            //   cout << smallest << "haha" << cur << endl;
              // add order
              result.push_back(cur);
              // add distance
              total += smallest;
              // delete point number from the unvisited array
              vector<int>::iterator iter=find(unvisited.begin(),unvisited.end(),cur);
              if(iter!=unvisited.end()) unvisited.erase(iter);
              // check unvisited
            //   for(int i = 0; i < unvisited.size(); i++){
            //       cout << unvisited.at(i);
            //   }
            //   cout << endl;
            // cout << smallest << endl;
          }
          cout << fixed;
          cout << setprecision(4)<<"distance: " << total << endl;
          return result;
        }
};
int main ()
{
    int n;
    cout << "Input numeber of lines" << endl;
    cin >> n;
    int a[n][2];
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    // int n = 4;
    // int a[n][2] = {{3,4},{6,8},{50,8},{11,7}};
    // int a[3][2] = {{0,0},{5,5},{20,17}};
    // srand(time(0));  // Initialize random number generator
    vector<int> re;
    Solution b;
    // for(int j = 4; j <= 4; j+=2){
    //     int n = j;
    //     int a[n][2];
    //     for(int k = 0; k < n; k++){
    //         for(int t = 0; t < 2; t++){
    //             a[k][t] = (rand() % 100) + 1;
    //             // if(t == 1){
    //             //     cout << "(" << a[k][0] << "," << a[k][1] << ")";
    //             // }
    //         }
    //     }
    //     // cout << endl;
    //     double start,stop;
    //     start = clock();
        re = b.TSP(n,a);
    //     stop = clock();
    //     cout << "runtime is: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "order: ";
        for(int i = 0; i < re.size(); i++){
             cout << " " << re.at(i);
        }
        cout << endl;
    // }
    return 0;
}
   



