#ifndef __piece_hpp__
#define __piece_hpp__

#include <string>
#include <vector>

class piece{
public:
	bool _color;
	std::string _icon;
	std::pair<int, int> _position;
	std::vector<std::pair<int,int>> _possiblemoves;

	virtual bool getColor()=0;
	virtual std::string getIcon()=0;
	virtual void setColor(bool)=0;
	virtual void setIcon(std::string)=0;
	virtual bool moveCheck(std::pair<int, int> endingSquare)=0;
	virtual void getPossibleMoves() = 0;

};

#endif

