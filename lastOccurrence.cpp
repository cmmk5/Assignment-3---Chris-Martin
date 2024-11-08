#include <vector>
using namespace std;

int lastOccurrence(const vector<int>& vec, int target, int index) {
    if (index < 0) return -1; // Base case: not found
    if (vec[index] == target) return index;
    return lastOccurrence(vec, target, index - 1);
}
