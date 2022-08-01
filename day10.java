/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null)
            return t2;
        Stack < TreeNode[] > stack = new Stack < > ();
        stack.push(new TreeNode[] {t1, t2});
        while (!stack.isEmpty()) {
            TreeNode[] t = stack.pop();
            if (t[0] == null || t[1] == null) {
                continue;
            }
            t[0].val += t[1].val;
            if (t[0].left == null) {
                t[0].left = t[1].left;
            } else {
                stack.push(new TreeNode[] {t[0].left, t[1].left});
            }
            if (t[0].right == null) {
                t[0].right = t[1].right;
            } else {
                stack.push(new TreeNode[] {t[0].right, t[1].right});
            }
        }
        return t1;
    }
}

/* not working
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NUL;)
        queue <pair<TreeNode*,TreeNode*>> s;
        pair<TreeNode*,TreeNode*> temp ;
        struct TreeNode* sumroot = new TreeNode(root1->val+root2->val);
         struct TreeNode* sumroot2 = sumroot;
        struct TreeNode* head = sumroot;
        s.push(make_pair(root1,root2));
        int cnt = 0;
        while(!s.empty()){
             temp= s.front();
            
            if(temp.first==NULL && temp.second==NULL){
                s.pop();
                continue;
            }
            
            //cout<<s.front().first->val<<" "<<s.front().second->val<<"\n";
            s.pop();
            if(temp.first && temp.second && temp.first->left !=NULL && temp.second->left !=NULL){
                sumroot->left = new TreeNode(temp.first->left->val+temp.second->left->val);
            }
            
            else if (temp.first && temp.first->left !=NULL)
                sumroot->left = new TreeNode(temp.first->left->val); 
            else if( temp.second && temp.second->left !=NULL)
                sumroot->left = new TreeNode(temp.second->left->val); 
            
            
            
            
            if( temp.first && temp.second && temp.first->right && temp.second->right)
            sumroot->right = new TreeNode(temp.first->right->val+temp.second->right->val); 
            else if ( temp.first && temp.first->right !=NULL)
                sumroot->right = new TreeNode(temp.first->right->val); 
            else if( temp.second && temp.second->right !=NULL)
                sumroot->right = new TreeNode(temp.second->right->val); 
            if(cnt%3==0)
            head = sumroot;
            if(cnt%2==0){
                sumroot = head->left;
            }
            else{
                sumroot = head->right;
            }
            
            cnt++;
            if(temp.first && temp.second )
            {s.push(make_pair(temp.first->left,temp.second->left));
            s.push(make_pair(temp.first->right,temp.second->right));}
            //cout<<s.top().first->val<<" "<<s.top().second->val<<"\n";
        }
        return sumroot2;
    }
};
*/