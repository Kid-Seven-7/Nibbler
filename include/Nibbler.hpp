# ifndef _NIBBLER_HPP_
# define _NIBBLER_HPP_

# include <vector>
# include <cstdlib>
# include <ctime>

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

struct Part {
	int x, y;
	int nextX, nextY;
	int prevX, prevY;
};

class Snake_class {
	private:
		int direction;
		std::vector<Part> Snake;
	public:
		Snake_class(int width, int height);
		~Snake_class();
		//ints
		int getDirection();
		int getX(int index);
		int getY(int index);
		int getNextX(int index);
		int getNextY(int index);
		//voids
		void addPart();
		void moveSnake();
		void setDirection(int dirValue);
		void setVector(std::vector<Part> &Snake);
		void generateFood(int &width, int &height, int &food_x, int &food_y, std::vector<Part> &Snake);
		//bools
		bool collision();
		//misc
		std::vector<Part> getVector();
};

extern	"C"
{
	Snake_class *snakeClass(int width, int height);
}

# endif
