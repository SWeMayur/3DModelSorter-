#include "pch.h"
#include "JsonFileReader.h"
using namespace IOOperation;

JsonFileReader::JsonFileReader(std::string& filePath, std::unordered_map<std::string, int>& json_data)
{
	readJson(filePath,json_data);
}

JsonFileReader::~JsonFileReader() {}

void JsonFileReader::readJson(std::string& filePath, std::unordered_map<std::string, int>& json_data)
{
    std::ifstream file(filePath);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string modelName = buffer.str();

    // Close the file
    file.close();

    // Parse the JSON string
    size_t pos = modelName.find_first_of("{");
    modelName = modelName.substr(pos);

    pos = modelName.find_last_of("}");
    modelName = modelName.substr(0, pos + 1);

    // Parse the JSON data manually (this is a simple example and may not cover all cases)
    while ((pos = modelName.find_first_of("\"")) != std::string::npos) {
        modelName = modelName.substr(pos + 1);
        pos = modelName.find_first_of("\"");
        std::string key = modelName.substr(0, pos);

        pos = modelName.find_first_of(":");
        modelName = modelName.substr(pos + 1);

        pos = modelName.find_first_of(",");
        std::string modelValue = (pos != std::string::npos) ? modelName.substr(0, pos) : modelName;
        int value = std::stoi(modelValue);

        json_data[key] = value;

        if (pos != std::string::npos)
            modelName = modelName.substr(pos + 1);
    }
}