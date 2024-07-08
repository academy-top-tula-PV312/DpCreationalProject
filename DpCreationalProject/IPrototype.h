#pragma once
template <typename T>
class IPrototype
{
public:
	virtual T Clone() = 0;
};

