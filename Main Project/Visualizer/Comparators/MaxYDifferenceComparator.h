//Comparator which is used to sort 3d models based on maxiumum height
#pragma once
#include <vector>
#include "Point3D.h"
#include "pch.h"
using namespace GeometricEntity;

class COMPARATORS_API MaxYDifferenceComparator {
public:
    bool operator()(const std::vector<Point3D>& v1, const std::vector<Point3D>& v2) const;
};
