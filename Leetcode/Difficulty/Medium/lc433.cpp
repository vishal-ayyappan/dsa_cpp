#include <bits/stdc++.h>
using namespace std;

//Minimum Genetic Mutation (StartGene might not be in the bank, but endGene will be in the bank)

int minMutation(string startGene, string endGene, vector<string>& bank) {
    if (startGene == endGene) return 0;
    int n = bank.size();
    if (n == 0) return -1;
    int len = startGene.length();
    vector<char> changeTo {'A', 'C', 'G', 'T'};
    //Store the bank in a hashmap
    unordered_map<string, int> mpp;
    for (int i=0; i<n; i++){
        string s = bank[i];
        mpp[s] = i;
    }
    //Create a visited array
    vector<bool> visited (n, false);
    //Check if the startGene is in the array
    if (mpp.find(startGene) != mpp.end()){
        int idx = mpp[startGene];
        visited[idx] = true;
    }
    //Do a BFS to check the minimum mutations
    int time = 0;
    queue<string> q;
    q.push(startGene);
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            string gene = q.front();
            q.pop();
            if (gene == endGene) return time;
            //Try all possibilities (For each character)
            for (int j=0; j<len; j++){
                char og = gene[j];
                for (int k=0; k<4; k++){
                    gene[j] = changeTo[k];
                    //If it is in the bank and if it is not visited, push it to the queue
                    if (mpp.find(gene) != mpp.end() && !visited[mpp[gene]]){
                        visited[mpp[gene]] = true;
                        q.push(gene);
                    }
                }
                gene[j] = og;
            }
        }
        time++;
    }
    return -1;
}