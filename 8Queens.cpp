#include<bits/stdc++.h>
using namespace std;

typedef pair<int,vector<vector<int>>> p;

bool checkPos(vector<vector<int>> &v,int row, int col){
    int i, j;
    for (i = 0; i < col; i++) 
        if (v[row][i]) 
            return false; 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (v[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < 8; i++, j--) 
        if (v[i][j]) 
            return false; 
    return true; 
}

void ucs(priority_queue<p,vector<p>,greater<p>> &open, vector<vector<int>> &v){
    open.push(make_pair(0,v));
    int k = 1;
    while(!open.empty()){
        for(int j = 0; j < 8; ++j){
            p storePair = open.top();
            vector<vector<int>> vec = storePair.second;
            int t = storePair.first;
            if(checkPos(vec,j,t)){
                if(t == 7){
                     vec[j][t] = 1;
                     cout << k << endl;
                     ++k;
                     for(auto it : vec){
                        for(auto i : it){
                            if(i==0)
                                cout<<". ";
                            else
                                cout <<"X ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }else{
                    vec[j][t] = 1;
                    open.push(make_pair(t+1,vec));
                }  
            }
        }
        open.pop();        
    }
}


int main(){
    priority_queue<p,vector<p>,greater<p>> open;
    vector<vector<int>> v(8,vector<int>(8,0));
    ucs(open,v);
    return 0;
}