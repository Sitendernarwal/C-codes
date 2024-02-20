#include <iostream>
#include <vector>

bool crossRiver(std::vector<int> &safe)
{ // Write your code here
    int jump = 1;
    if (safe[0] + 1 != safe[1])
    {
        return false;
    }

    for (int i = 1; i < safe.size() - 1; i++)
    {
        if (safe[i] + jump == safe[i + 1])
        {
            // If we can make the current jump, do nothing
        }
        else if (safe[i] + jump + 1 == safe[i + 1])
        {
            // If we can make a larger jump, increase the jump size
            jump++;
        }
        else if (safe[i] + jump - 1 == safe[i + 1])
        {
            // If we can make a smaller jump, decrease the jump size
            jump--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // Test case
    std::vector<int> safePositions = {0, 1, 2, 3, 5, 6, 7, 8, 9, 13};

    // Check if it is possible to cross the river safely
    bool result = crossRiver(safePositions);

    // Display the result
    if (result)
    {
        std::cout << "It is possible to cross the river safely." << std::endl;
    }
    else
    {
        std::cout << "It is not possible to cross the river safely." << std::endl;
    }

    return 0;
}
