//1.2.
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
      int left = 0,right = 0;
      dfs("",n,left,right);
      return res;
    }
    void dfs(string s, int n, int left, int right) {
      if(left==n&&right==n){
      res.push_back(s);
      return;
      }
      if(left < n)          dfs(s+'(',n,left+1,right);
      if(right < left)      dfs(s+')',n,left,right+1);
    }

};
int main()
{
    Solution so;

    vector<string> a;
   a = so.generateParenthesis(3);
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
        cout << endl;
    }
    getchar();
    //system("pasue");
    return 0;
}
