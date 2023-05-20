#ifndef POINT_HEADERS
#define POINT_HEADERS

struct Point {
	int x = 0;
	int y = 0;

    Point();
	Point(int new_x, int new_y);

	// Vector operations
	void add(Point p);
	void add(int x, int y);
	void sub(Point p);
	void sub(int x, int y);
	int dotProd(Point p);
	int dotProd(int x, int y);
	float distance();
};

#endif