#include <vector>

namespace Statistics {
    struct Stats
{
 float average;
 float max;
 float min;
};
 Stats ComputeStatistics(const std::vector<float>& float_vector);
 std::vector<float> RemoveNan(const std::vector<float>& float_vector);
 float maxElement(const std::vector<float>& float_vector);
 float minElement(const std::vector<float>& float_vector);
 float Average(const std::vector<float>& float_vector);
}