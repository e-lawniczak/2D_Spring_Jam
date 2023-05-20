#ifndef POINT_HEADERS
#define POINT_HEADERS

class Point {
public:
	Point();
	Point(int aX, int aY);
	~Point();
	void free();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void newPos(Point p);

private:
	int x;
	int y;
};


#endif 
