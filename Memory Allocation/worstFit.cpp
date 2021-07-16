/*
    Multiprogramming with fixed number of tasks
    Worst Fit Memory Allocation Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

void worstFit(vector<int> processSize, vector<int> blockSize)
{
    vector<int> allocation(processSize.size(), -1);
    vector<bool> occupied(blockSize.size(), false);

    int totalInternalFrag = 0;

    for(int i = 0; i < processSize.size(); i++)
    {
        int worstIndex = -1;
        for(int j = 0; j < blockSize.size(); j++)
        {
            if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                if(worstIndex == -1)
                    worstIndex = j;
                else if(blockSize[worstIndex] < blockSize[j])
                    worstIndex = j;
            }
        }
        if(worstIndex != -1)
        {
            allocation[i] = worstIndex;
            totalInternalFrag += blockSize[worstIndex] - processSize[i];
            blockSize[worstIndex] -= processSize[i];
            occupied[worstIndex] = true;
        }
    }

    int totalExternalFrag = 0;

    cout << "Pno.\tProcess Size\tBlock no.\n";
    for(int i = 0; i < processSize.size(); i++)
    {
        cout<<i+1<<"\t"<<processSize[i]<<"\t\t";

        if(allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else 
        {
            cout << "Not allocated\n";
            totalExternalFrag += processSize[i];
        } 
    }

    cout << "Total Internal Fragmentation: " << totalInternalFrag << "\n";
    cout << "Total External Fragmentation: " << totalExternalFrag << "\n";
}

int main()
{
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of memory blocks: ";
    cin >> m;

    vector<int> processSize(n), blockSize(m);

    cout << "Enter sizes of processes: ";
    for(int i = 0; i < n; i++)
        cin >> processSize[i];
    
    cout << "Enter sizes of memory blocks: ";
    for(int i = 0; i < m; i++)
        cin >> blockSize[i];
    
    worstFit(processSize, blockSize);

    return 0;

}