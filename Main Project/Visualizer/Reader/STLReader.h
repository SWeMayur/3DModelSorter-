#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include "pch.h"
#include "vector"
#include "Point3D.h"
#include "string"
using namespace GeometricEntity;

// This class is exported from the dll
namespace IOOperation {
	class READER_API STLReader {
	public:
		STLReader(std::string filePath, std::vector<Point3D>& vertices, std::vector<Point3D>& colors, std::vector<Point3D>& normals);
		~STLReader();

	public:
		void readShader(std::string filePath);

	private:
		void readSTL(std::string filePath, std::vector<Point3D>& vertices, std::vector<Point3D>& colors, std::vector<Point3D>& normals);
	};
}