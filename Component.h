#pragma once
#ifndef Component_h
#define Component_h
class Component
{
protected:
	Component(char* newt) : Type(newt){};
public:
	char* Type;
	friend bool operator==(const Component& left, const Component& right){
		return ((left.Type == right.Type));
	}
	friend bool operator!=(const Component& left, const Component& right){
		return !(left == right);
	}
	virtual void Start();
	virtual void Update();
	~Component();
};
#endif