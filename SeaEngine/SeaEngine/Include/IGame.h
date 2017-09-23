#pragma once
#ifndef IGAME_H
#define IGAME_H

class IGame
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};

#endif // !IGAME_H