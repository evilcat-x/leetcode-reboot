/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (49.80%)
 * Total Accepted:    38K
 * Total Submissions: 76.2K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 *
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 *
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 *
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 *
 * At the end, return the modified image.
 *
 * Example 1:
 *
 * Input:
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation:
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 *
 *
 *
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 *
 */
#include <vector>
using namespace std;

class Solution
{
  private:
    int color;
    int target;
    int height;
    int width;
    vector<vector<int>> *img;

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        color = newColor;
        target = image[sr][sc];
        if (color == target)
            return image;
        height = image.size();
        width = image[0].size();
        img = &(image);
        f_fill(sr, sc);
        return image;
    }
    void f_fill(int r, int c)
    {
        (*img)[r][c] = color;
        if (r - 1 >= 0 && (*img)[r - 1][c] == target)
            f_fill(r - 1, c);
        if (r + 1 < height && (*img)[r + 1][c] == target)
            f_fill(r + 1, c);
        if (c - 1 >= 0 && (*img)[r][c - 1] == target)
            f_fill(r, c - 1);
        if (c + 1 < width && (*img)[r][c + 1] == target)
            f_fill(r, c + 1);
    }
};
