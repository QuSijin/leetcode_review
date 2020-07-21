class Solution {
public:
    int shui(vector<int>& height)
    {
        int maxx = 0;
        int minheight;
        int area;
        for(int i =0,j=height.size()-1;i<j;)
        {
            minheight = height[i]<height[j] ?height[i++] : height[j--];
            area = (j-i+1)*minheight;
            maxx = max(maxx,area);
        }
    return maxx;
    }

};
int main()
{
    Solution so;
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    int b = so.shui(a);
    cout << b << endl;
    system("pause");
    return 0;
}
