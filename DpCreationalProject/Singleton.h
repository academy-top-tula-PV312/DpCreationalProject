#pragma once
#include <iostream>
#include <mutex>

class Singleton
{
	static Singleton* instance;
	Singleton() {}
public:
	static Singleton* getInstance()
	{
		if (!instance)
			instance = new Singleton();
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;


std::mutex mutex;

class OS
{
	static OS* instance;
	std::string name;
	

	OS(std::string name) : name{ name } {};
public:

	std::string Name() { return name; }

	static OS* getInstance(std::string name)
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (!instance)
			instance = new OS(name);
		return instance;
	}
};

OS* OS::instance = nullptr;


class Computer
{
	OS* system;
public:
	OS*& OS() { return system; }

	void Launch(std::string name)
	{
		system = OS::getInstance(name);
	}
};

