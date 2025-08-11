#include <bits/stdc++.h>
using namespace std;

//Floyd Warshall Algorithm

void floydWarshall(vector<vector<int>> &dist) {
    //You have been given directed edges.
    //You have to iterate via each path and check the distance, if it is minimum you update
    int n = dist.size();
    for (int via = 0; via < n; via++){
        //from i to j via 'via'
        for (int i= 0; i < n; i++){
            for (int j=0; j < n; j++){
                if (i == via || j == via) continue;
                if (dist[i][via] != 1e8 && dist[via][j] != 1e8){
                    int newDistance = dist[i][via] + dist[via][j];
                    if (newDistance < dist[i][j]){
                        dist[i][j] = newDistance;
                    }
                }
            }
        }
    }
    // //To check if there exists a negative loop
    // for (int i=0; i<n; i++){
    //     if (dist[i][i] != 0){
    //         //This would be a negative loop
    //     }
    // }
}