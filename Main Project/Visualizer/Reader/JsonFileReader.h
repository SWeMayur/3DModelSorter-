#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "pch.h"
#include "Point3D.h"

namespace IOOperation {
	class READER_API JsonFileReader
	{
	public:
		JsonFileReader(std::string& filePath, std::unordered_map<std::string, int>& json_data);
		~JsonFileReader();
	private:
		void readJson(std::string& filePath, std::unordered_map<std::string, int>& json_data);
	};
}