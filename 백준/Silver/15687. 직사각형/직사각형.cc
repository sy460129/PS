#include <iostream>
using namespace std;
class Rectangle{
public:
	Rectangle(int w, int h){
		width=w;
		height=h;
	}
	int get_width() const {
		return width;
	}
	int get_height() const{
		return height;
	}
	void set_width(int w){
		if(w>0 && w<=1000){
			width=w;
		}
	}
	void set_height(int h){
		if(h>0 && h<=2000){
			height=h;
		}
	}
	int area() const{
		return width*height;
	}
	int perimeter() const{
		return (width+height)*2;
	}
	bool is_square() const{
		if(width==height){
			return true;
		}
		else{
			return false;
		}
	}
private:
	int width;
	int height;
};