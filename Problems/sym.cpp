#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int size[500] = {0};
    struct TreeNode** tmp = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    // printf("%d", size[123]);

    tmp[0] = root;
    size[0] = 1;
    int index = 1; // 总下标
    int layer = 0; // 层数
    int i, j;

    while (size[layer] > 0){
        int start = index - size[layer];
        size[layer+1] = 0;
        for (i = 0; i < size[layer]; i++) {
            if (tmp[start+i]->left != NULL) {
                tmp[index++] = tmp[start+i]->left;
                size[layer+1]++;
            }
            if (tmp[start+i]->right != NULL) {
                tmp[index++] = tmp[start+i]->right;
               size[layer+1]++;
            }
        }
        layer++;
    }

    *returnSize = index;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(layer*2));
    int** res = (int**)malloc(sizeof(int*)*(layer*2));

    for (i = 0; i < layer; i++) {
        (*returnColumnSizes)[i] = size[layer-i-1];
        int* restmp = (int*)malloc(sizeof(int)*(*returnColumnSizes)[i]);
        for(j = 0; j < (*returnColumnSizes)[i]; j++) {
            restmp[j] = tmp[index-(*returnColumnSizes)[i]+j]->val;
        }
        res[i] = restmp;
        // printf("%d\n",res[i][0]);
        index = index -(*returnColumnSizes)[i];
    }
    // printf("%d\n", (*returnColumnSizes)[0]);
    return res;
}