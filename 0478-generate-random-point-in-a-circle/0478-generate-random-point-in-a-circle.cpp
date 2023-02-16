class Solution {
public:
    double r;
    double x;double y;
    Solution(double radius, double x1, double y1) {
        r=radius;
        x=x1;
        y=y1;
    }
    
    vector<double> randPoint() {
        vector<double>ans(2);
        double theta=((double)rand()/RAND_MAX*(2*3.14));
        double l=sqrt((double)rand()/RAND_MAX)*r;
       ans= {x+(l*cos(theta)),y+(l*sin(theta))};
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */