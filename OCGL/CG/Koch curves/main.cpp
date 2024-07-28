#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void koch_curve(int x1, int y1, int x2, int y2, int order){
	static float angle = 60*(3.14/180);
	
	int x3 = (x1*2+x2)/3;
	int y3 = (y1*2+y2)/3;
	int x4 = (x1+x2*2)/3;
	int y4 = (y1+y2*2)/3;
	
	int x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
	int y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
	
	if (order>1){
		koch_curve(x1, y1, x3, y3, order-1);
		koch_curve(x3, y3, x, y, order-1);
		koch_curve(x, y, x4, y4, order-1);
		koch_curve(x4, y4, x2, y2, order-1);
	}
	else{
		setcolor(3);
		line(x1, y1, x3, y3);
		line(x3, y3, x, y);
		line(x, y, x4, y4);
		line(x4, y4, x2, y2);
	}
	
}



int main() {
	initwindow(1200,800,"Graphics");
	koch_curve(300,300,600,300,0);
	
	
	getch();
	return 0;
}
