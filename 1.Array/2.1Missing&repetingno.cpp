/*
Solution 1: Using Count Sort

Intuition + Approach: 

Since the numbers are from 1 to N in the array arr[]

Take a substitute array of size N+1 and initalize it with 0.
Traverse the given array and increase the value of substitute[arr[i]] by one .
Then again traverse the substitute array starting from index 1 to N.
If you find any index value greater than 1 that is repeating element A.

If you find any index value = 0 then that is the missing element B.

Dry Run: lets take the example of array[] = {3,1,2,5,3}

The size of the array is 5

We initialize a substitute array of size 6 with elements 0.

Now traversing through the array 

Found 3 at 0 index, increase the value of substitue array at index 3 by 1.
Found 1 at 1 index, increase the value of substitue array at index 1 by 1.
Found 2 at 2 index, increase the value of substitue array at index 2 by 1.
Found 5 at 3 index, increase the value of substitue array at index 5 by 1.
Found 3 at 4 index, increase the value of substitue array at index 3 by 1.
Now Traversing through the substitute array 

At index 3, the value is greater than 1 i.e 2. So A = 3.

At index 4, the value is 0 so B = 4.
*/
vector<int> find_missing_repeating(vector<int> array)
{
    int n = array.size() + 1;

    vector<int> substitute(n, 0); // initializing the substitute array with 0 of size n+1.

    vector<int> ans;              // initializing the answer  array .

    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]]++;
    }

    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}
/*
Time Complexity: O(N) + O(N) (as we are traversing 2 times )

Space Complexity: O(N) As we are making new substitute array
*/