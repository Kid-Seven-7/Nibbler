# ifndef _NIBBLER_HPP_
# define _NIBBLER_HPP_

# include <vector>

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

struct Part {
	int x, y;
	int nextX, nextY;
	int prevX, prevY;
	bool isHead;
	bool isTail;
	bool canMove;
};

class Snake_class {
	private:
		int length, direction;
		std::vector<Part> Snake;
		bool isAlive;
	public:
		Snake_class();
		Snake_class(int width, int height);
		~Snake_class();

		int getLength();
		int getX(int index);
		int getY(int index);
		int getNextX(int index);
		int getNextY(int index);
		bool getType(int index);
		void setDirection(int dirValue);
		int getDirection();
		void moveSnake();
		void addPart();
		bool collision();
		std::vector<Part> getVector();
		void setVector(std::vector<Part> &Snake);
		void reset();
};

extern	"C"
{
	Snake_class *snakeClass(int width, int height);
}

# endif
