#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    bool isSymmetric(TreeNode *root) {
        std::queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            int tempLen = que.size();
            std::vector<int> nums(tempLen);
            root = que.front();
            que.pop();
            //按照行进行遍历，放到队列中
            for (int i = 0; i < tempLen; ++i)
            {
                nums[i] = root ? root->val : -1;

                if (!root)
                {
                    que.push(root->left);
                    que.push(root->right);
                }
            }
            //遍历一整行
            for (int i = 0; i < tempLen / 2; ++i)
            {
                if (nums[i] != nums[tempLen / 2 + i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};