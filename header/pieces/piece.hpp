class piece{
private:
	bool _color;
	bool _icon;
public:
	bool getColor();
	bool getIcon();
	void setColor(bool);
	void setIcon(bool);
	virtual void move(startingSquare, endingSquare)=0;
	virtual void moveCheck(startingSquare)=0;
	virtual void capture(startingSquare, endingSquare)=0;	

