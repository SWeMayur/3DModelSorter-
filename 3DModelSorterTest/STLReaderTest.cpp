#include "pch.h"
#include "STLReader.h"

using namespace IOOperation;

// Test case for the STLReader constructor
TEST(STLReaderTest, ConstructorTest) {
    std::vector<Point3D> vertices;
    std::vector<Point3D> colors;
    std::vector<Point3D> normals;

    //read the stl file and fill the three vectors
    STLReader stlReader("D:\Mayur_Workspace\STL_Files\building.stl", vertices, colors, normals);

    //compare vectors with size 0
    ASSERT_EQ(vertices.size(), 0);//fail
    ASSERT_EQ(colors.size(), colors.size()); //pass
    ASSERT_EQ(normals.size(), 0); //fail
}