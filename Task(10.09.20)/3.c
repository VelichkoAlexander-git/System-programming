#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct {
	double x;
	double y;
} Vector;
 
typedef struct {
	Vector *p1;
	Vector *p2;
} Line;
 
Line *line_init(double x1, double y1, double x2, double y2)
{
	Vector v1 = { x1, y1 };
	Vector v2 = { x2, y2 };
 
	Line *l = malloc(sizeof(Line));
	l->p1 = &v1;
	l->p2 = &v2;
 
	return l;
}
 
double line_length(Line *l)
{
	double dx = l->p1->x - l->p2->x;
	double dy = l->p1->y - l->p2->y;
	double len = sqrt(dx * dx + dy * dy);
 
	return len;
}
 
int main(void)
{
	Line *l1 = line_init(1, 1, 5, 5);
	Line *l2 = line_init(-5, 3, 0, 5);
 
	printf("line length: %f\n", line_length(l1));
	printf("line length: %f\n", line_length(l2));
 
	return 0;
}