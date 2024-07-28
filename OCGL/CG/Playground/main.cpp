# include <iostream>
# include <graphics.h>
# include <cmath>
using namespace std;

void q_line(int x1, int y1, int x2, int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	float length;
	
	
	if(abs(dx)>abs(dy)){
		length = abs(dx);
	}
	else{
		length = abs(dy);
	}
	float x_inc = dx/length;
	float y_inc = dy/length;
	
	float x = x1;
	float y = y1;
	putpixel(x1, y1, 15);
	for (int i=0 ; i<length ; i++){
		x = x+x_inc;
		y = y+y_inc;
		putpixel(x, y, 15);
	}
}

void q_circle(int x1, int y1, int r){
	float s = 3-2*r;
	int x = 0;
	int y = r;
	
	putpixel(x+x1, y+y1, 15);
	putpixel(-x+x1, y+y1, 15);
	putpixel(x+x1, -y+y1, 15);
	putpixel(-x+x1, -y+y1, 15);
	putpixel(y+x1, x+y1, 15);
	putpixel(-y+x1, x+y1, 15);
	putpixel(y+x1, -x+y1, 15);
	putpixel(-y+x1, -x+y1, 15);
	
	while(x<y){
		if(s<0){
			s = s+4*x+6;
			x = x+1;
		}
		else{
			s = s + 4*(x-y) + 10;
			x = x+1;
			y = y-1;
		}
		putpixel(x+x1, y+y1, 15);
		putpixel(-x+x1, y+y1, 15);
		putpixel(x+x1, -y+y1, 15);
		putpixel(-x+x1, -y+y1, 15);
		putpixel(y+x1, x+y1, 15);
		putpixel(-y+x1, x+y1, 15);
		putpixel(y+x1, -x+y1, 15);
		putpixel(-y+x1, -x+y1, 15);
	}
	
	
}





int main(){
	initwindow(1200,800,"Graphics");
	
	
	int length = 300;
	int c = 400;
	
	// 0+c, 0+c
	// length+c, 0+c
	// (length/2)+c, (sqrt(3)/2)*length+c
	q_line(0+c, (sqrt(3)/2)*length+c, length+c, (sqrt(3)/2)*length+c);
	q_line(length+c, (sqrt(3)/2)*length+c, (length/2)+c, 0+c);
	q_line((length/2)+c, 0+c, 0+c, (sqrt(3)/2)*length+c);
	
	q_circle((length/2)+c, (length*(sqrt(3)/2))+c-(sqrt(3)*length)/6, (sqrt(3)*length)/6);
	q_circle((length/2)+c, (length*(sqrt(3)/2))+c-(sqrt(3)*length)/6, (sqrt(3)*length)/3);	
	
	getch();
	return 0;
}



