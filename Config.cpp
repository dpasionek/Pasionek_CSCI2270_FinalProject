#include "Config.h"

Config::Config()
{
	
}

void Config::init(std::string configFile)
{
	std::ifstream file(configFile);
	std::string line ="null", tag = "null", value = "null";
	int index = -1;

	if(!file.is_open())
	{
		std::cout << "ERROR: There was an error opening the file!" << std::endl;
		std::cout << "Please make sure that the file \"" << configFile << "\" exists!" << std::endl;
		// Quit the program, if the config can't be loaded
		exit(1);
	}

	while(std::getline(file, line))
	{
		if(line[0] != '#')
		{	
			std::cout << line << std::endl;
			index = line.find_first_of("=");
			tag = line.substr(0, index);
			value = line.substr(index + 1);
			ConfigValue * newVal = new ConfigValue(tag, value);
			configValues.push_back(*newVal);		
		}
		
	}
}

// Will have to parse the actual data type elsewhere, it's just easier
// To store everything as a string...
std::string Config::get(std::string tag)
{
	for(unsigned int i = 0; i < configValues.size(); i++)
		if(configValues[i].tag == tag)
			return configValues[i].value;
	return "NULL";
}



Config::~Config()
{

}
