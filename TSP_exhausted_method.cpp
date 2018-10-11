#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>  // For srand() and rand()
#include <ctime>
#include <iomanip>
#include "limits.h"

float result_dis = INT_MAX;

class Solution{
    public:
    void TSP(int n,int a[][2], int result_order[]){
        if(n == 0){
            return;
        }
        if(n == 1){
            cout << "order: " << "0" << endl;
            cout << "distance: " << "0" << endl;
            return;
        }
        int order[n];
        for(int i = 0; i < n; i++){
            order[i] = i;
        }
        Perm(1, n, order, a, result_order);
    }
    void Perm(int start, int end, int order[], int a[][2], int result_order[]){
        // get to the end, output one permutation 
        if(start == end){
            float distance = 0;
            int cur = 0;
            // cout << "order: ";
            for(int i = 0; i < end; i++){
                // cout << order[i];
                if(i > 0){
                    distance += sqrt(pow(a[order[i]][0]-a[cur][0],2)
                    +pow(a[order[i]][1]-a[cur][1],2));
                    cur = order[i];
                }
            }
            // cout << endl;
            // add distance from the last location to the starting point(0)
            distance += sqrt(pow(a[0][0]-a[cur][0],2)
                    +pow(a[0][1]-a[cur][1],2));
            if(result_dis > distance){
                result_dis = distance;
                for(int i = 0; i < end; i++){
                    result_order[i] = order[i];
                }
            }
            // cout << "distance: " << distance << endl;
            return;
        }
        // permutation
        for(int i = start; i < end; i++){
            swap(order[start],order[i]);
            Perm(start+1,end,order,a,result_order);
            swap(order[i],order[start]);
        }
    }
};

int main()
{
    int n = 10;
    int a[n][2] = {{19,80},{68,77},{14,47},{61,32},{76,77},{6,68},{43,21},{51,26},{37,83},{73,14}};

    // srand(time(0));  // Initialize random number generator
    Solution b;
    // for(int j = 4; j <= 4; j+=2){
    //     int n = j;
        int result_order[n];
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
        b.TSP(n,a,result_order);
    //     stop = clock();
        cout << "order: ";
        for(int p = 0; p < n; p++){
            cout << result_order[p] << " ";
        }
        cout << endl;
        cout << fixed;
        cout << "distance: " << setprecision(4)<<result_dis << endl;
        // cout << "runtime is: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    // }
    return 0;
}

