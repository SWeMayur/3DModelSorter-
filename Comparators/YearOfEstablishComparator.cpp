#include <fstream>
#include <sstream>
#include "string"
#include "algorithm"
#include "Point3D.h"
#include "pch.h"
#include "YearOfEstablishComparator.h"

using namespace GeometricEntity;

// Constructor for YearOfEstablishComparator class.
YearOfEstablishComparator::YearOfEstablishComparator() {
    // JSON file path to be read.
    const std::string& jsonFilePath = "Establishment.json";
    // Read the JSON file.
    readJsonFile(jsonFilePath);
}

// Destructor for YearOfEstablishComparator class.
YearOfEstablishComparator::~YearOfEstablishComparator() {}

// Custom comparator for comparing vectors of Point3D based on their rounded z-values.
// This comparator is designed to compare establishments based on their years of establishment.
bool YearOfEstablishComparator::operator()(const std::vector<Point3D>& v1, const std::vector<Point3D>& v2) const {
    // Extract the rounded z-values from the first and second vectors.
    float z1 = (v1.size() > 0) ? round(v1[0].z()) : 0.0f;
    float z2 = (v2.size() > 0) ? round(v2[0].z()) : 0.0f;

    // Get the associated values from the JSON file for the rounded z-values.
    int value1 = jsonValues.find(z1) != jsonValues.end() ? jsonValues.at(z1) : 0;
    int value2 = jsonValues.find(z2) != jsonValues.end() ? jsonValues.at(z2) : 0;

    // Compare the values associated with z1 and z2 and return true if value1 is less than value2.
    // This indicates that the establishment in v1 has a lower year of establishment than the one in v2.
    return value1 < value2;
}

// Read the JSON file and populate the jsonValues map.
void YearOfEstablishComparator::readJsonFile(const std::string& jsonFilePath) {
    std::ifstream file(jsonFilePath);

    // Check if the file is open successfully.
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + jsonFilePath);
    }

    std::string line;
    // Read each line of the file.
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string keyStr;
        int value;
        // Extract key and value from the line (assuming the format is "4.83628": value).
        if (iss >> keyStr >> value) {
            // Convert the key from string to float and round it.
            float key = std::stof(keyStr.substr(1, 6));
            jsonValues[round(key)] = value;
        }
    }
}
