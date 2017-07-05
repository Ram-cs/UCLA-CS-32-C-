
#include <iostream>
using namespace std;

//FUNCTION PROTOTYPE
bool pathExists(string maze[][10], int nRows, int nCols, int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise



class Coord {
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

//FUNCTION DEFINITION
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    maze[sr][sc] = '#';//initialize the maze
    
    if (sr == er && sc == ec) //if coord point is equal to end coord
            return true;
    
    if ((sr >= 0 && sr-1 <= nRows -1) && (sc >= 0 && sc <= nCols-1)) {//check the boundry
        if (maze[sr-1][sc] == '.') { //move north
            if (pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
                return true;
            }
        }
        
    if ((sr >= 0 && sr <= nRows-1) && (sc + 1 >= 0 && sc + 1 <= nCols -1)) {//check boundry
        if (maze[sr][sc + 1] == '.') { //move east
            if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
                return true;
            }
        }
        
    if ((sr + 1 >= 0 && sr + 1 <= nRows-1) && (sc >= 0 && sc <= nCols-1)) {//check boundry
        if (maze[sr + 1][sc] == '.') { //move south
            if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
                return true;
            }
            
        }
        
    if ((sr >= 0 && sr <= nRows-1) && (sc-1 >= 0 && sc-1 <= nCols-1)) {//check boundry
        if (maze[sr][sc - 1] == '.') { //move west
            if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
                return true;
            }
        }
    return false;
}



