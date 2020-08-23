/*
	109. Triangle
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

	Example
	Example 1:

	Input the following triangle:
	[
	     [2],
	    [3,4],
	   [6,5,7],
	  [4,1,8,3]
	]
	Output: 11
	Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
	Example 2:

	Input the following triangle:
	[
	     [2],
	    [3,2],
	   [6,5,7],
	  [4,4,8,1]
	]
	Output: 12
	Explanation: The minimum path sum from top to bottom is 12 (i.e., 2 + 2 + 7 + 1 = 12).
	Notice
	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */


class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        
        // make sure that the triangle is not empty
        if (triangle.size() == 0) {
            return 0; 
        }
        if (triangle.at(0).size() == 0) {
            return 0; 
        }
        
        // initialize the memo of the sum with the first element of the triangle
        vector<int> memoSum{triangle.at(0).at(0)}; 
        
        for (int rowIdx = 1; rowIdx < triangle.size(); ++rowIdx) {
            vector<int> curSum; 
            for (int colIdx = 0; colIdx < rowIdx + 1; ++colIdx) {
                int minPreSum; 
                if (colIdx - 1 < 0) {
                    // the first column
                    minPreSum = memoSum.at(colIdx); 
                }
                else if (colIdx == memoSum.size()) {
                    // last column
                    minPreSum = memoSum.at(colIdx - 1); 
                }
                else {
                    // the element in the middle
                    minPreSum = min(memoSum.at(colIdx), memoSum.at(colIdx - 1)); 
                }
                curSum.push_back(triangle.at(rowIdx).at(colIdx) + minPreSum); 
            }
            memoSum = curSum; 
        }
        return *min_element(memoSum.cbegin(), memoSum.cend()); 
    }
};