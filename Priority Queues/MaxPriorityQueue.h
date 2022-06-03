#include <vector>
using namespace std;

class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (pq.size() == 0)
        {
            return 0;
        }
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;
        while (leftchildindex < pq.size())
        {
            int maxNode = parentindex;
            if (pq[leftchildindex] > pq[maxNode])
            {
                maxNode = leftchildindex;
            }
            if (rightchildindex < pq.size() && pq[rightchildindex] > pq[maxNode])
            {
                maxNode = rightchildindex;
            }
            if (maxNode == parentindex)
            {
                break;
            }
            int temp = pq[maxNode];
            pq[maxNode] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = maxNode;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
        return ans;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return (pq.size() == 0);
    }
};