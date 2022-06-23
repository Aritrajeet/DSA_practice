class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
       if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {     //sort based on 2nd parameter i.e. deadline
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];    //add the current course into schedule so duration is added
            q.push(i[0]);
            if(sum > i[1]) {  //if curr duration is more than deadline of the course
                sum -= q.top();     //remove the course with max duration and fit this course
                q.pop();
            }
        }
        return q.size();      //at the end we will have the max possible number of courses we can take
    }
};
