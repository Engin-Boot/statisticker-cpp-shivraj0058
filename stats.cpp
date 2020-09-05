#include "stats.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& float_vector)
{
    Statistics::Stats statobj;
    int float_vector_size = float_vector.size();
    if (float_vector_size == 0)
    {
        statobj.max = nanf("");
        statobj.min = nanf("");
        statobj.average = nanf("");
        return statobj;
    }
    vector<float> float_vector2;
    for (int i = 0; i < float_vector_size; i++)
    {
        if (!isnan(float_vector[i]))
            float_vector2.push_back(float_vector[i]);
    }
    int float_vector2_size = float_vector2.size();
    float sum = 0;
    for (int i = 0; i < float_vector2_size; i++)
    {
        sum = sum + float_vector2[i];
    }
    statobj.average = sum /float_vector2_size;
    statobj.max = maxElement(float_vector2);
    statobj.min = minElement(float_vector2);
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

