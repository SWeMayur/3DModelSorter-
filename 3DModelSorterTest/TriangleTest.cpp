#include "pch.h"
#include "Triangle.h"
using namespace GeometricEntity;

TEST(TriangleTest, ConstructorAndGetters) {
    Point3D p1(1.0f, 2.0f, 3.0f);
    Point3D p2(4.0f, 5.0f, 6.0f);
    Point3D p3(7.0f, 8.0f, 9.0f);

    Triangle triangle(p1, p2, p3);

    // Test getter functions
    EXPECT_EQ(triangle.p1(), p1);
    EXPECT_EQ(triangle.p2(), Point3D(1.2f, 1.4f, 1.5f)); //failing test case
    EXPECT_EQ(triangle.p3(), p3);
}

