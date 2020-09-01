#include "stats.h"
#include<cmath>
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
    float sum = 0;
    for (int i = 0; i < float_vector_size; i++)
    {
        sum = sum + float_vector[i];
    }
    statobj.average = sum /float_vector_size;
    statobj.max = maxElement(float_vector);
    statobj.min = minElement(float_vector);
    return statobj;
}

float Statistics::minElement(const std::vector<float>& float_vector)
{
    float min = float_vector[0];
    for (int i = 1; i<float_vector_size; i++)
    {
        if (float_vector[i]<min)
            min = float_vector[i];
    }
    return min;
}

float Statistics::maxElement(const std::vector<float>& float_vector)
{
    float max = float_vector[0];
    for (int i = 1; i<float_vector_size; i++)
    {
        if (float_vector[i]>max)
            max = float_vector[i];
    }
    return max;
}