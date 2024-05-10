  /*
    calculating the area of a circle,
    triangle and rectangle by using structs
    written by: zeynepsturan
  */

#include <stdio.h>
#include <math.h>
#define PI 3.14

/*structures for the shapes*/
typedef struct{
	double width;
	double height;
}Rectangle;

typedef struct{
	double side1;
	double side2;
	double side3;
}Triangle;

typedef struct{
	double radius;
}Circle;

void calculate_area(Rectangle rectangle, Circle circle, Triangle triangle, double areas[3]);

int main(){

	double areas[3]; /*the array that stores the area results*/
	Rectangle rectangle={5,3};
	Triangle triangle={3,4,5};
	Circle circle={2};
  
	calculate_area(rectangle, circle, triangle, areas);
  return 0;
}

void calculate_area(Rectangle rectangle, Circle circle, Triangle triangle, double areas[3]){
  /*area of the circle*/
	double circle_area=pow(circle.radius,2)*PI;

  /*area of the triangle*/
	double S = (triangle.side1 + triangle.side2 + triangle.side3)/2;
	double triangle_area = sqrt( S* (S - triangle.side1) * (S - triangle.side2) * (S - triangle.side3));

   /*area of the rectangle*/
	double rectangle_area=(rectangle.width*rectangle.height);

  /*storing them in the array*/
	areas[0]=rectangle_area;
	areas[1]=circle_area;
	areas[2]=triangle_area;

  /*printing the results*/
	printf("Area of rectangle: %.2lf\n",rectangle_area);
	printf("Area of cirle: %.2lf\n",circle_area);
	printf("Area of triangle: %.2lf\n",triangle_area);
}
