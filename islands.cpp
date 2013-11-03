#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

template<int ROW,int COL>
bool isSafe(int (&M)[ROW][COL],bool (&visited)[ROW][COL],int i,int j)
{
   if(i >= 0 && i < ROW && j >=0 && j < COL && M[i][j] && !visited[i][j])
       return true;
   return false;
}
    
template<int ROW,int COL>
void DFS(int (&M)[ROW][COL],bool (&visited)[ROW][COL],int i,int j)
{
    static int x[] = {-1,1 ,1,-1,0, 0,1,-1};
    static int y[] = {-1,1,-1, 1,1,-1,0, 0};

    visited[i][j] = true;
    
    for(int k = 0;k < 8; k++)
    {
        if(isSafe(M,visited,i + x[k], j + y[k]))
        {
            DFS(M,visited,i + x[k], j + y[k]);
        }
    
    }
}

template<int ROW, int COL>
int countIslands(int (&M)[ROW][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0 ,sizeof(visited));

    int count = 0;

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(M[i][j] && !visited[i][j] )
            {
                count++;
                DFS(M,visited,i,j);
            }
        }
    }
return count;
}

int main()
{
    int M[][5] =
                    {
                        {1,1,0,0,0},
                        {0,1,0,0,1},
                        {1,0,0,1,1},
                        {0,0,0,0,0},
                        {1,0,1,0,1}
                    };
    cout << countIslands(M) << endl;
    return 0;
}
