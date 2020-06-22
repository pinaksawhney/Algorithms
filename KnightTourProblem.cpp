#include <iostream>
#include <vector>
#define N 8

using namespace std;

/** utility function to check if safe for knight to make a move */
int is_safe(int x, int y, int sol[N][N]) {
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y] == -1);
}

/** utility function to print solution */
void print_Knight_Path(int sol[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}


/** recursive function to solve KT problem */
int solveKTutil(int x, int y, int sol[N][N], int xmove[N], int ymove[N], int movei) {

    if(movei == N*N)
        return 1;
    int next_x = 0;
    int next_y = 0;

    for(int k=0; k<N; k++) {
        next_x = x + xmove[k];
        next_y = y + ymove[k];
        if(is_safe(next_x, next_y, sol)){
            sol[next_x][next_y] = movei;
            if(solveKTutil(next_x, next_y, sol, xmove, ymove, movei+1) == 1)
                return 1;
        }
    }
    sol[x][y]=-1;
    return 0;
}

int solveKT() {
    int sol[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sol[i][j] = -1;
        }
    }

    int xmove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;
    if (solveKTutil(0, 0, sol, xmove, ymove, 1) == 0) {
        cout << "NO SOL";
        return 0;
    }
    else
        print_Knight_Path(sol);
    return 1;
}


int main() {

    solveKT();
    return 0;
}
