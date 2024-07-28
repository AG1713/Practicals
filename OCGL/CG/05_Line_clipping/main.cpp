#include <iostream>
#include <cmath>
#include <graphics.h>
#include "G:\Computer Graphics\00_Basic_tools\Algorithms.h"
using namespace std;

// Cohen-Sutherland line clipping algorithm

// TDRL - Top Down Right Left

int g_code(float x_min, float x_max, float y_min, float y_max, float x, float y){
	int code = 0;
	if (y > y_max)
		code |= 8;
	if (y < y_min)
		code |= 4;
	if (x > x_max)
		code |= 2;
	if (x < x_min)
		code |= 1;
	return code;
}

void get_xy(float &x, float &y, int code, float m, float c, float x_max, float x_min, float y_max, float y_min){
	cout<<code<<endl;
	// Compares x and x_max and x_min
	// If x is out of range, x = x_max or x_min and y is derived accordingly
	// y is returned
	if ((code&8)==8){
		cout<<"Top"<<endl;
		if((code&1)==1){
			if((x_min-x)>(y-y_max)){
				x = x_min;
				y = m*x_min + c;
				return;
			}
			if((x_min-x)<(y-y_max)){
				y = y_max;
				x = (y_max-c)/m;
				return;
			}	 
		}
		if((code&2)==2){
			if((x-x_max)>(y-y_max)){
				x = x_max;
				y = m*x_max + c;
				return;
			}
			if((x-x_max)<(y-y_max)){
				y = y_max;
				x = (y_max-c)/m;
				return;
			}
		}
		y = y_max;
		x = (y_max - c)/m;
		return;
	}
	
	
	else if ((code&4)==4){
		cout<<"Down"<<endl;
		if((code&1)==1){
			if((x_min-x)>(y_min-y)){
				x = x_min;
				y = m*x_min + c;
				return;
			}
			if((x_min-x)<(y_min-y)){
				y = y_min;
				x = (y_min-c)/m;
				return;
			}
		}
		if((code&2)==2){
			if((x-x_max)>(y_min-y)){
				x = x_max;
				y = m*x_max + c;
				return;
			}
			if((x-x_max)<(y_min-y)){
				y = y_min;
				x = (y_min-c)/m;
				return;
			}
		}
		y = y_min;
		x = (y_min - c)/m;
		return;
	}
		
	else{
		if((code&1)==1){
			x = x_min;
			y = m*x_min+c;
			cout<<x<<" "<<y<<endl;
			return;
		}
		if((code&2)==2){
			x = x_max;
			y = m*x_max+c;
			return;
		}
			
		}
		
		return;
	}
	
	
	
	



void clipping(float x_min, float x_max, float y_min, float y_max, float x1, float y1, float x2, float y2){
	int code1, code2;
	code1 = g_code(x_min, x_max, y_min, y_max, x1, y1);
	code2 = g_code(x_min, x_max, y_min, y_max, x2, y2);
	
	float xn1=x1, xn2=x2, yn1=y1, yn2=y2;
	float m = (y2-y1)/(x2-x1);
	float c = y1-(m*x1);
	
	
	if((code1 | code2) == 0){
		q_line(x1, y1, x2, y2);
	}
	else if((code1 & code2)!=0){
		return;
	}
	else{
		// when code1 is in and code2 is out
		// when code1 is out and code2 is in
		// when both code1 and code2 are out

		get_xy(xn1, yn1, code1, m, c, x_max, x_min, y_max, y_min);
		cout<<xn1<<" "<<yn1<<endl;
		get_xy(xn2, yn2, code2, m, c, x_max, x_min, y_max, y_min);
		cout<<xn2<<" "<<yn2<<endl;
		
//		cout<<xn1<<" "<<yn1<<" "<<xn2<<" "<<yn2<<endl;
		q_line(xn1, yn1, xn2, yn2, 15);
	}
}

int main(){
	initwindow(1200,800,"Graphics");
	
	q_line(300,300,600,300);
	q_line(600,300,600,600);
	q_line(600,600,300,600);
	q_line(300,600,300,300);
	
	q_line(200,400,400,250, 1);
	q_line(100,700,400,350, 1);
	q_line(100,200,800,700, 1);
	q_line(900,200,100,800, 1);
	
	clipping(300,600,300,600,200,400,400,250);
	clipping(300,600,300,600,100,700,400,350);
	clipping(300,600,300,600,100,200,800,700);
	clipping(300,600,300,600,900,200,100,800);
	
	getch();
	return 0;
}

