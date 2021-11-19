#ifndef __piece_hpp__
#define __piece_hpp__

#include <string>

class piece{
private:
	bool _color;
	bool _icon;
public:
	virtual bool getColor()=0;
	virtual std::string getIcon()=0;
	virtual void setColor(bool)=0;
	virtual void setIcon(std::string)=0;
	virtual bool moveCheck(std::pair<int, int> endingSquare)=0;
	virtual void getPossibleMoves() = 0;

};

#endif

