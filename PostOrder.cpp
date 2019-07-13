
void PostOrder(TreeNode *root) {
    TreeNode *p = root, *r = NULL;
    stack<TreeNode*> s;
    while (p || !s.empty()) {
        if (p) {//走到最左边
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            if (p->right && p->right != r)//右子树存在，未被访问
                p = p->right;
            else {
                s.pop();
                visit(p->val);
                r = p;//记录最近访问过的节点
                p = NULL;//节点访问完后，重置p指针
            }
        }//else
    }//while
}