
#include <iostream>
#include <queue>

using namespace std;

//FUNCTION PROTOTYPE
bool pathExists(string maze[][10], int nRows, int nCols, int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise



class Coord
{
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
    queue <Coord> stackQueue; //create the stackQue
    stackQueue.empty();//empty the stack
    Coord startPoint(sr, sc);
    stackQueue.push(startPoint); //push the first corordinate into stack
    maze[sr][sc] = 'X';//initialize the maze
    
    while(stackQueue.empty() == false) { //check if maze is empty
        Coord tempCord = stackQueue.front(); //get the front of the queue
        stackQueue.pop(); //pop the front of queue
        
        int row = tempCord.r();//get the row
        int col = tempCord.c();//get the colm
        if (row == er && col == ec) //if coord point is equal to end coord
            return true;
        if ((row-1 >= 0 && row-1 <= nRows -1) && (col >= 0 && col <= nCols-1)) {//check the boundry
            if (maze[row-1][col] == '.') { //move north
                Coord north(row-1, col); //get the north
                stackQueue.push(north);//push the north into queue
                maze[row-1][col] = 'X';//mark as visited
            }
        }
        
        if ((row >= 0 && row <= nRows-1) && (col + 1 >= 0 && col + 1 <= nCols -1)) {//check boundry
            if (maze[row][col + 1] == '.') { //move east
                Coord east(row, col + 1);//move seast
                stackQueue.push(east);//push east into queue
                maze[row][col + 1] = 'X';//mark as visited
            }
        }
        
        if ((row + 1 >= 0 && row + 1 <= nRows-1) && (col >= 0 && col <= nCols-1)) {//check boundry
            if (maze[row + 1][col] == '.') { //move south
                Coord south(row + 1, col);//move to south
                stackQueue.push(south);//push south coord into queu
                maze[row + 1][col] = 'X';//mark as visited
            }
  
        }
        
        if ((row >= 0 && row <= nRows-1) && (col-1 >= 0 && col-1 <= nCols-1)) {//check boundry
            if (maze[row][col - 1] == '.') { //move west
                Coord west(row, col - 1);//move to west
                stackQueue.push(west);//push west coord into queue
                maze[row][col - 1] = 'X';//mark as visited
            }
        }
       
    }
    
    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
