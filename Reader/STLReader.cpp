#include "pch.h"
#include "STLReader.h"
#include <fstream>
#include <sstream>
#include "pch.h"
#include "framework.h"
#include "string"
using namespace IOOperation;

STLReader::STLReader(std::string filePath, std::vector<Point3D>& vertices, std::vector<Point3D>& colors, std::vector<Point3D>& normals)
{
    readSTL(filePath, vertices, colors, normals);
}
STLReader::~STLReader()
{}

void STLReader::readSTL(std::string filePath, std::vector<Point3D>& vertices, std::vector<Point3D>& colors, std::vector<Point3D>& normals)
{
    std::ifstream dataFile;
    dataFile.open(filePath);
    if (!dataFile.is_open())
    {
        return;
    }

    std::string line;
    int count = 0;
    while (std::getline(dataFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            float x, y, z;
            iss >> token >> x >> y >> z;

            Point3D p1(x, y, z);
            Point3D c1(1.0f, 0.0f, 0.0f);

            std::getline(dataFile, line);
            std::istringstream iss1(line);
            std::string token1;
            float x1, y1, z1;
            iss1 >> token1 >> x1 >> y1 >> z1;

            Point3D p2(x1, y1, z1);
            Point3D c2(0.0f, 1.0f, 0.0f);

            std::getline(dataFile, line);
            std::istringstream iss2(line);
            std::string token2;
            float x2, y2, z2;
            iss2 >> token2 >> x2 >> y2 >> z2;

            Point3D p3(x2, y2, z2);
            Point3D c3(0.0f, 0.0f, 1.0f);

            vertices.push_back(p1);
            vertices.push_back(p2);
            vertices.push_back(p3);

            colors.push_back(c1);
            colors.push_back(c2);
            colors.push_back(c3);
        }
        if (line.find("facet normal") != std::string::npos)
        {
            std::string _;
            std::istringstream issNormal(line);
            float x;
            float y;
            float z;
            issNormal >> _ >> _ >> x >> y >> z;
            normals.push_back(Point3D(x, y, z));
        }
    }
    dataFile.close();
}

void STLReader::readShader(std::string filePath)
{

}