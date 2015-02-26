/*********************************************************************************************
 *  Name:           Brandon Stanley
 *  Student Number: 0495470
 *  Course:         Comp-2412-FA
 *  Assignment:     1
 *  Date Due:       Sept. 30th, 2013
 *  
 *********************************************************************************************
 * Purpose of this file:
 *      The project's header file.
 *********************************************************************************************/


#ifndef H_MOUSE_H
#define H_MOUSE_H
#include <vector>

using namespace std;

class MOUSE{
  private:
	vector< vector<char> > maze;
	int x, y;
	void print_maze(void);

  public:
	MOUSE(vector< vector<char> > maze);
	void run_maze();
};

class COORDS{
  public:
      int x;
      int y;
      COORDS(int x, int y){ this->x = x; this->y=y;}
};

#endif

