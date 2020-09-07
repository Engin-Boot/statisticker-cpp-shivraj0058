#include "stats.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& float_vector)
{
    Statistics::Stats statobj={NAN,NAN,NAN};
    std::vector<float> NonNANfloatVector = RemoveNan(float_vector);
    if (NonNANfloatVector.size() == NULL)
    {
        return statobj;
    }
    statobj.average = Average(NonNANfloatVector);
    statobj.max = maxElement(NonNANfloatVector);
    statobj.min = minElement(NonNANfloatVector);
    
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

float Statistics::Average(const std::vector<float>& float_vector2)
{
    int sum = 0;
    int float_vector2_size = float_vector2.size();
    for (int i = 0; i < float_vector2_size; i++)
    {
        sum = sum + float_vector2[i];
    }
    float average = sum / float_vector2_size;
    return average;

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

std::vector<float> RemoveNan(const std::vector<float>& float_vector)
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

