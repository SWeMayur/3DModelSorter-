#include <vector>
#include "pch.h"
#include "MaxYDifferenceComparator.h"
#include "Point3D.h"
using namespace GeometricEntity;

// Custom comparator for comparing vectors of Point3D based on their maximum y-values.
// This comparator is intended to be used for sorting or ordering vectors.
bool MaxYDifferenceComparator::operator()(const std::vector<Point3D>& v1, const std::vector<Point3D>& v2) const {
    // Initialize variables to store the maximum y-values of each vector.
    float maxYV1 = -12345678.0f;
    float maxYV2 = -12345678.0f;

    // Iterate through the elements of the first vector (v1) to find the maximum y-value.
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i].y() > maxYV1)
            maxYV1 = v1[i].y();
    }

    // Iterate through the elements of the second vector (v2) to find the maximum y-value.
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i].y() > maxYV2)
            maxYV2 = v2[i].y();
    }

    // Compare the maximum y-values of the two vectors and return true if maxYV1 is greater than maxYV2.
    // This indicates that the vector v1 has a greater maximum y-value than vector v2.
    return maxYV1 > maxYV2;
}
