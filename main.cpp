/*********************************************************************************************
 *  Name:           Brandon Stanley
 *  Student Number: 0495470
 *  Course:         Comp-2412-FA
 *  Assignment:     1
 *  Date Due:       Sept. 30th, 2013
 *  
 *********************************************************************************************
 * Purpose of this file:
 *      This file initializes the maze, and then passes it through to the mouse for navifation  
 *
 *	There are two methods to running this file, by giving it a file name through command line,
 * or a run time maze creation.
 *********************************************************************************************/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream> 
#include "mouse.h"


using namespace std;

int main(int argc, char **argv){
    vector< vector<char> > maze;
    stack<char > read_stack;
    MOUSE *mouse;
    int x;
    string input; 

    string line;
    ifstream fp;
    cout << "test" << endl;
    if(argc == 2){ //command line file given
    	fp.open(argv[1]);
    	while(getline(fp, line)){
	  cout << line << endl;
	  vector<char> temp;
	  for(int i = 0; i < line.size(); ++i)
		temp.push_back(line[i]);
	  maze.push_back(temp);
    	}
	        
    }
    else{//user input, I assume the stack is ment to flip the maze
         cout << "Fill this maze line by line, press enter to end a line." << endl 
		<< "0 is open space, 1 is closed space, m is the mouse, e is the exit." << endl
		<< " The first row will determine the width of the maze." << endl
		<< " Rows longer then this will be clipped off, and rows shorter then this will be filled with 1." << endl 
		<<  "An empty row means the end of the input." << endl << endl;
         getline(cin, input);
         x = input.length();
         for(int i = 0; i < x + 2; i++)
                 read_stack.push('1');
                 
         do{
             read_stack.push('1');
             for(int j = 0; j < x; ++j){
                 if(input.length() <= j)
                    read_stack.push('1');
                 else
                    read_stack.push(input[j]); 
                     
             }
             read_stack.push('1');
             getline(cin, input);
         }while(input.length() > 0);
         for(int i = 0; i < x + 2; i++)
                 read_stack.push('1');
         while(read_stack.size() != 0){
		 vector<char> temp;
                 for(int i = 0; i < x+2; ++i){
			 temp.push_back(read_stack.top());
                         read_stack.pop();
                 }
                 maze.push_back(temp);
         }
         
         
              
    }
	
	cout << "Enter a character and press enter for the program to perform the next step." << endl;
	mouse = new MOUSE(maze);
	mouse->run_maze();
}
