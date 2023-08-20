class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();

        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }

        int i = 0;
        int attempts = 0; // To prevent an infinite loop in case of mismatched sandwiches
        while (!q.empty() && attempts < n) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                attempts = 0; // Reset attempts if a match is found
            } else {
                int frontStudent = q.front();
                q.pop();
                q.push(frontStudent);
                attempts++;
            }
        }

        return q.size();
    }
};