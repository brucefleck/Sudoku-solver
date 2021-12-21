#include <iostream>
using namespace std;

// Global variables and arrays
short grid[9][9] = {
        {0, 0, 0, 1, 0, 9, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0}
    };

short gridStats[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

short sqNum[9][4] = {
        {0, 2, 0, 2},
        {0, 2, 3, 5},
        {0, 2, 6, 8},
        {3, 5, 0, 2},
        {3, 5, 3, 5},
        {3, 5, 6, 8},
        {6, 8, 0, 2},
        {6, 8, 3, 5},
        {6, 8, 6, 8}
    };

// Functions
void printGrid() {
    for(short i=0; i<3; ++i) {
        cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << " | ";
        cout << grid[i][3] << " " << grid[i][4] << " " << grid[i][5] << " | ";
        cout << grid[i][6] << " " << grid[i][7] << " " << grid[i][8] << endl;
    }
    cout << "------+-------+------" << endl;
    for(short i=3; i<6; ++i) {
        cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << " | ";
        cout << grid[i][3] << " " << grid[i][4] << " " << grid[i][5] << " | ";
        cout << grid[i][6] << " " << grid[i][7] << " " << grid[i][8] << endl;
    }
    cout << "------+-------+------" << endl;
    for(short i=6; i<9; ++i) {
        cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << " | ";
        cout << grid[i][3] << " " << grid[i][4] << " " << grid[i][5] << " | ";
        cout << grid[i][6] << " " << grid[i][7] << " " << grid[i][8] << endl;
    }
    cout << endl;
}

short* checkRow(short row) {
    short *ans = new short[9];
    short count = 0;
    bool num;
    for(short i=0; i<9; ++i) {
        num = true;
        for(short j=0; j<9; ++j) {
            if(grid[row][j] == i+1) {
              num = false;
              break;
            }
        }
        if(num) {
            ans[count] = i+1;
            ++count;
        }
    }
    return ans;
}

short* checkColumn( short col) {
    short *ans = new short[9];
    bool num;
    short count = 0;
    for(short i=0; i<9; ++i) {
        num = true;
        for(short j=0; j<9; ++j) {
            if(grid[j][col] == i+1) {
              num = false;
              break;
            }
        }
        if(num) {
            ans[count] = i+1;
            ++count;
        }
    }
    return ans;
}

short quadrant(short x, short y) {
    short square;
    if((0 <= x && x <= 2) && (0 <= y && y <= 2)) {
        square = 0;
    } else if((3 <= x && x <= 5) && (0 <= y && y <= 2)) {
        square = 1;
    } else if((6 <= x && x <= 8) && (0 <= y && y <= 2)) {
        square = 2;
    } else if((0 <= x && x <= 2) && (3 <= y && y <= 5)) {
        square = 3;
    } else if((3 <= x && x <= 5) && (3 <= y && y <= 5)) {
        square = 4;
    } else if((6 <= x && x <= 8) && (3 <= y && y <= 5)) {
        square = 5;
    } else if((0 <= x && x <= 2) && (6 <= y && y <= 8)) {
        square = 6;
    } else if((3 <= x && x <= 5) && (6 <= y && y <= 8)) {
        square = 7;
    } else if((6 <= x && x <= 8) && (6 <= y && y <= 8)) {
        square = 8;
    }
    return square;
}

short* checkSquare(short sqr) { //Input quadrant function
    short *ans = new short[9];
    short count = 0;
    bool num;
    for(short k=0; k<9; ++k) {
        num = true;
        for(short i=sqNum[sqr][0]; i<sqNum[sqr][1]+1; ++i) {
            for(short j=sqNum[sqr][2]; j<sqNum[sqr][3]+1; ++j) {
                if(grid[i][j] == k+1) {
                  num = false;
                  break;
                }
            }
            if(!num) break;
        }
        if(num) {
            ans[count] = k+1;
            ++count;
        }
    }
    return ans;
}

short* possibleNums(short x, short y) {
  //Creates and fills arrays with the answers
  short *RAarr = new short[9];
  short *CAarr = new short[9];
  short *SAarr = new short[9];
  RAarr = checkRow(y);
  CAarr = checkColumn(x);
  SAarr = checkSquare(quadrant(x,y));

  //Creates answer length variables and initializes them acordingly
  short RAL = 0, CAL = 0, SAL = 0;
  for(short i=0; i<9; ++i) {
    if(RAarr[i] != 0) ++RAL;
    if(CAarr[i] != 0) ++CAL;
    if(SAarr[i] != 0) ++SAL;
  }

  //Declare and fill the new answer arrays 
  short *rowAns = new short[RAL];
  short *colAns = new short[CAL];
  short *sqrAns = new short[SAL];
  for(short i=0; i<RAL; ++i) {
    rowAns[i] = RAarr[i];
  }
  for(short i=0; i<CAL; ++i) {
    colAns[i] = CAarr[i];
  }
  for(short i=0; i<SAL; ++i) {
    sqrAns[i] = SAarr[i];
  }

  //Creates and fills new final answer array
  short count = 0;
  short *ans = new short[9];
  for(short i=0; i<RAL; ++i) {
    for(short j=0; j<CAL; ++j) {
      for(short k=0; k<SAL; ++k) {
        if(rowAns[i] == colAns[j] && colAns[j] == sqrAns[k]) {
          ans[count] = rowAns[i];
          ++count;
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
    
    for(short i=0; i<9; ++i) {
        for(short j=0; j<9; ++j) {
            if(grid[i][j] != 0) {
                gridStats[i][j] = 1;
            } else {
                gridStats[i][j] = 0;
            }
        }
    }

    printGrid();
    
    short *temp = new short[9];
    temp = possibleNums(3,2);
    short a = 0;
    for(short i=0; i<9; ++i) {
      if(temp[i] != 0) ++a;
    }
    short *ans = new short[a];
    for(short i=0; i<a; ++i) {
      ans[i] = temp[i];
    }
    delete[] temp;
    for(short i=0; i<a; ++i) {
      cout << "[" << ans[i] << "] ";
    }
    cout << endl;

    cout << endl;
    cout << "Done." << endl;
}
