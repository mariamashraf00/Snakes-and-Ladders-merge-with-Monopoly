#include "GameObject.h"
#include <fstream>

GameObject::GameObject(const CellPosition & pos)
{
	position = pos;
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}