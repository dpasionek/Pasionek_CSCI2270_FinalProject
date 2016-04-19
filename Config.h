#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

struct ConfigValue
{
	std::string tag;
	std::string value;
	
	ConfigValue(std::string _tag, std::string _value)
	{
		tag = _tag;
		value = _value;
	}ConfigValue(){};
};

class Config
{
public:
	Config();
	~Config();
	void init(std::string configFile);
	// Returns the value of a certain tag
	std::string get(std::string tag);
	
private:
	std::vector<ConfigValue> configValues;
	void pushConfigValue(std::string tag, std::string value);
	
};
