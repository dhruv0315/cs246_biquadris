#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include <vector>

class Block {
  std::vector<std::vector<int>> shape;  // 2D grid representing the block's shape
  int x, y;  // Position of the block on the board (bottom-left corner of the block)

	public:
	Block();
	virtual ~Block() = 0; 
	virtual void rotateClockwise() = 0; //pure virtual method, abstract class, preventing initializing a "BLock" obj
	virtual void rotateCounterClockwise() = 0;
	void moveLeft();
	void moveRight();
	void moveDown();
	void dropToBottom();

};

class IBlock: public Block {};

class JBlock: public Block {};

class LBlock: public Block {};

class OBlock: public Block {};

class SBlock: public Block {};

class ZBlock: public Block {};

class TBlock: public Block {};


#endif
