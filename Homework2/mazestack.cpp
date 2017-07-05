
#include <iostream>
#include <stack>

using namespace std;

//FUNCTION PROTOTYPE
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);
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
    stack <Coord> stackCord; // crate a stack of Coord
    stackCord.empty();
    Coord startPoint(sr, sc); // assign the first of the stack value
    stackCord.push(startPoint); //push the first corordinate into stack
    maze[sr][sc] = 'X';
    
    while(stackCord.empty() == false) {
        Coord tempCord = stackCord.top();//storing the top stack
        stackCord.pop(); //pop the top stack
        
        int row = tempCord.r(); // store the popped row
        int col = tempCord.c(); // store the popped colm
        
        if (row == er && col == ec) //checking if popped stack is at the end
            return true;
    
        if ((row-1 >= 0 && row-1 <= nRows -1) && (col >= 0 && col <= nCols-1)) {//check boundries
            if (maze[row-1][col] == '.') { //move north
                Coord north(row-1, col); //store north coord
                stackCord.push(north); //push north coord into stack
                maze[row-1][col] = 'X'; // mark visited
            }
        }
        
        if ((row >= 0 && row <= nRows-1) && (col + 1 >= 0 && col + 1 <= nCols -1)) {//check boundries
            if (maze[row][col + 1] == '.') { //move east
                Coord east(row, col + 1); //store east coord
                stackCord.push(east); //push in the stack
                maze[row][col + 1] = 'X'; // mark visited
            }
 
        }
        
        if ((row + 1 >= 0 && row + 1 <= nRows-1) && (col >= 0 && col <= nCols-1)) {//check boundries
            if (maze[row + 1][col] == '.') { //move south
                Coord south(row + 1, col); //store south coord
                stackCord.push(south); //store south in stack
                maze[row + 1][col] = 'X'; //mark visited
            }
 
        }
        
        if ((row >= 0 && row <= nRows-1) && (col-1 >= 0 && col-1 <= nCols-1)) {//check boundries
            if (maze[row][col - 1] == '.') { //move west
                Coord west(row, col - 1); //store west coord
                stackCord.push(west); //push west coord into the stack
                maze[row][col - 1] = 'X'; //mark visited
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
 
