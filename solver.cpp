#include<iostream>
using namespace std;

// Row are horizontal
// Columns are vertical
int grid[9][9] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

// Function that draws the grid
void drawGrid()
{
    cout << "" << endl;
    for(int i = 0; i < 9; i++) 
    {
        if((i == 3) || (i == 6))
        {
            cout << "---------------------" << endl;
        }
        for(int j = 0; j < 9; j++)
        {
            if((j == 3) || (j == 6))
            {
                cout << "| ";
            }
            cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

// Returns bool based on if 'test' is in 'row'
// Returns 0 if value is not in row (horiozontal segment), returns 1 if value is in row
bool isInRow(int row, int test)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[row][i] == test)
        {
            return true;
        }
    }
    return false;
}

// Returns bool based on if 'test' is in 'col'
// Returns 0 if value is not in col (vertical segment), returns 1 if value is in col
bool isInCol(int col, int test)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][col] == test)
        {
            return true;
        }
    }
    return false;
}

// Returns bool bases on if 'test' is in the box based on intput row and col
// Returns 0 if value is not in box (3x3 square segment), returns 1 if value is in box
bool isInBox(int row, int col, int test)
{
    int boxRow = row-row%3;
    int boxCol = col-col%3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[boxRow + i][boxCol + j] == test)
            {
                return true;
            }
        }
    }
    return false;
}

// Function that does the recursion
// Returns 1 if there are no spaces to fill
bool solve()
{
    bool gotValue = false;
    int row = 0; int col = 0; int outOfBoundsCheck = 0;

    // Finds zero
    while(!gotValue && (outOfBoundsCheck < 81))
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                outOfBoundsCheck++;
                if(grid[i][j] == 0)
                {
                    row = i; col = j;
                    gotValue = true;
                    goto endGotValueLoop;

                }
            }
        }
        endGotValueLoop:
            break;
    }

    // If no zero was found return true, else try nums from 1-9 and call solve()
    if(!gotValue)
    {
        return true;
    } else
    {
        for(int i = 1; i < 10; i++)
        {
            if(!isInRow(row, i) && !isInCol(col, i) && !isInBox(row, col, i))
            {
                grid[row][col] = i;
                if(solve() == true)
                    return true;
                solve();
                grid[row][col] = 0;
            }
        }
        return false;
    }
}

int main()
{
    solve();
    drawGrid();
}
