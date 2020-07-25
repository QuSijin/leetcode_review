class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        if(!root)   return ans;
        st.push(root);
        while(st.size())
        {
            Node* cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            for(int i =0;i < cur->children.size();i++)
            {
                st.push(cur->children[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
