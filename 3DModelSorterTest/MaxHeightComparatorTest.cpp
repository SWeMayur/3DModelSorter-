#include "pch.h"
#include "MaxYDifferenceComparator.h"

TEST(MaxYDifferenceComparatorTest, CompareVectors) {
    MaxYDifferenceComparator comparator;

    std::vector<GeometricEntity::Point3D> vector1 = { GeometricEntity::Point3D(1.0f, 2.0f, 3.0f), GeometricEntity::Point3D(4.0f, 5.0f, 6.0f) };
    std::vector<GeometricEntity::Point3D> vector2 = { GeometricEntity::Point3D(7.0f, 8.0f, 9.0f), GeometricEntity::Point3D(10.0f, 11.0f, 12.0f) };
    std::vector<GeometricEntity::Point3D> vector3 = { GeometricEntity::Point3D(13.0f, 14.0f, 15.0f), GeometricEntity::Point3D(16.0f, 17.0f, 18.0f) };

    // Test ordering based on max Y difference (height)
    EXPECT_TRUE(comparator(vector1, vector2));  // Y difference: 3
    EXPECT_TRUE(comparator(vector2, vector3));  // Y difference: 3
    EXPECT_TRUE(comparator(vector1, vector3));  // Y difference: 3

    // Test equal vectors (should return false)
    EXPECT_FALSE(comparator(vector1, vector1));
    EXPECT_FALSE(comparator(vector2, vector2));
    EXPECT_FALSE(comparator(vector3, vector3));
}
