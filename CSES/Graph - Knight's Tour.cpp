#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

const int N = 8;
int board[N][N];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

inline bool inside(int x,int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

int getDegree(int x,int y){
    int cnt = 0;
    for(int i = 0; i < 8; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(inside(nx,ny) && board[ny][nx] == -1) cnt++;
    }
    return cnt;
}

bool solve(int x,int y,int step){
    board[y][x] = step;
    if(step == N * N - 1) return true;

    vector<pair<int,pair<int,int>>> moves;
    for(int i = 0;i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(inside(nx,ny) && board[ny][nx] == -1)
            moves.push_back({getDegree(nx,ny), {nx,ny}});
    }

    sort(moves.begin(), moves.end());

    for(auto &mv:moves){
        int nx = mv.second.first, ny = mv.second.second;
        if(solve(nx,ny,step+1)) return true;
    }

    board[y][x]=-1;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_n(board, 64, -1);

    int sx, sy;
    cin >> sx >> sy;
    sx--; sy--;

    if(solve(sx,sy,0)){
        for(int i = 0 ;i < N; i++){
            for(int j = 0;j < N; j++)
                cout << board[i][j] + 1 << " ";
            cout << '\n';
        }
    } else cout << "NO SOLUTION\n";
}
