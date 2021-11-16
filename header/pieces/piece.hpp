#ifndef __piece_hpp__
#define __piece_hpp__

#include <string>

class piece{
private:
	bool _color;
	bool _icon;
public:
	bool getColor();
	std::string getIcon();
	void setColor(bool);
	void setIcon(std::string);
	virtual void move(startingSquare, endingSquare)=0;
	virtual void moveCheck(startingSquare)=0;
	virtual void capture(startingSquare, endingSquare)=0;
};

#endif

