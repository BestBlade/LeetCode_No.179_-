/* ------------------------------------------------------------------|
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	排序法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：10.8 MB, 在所有 C++ 提交中击败了76.34%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    //写在类内就要加static，因为sort自带cmp函数，不加static的话sort就有二义性，不知道调用哪个cmp
    //写类外可以不加
    static bool compare(const int& x, const int& y) {
        //判断4，14组成的组合
        //414和144哪个大就先返回哪个
        int sx = 10;
        int sy = 10;
        while (sx <= x) {
            sx *= 10;
        }
        while (sy <= y) {
            sy *= 10;
        }
        return sy * x + y > sx * y + x;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for (int& i : nums) {
            res += to_string(i);
        }
        return res;
    }
};


int main(){
    vector<int> nums = {10,2};
    Solution res;
    res.largestNumber(nums);
    }