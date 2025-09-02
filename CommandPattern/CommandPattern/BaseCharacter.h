#pragma once


// Receiver(¼ö½ÅÀÚ)
class BaseCharacter
{
private:
	int CoordinateX;
	int CoordinateY;

public:
	BaseCharacter() = default;
	virtual ~BaseCharacter() {};
	
	void Init(int StartX, int StartY);

	int GetCoordinateX() const { return CoordinateX; }
	int GetCoordinateY() const { return CoordinateY; }

	void MoveTo(int NewX, int NewY);

	void Move(int DeltaX, int DelataY);

	void Jump();

	void Dash();
};