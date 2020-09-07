#include "stats.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& float_vector)
{
    Statistics::Stats statobj={NAN,NAN,NAN};
    std::vector<float> NonNANfloatVector = RemoveNan(float_vector);
    if (NonNANfloatVector.size() == 0)
    {
        return statobj;
    }
    statobj.average = Average(NonNANfloatVector);
    statobj.max = maxElement(NonNANfloatVector);
    statobj.min = minElement(NonNANfloatVector);
    return statobj;
}

float Statistics::minElement(const std::vector<float>& float_vector2)
{
    float min = float_vector2[0];
    int float_vector_size = float_vector2.size();
    for (int i = 1; i<float_vector_size; i++)
    {
        if (float_vector2[i]<min)
            min = float_vector2[i];
    }
    return min;
}


std::vector<float> Statistics::RemoveNan(const std::vector<float>& float_vector)
{
    std::vector<float> float_vector3;
    std::vector<float>::const_iterator iterator = float_vector.begin();
    while (iterator != float_vector.end())
    {
        if (!isnan(*iterator))
        {
            float_vector3.push_back(*iterator);
            iterator++;
        }
    }
    return float_vector3;
}

float Statistics::Average(const std::vector<float>& float_vector)
{

    int iterator; float sum = 0;
    int float_vector_size = float_vector.size();
    for (iterator = 0; iterator<float_vector_size; iterator++)
    {

        sum = sum + float_vector[iterator];
    }
    return sum / float_vector_size;

}
float Statistics::maxElement(const std::vector<float>& float_vector2)
{
    float max = float_vector2[0];
    int float_vector_size = float_vector2.size();
    for (int i = 1; i<float_vector_size; i++)
    {
        if (float_vector2[i]>max)
            max = float_vector2[i];
    }
    return max;
}
