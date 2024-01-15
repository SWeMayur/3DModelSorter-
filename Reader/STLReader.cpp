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
//readSTL function which reads stl file and stores it in vector of points
void STLReader::readSTL(std::string filePath, std::vector<Point3D>& vertices, std::vector<Point3D>& colors, std::vector<Point3D>& normals)
{
    std::ifstream dataFile;
    dataFile.open(filePath);
    //check if filepath is valid or not
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
            // first line
            std::istringstream stlLine(line);
            std::string token;
            float x, y, z;
            stlLine >> token >> x >> y >> z;

            Point3D p1(x, y, z);
            Point3D c1(1.0f, 0.0f, 0.0f);

            //second line
            std::getline(dataFile, line);
            std::istringstream stlLine1(line);
            std::string token1;
            float x1, y1, z1;
            stlLine1 >> token1 >> x1 >> y1 >> z1;

            Point3D p2(x1, y1, z1);
            Point3D c2(0.0f, 1.0f, 0.0f);

            //third line
            std::getline(dataFile, line);
            std::istringstream stlLine2(line);
            std::string token2;
            float x2, y2, z2;
            stlLine2 >> token2 >> x2 >> y2 >> z2;

            Point3D p3(x2, y2, z2);
            Point3D c3(0.0f, 0.0f, 1.0f);
            
            vertices.push_back(p1);
            vertices.push_back(p2);
            vertices.push_back(p3);

            colors.push_back(c1);
            colors.push_back(c2);
            colors.push_back(c3);
        }
        //read normals
        if (line.find("facet normal") != std::string::npos)
        {
            std::string _;
            std::istringstream stlLineNormal(line);
            float x;
            float y;
            float z;
            stlLineNormal >> _ >> _ >> x >> y >> z;
            normals.push_back(Point3D(x, y, z));
        }
    }
    dataFile.close();
}

void STLReader::readShader(std::string filePath)
{

}
