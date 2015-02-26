/*********************************************************************************************
 *  Name:  	    Brandon Stanley
 *  Student Number: 0495470
 *  Course:	    Comp-2412-FA
 *  Assignment:	    1
 *  Date Due:	    Sept. 30th, 2013
 *  
 *********************************************************************************************
 * Purpose of this file:
 *	This file is the mouse's implimentation.  It controls the mouse's ability to
 * navigate the maze.  
 *********************************************************************************************/

#include <iostream>
#include "mouse.h"
#include <vector>
#include <stack>

using namespace std;

MOUSE::MOUSE(vector< vector<char> > maze){
	this->maze = maze;
	for(int i = 0; i < maze.size(); ++i){
		for(int j = 0; j < maze[i].size(); ++j){ 
			if(maze[i][j] == 'm'){
				x = i;//starting positions
				y = j;
			}
		}
	}
}

void MOUSE::run_maze(){
  stack <COORDS*> backtrack;
  COORDS *pos;
  char temp[2], *temp2;	
  bool tripped = false;
  char junk;
  while(1){
    
        if(maze[x-1][y] == '0' || maze[x-1][y] == 'e'){
            pos = new COORDS(x-1, y);
            backtrack.push(pos);
	    }
        if(maze[x+1][y] == '0' || maze[x+1][y] == 'e'){
                pos = new COORDS(x+1, y);
                backtrack.push(pos);
        }
        if(maze[x][y-1] == '0' || maze[x][y-1] == 'e'){
                pos = new COORDS(x, y-1);
                backtrack.push(pos);
        }
        if(maze[x][y+1] == '0' || maze[x][y+1] == 'e'){
                pos = new COORDS(x, y+1);
                backtrack.push(pos);
        }

       	maze[x][y] = '.';
	    pos = backtrack.top();
  	    backtrack.pop();

  	    x = pos->x;
  	    y = pos->y;
  	    delete pos;
  	    if(maze[x][y] == 'e')
		    tripped = true;
	    
  	
	    maze[x][y] = 'm';

            cin >> junk;
	    print_maze();
	    if(tripped){
		    cout << "The mouse has exited the maze!" << endl;
            return;
        }

  }
  
  
}


void MOUSE::print_maze(void){
  for(int i = 0; i < maze.size(); ++i){
	for(int j = 0; j < maze[i].size(); ++j)
	  cout << maze[i][j];
	cout << endl;

  }


}

