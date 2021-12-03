#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <SDL.h>


namespace nc
{
	bool ReadFileToString(const std::string& filename, std::string& filestring);
	void SetFilePath(const std::string& pathname);
	std::string GetFilePath();
}