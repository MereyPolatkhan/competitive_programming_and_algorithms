class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int begin = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                begin = i;
                break;
            }
        }

        int end = 0;
        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                end = i;
                break;
            }
        }
        

        int internal = 0;
        int cur = 0;
        for (int i = begin; i <= end; i++) {
            if (seats[i] == 0) {
                cur++;
            }
            else {
                cur = 0;
            }
            internal = max(internal, cur);
        }

        end = seats.size() - 1 - end;
        internal = ceil((internal * 1.0) / 2);

        return max(max(begin, end), internal);
    }
};