class Solution {
public:
    bool backspaceCompare(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;
        
        int cnti = 0, cntj = 0;
        
        while (i >= 0 and j >= 0) {
            if (a[i] != '#' and b[j] != '#') {
                if (a[i] == b[j]) {
                    i--;
                    j--;
                }
                else {
                    return false;
                }
            }
            while (i >= 0 and a[i] == '#') {
                i--;
                cnti++;
            }
            while (j >= 0 and b[j] == '#') {
                j--;
                cntj++;
            }


            while (cnti > 0) {
                if (i >= 0 and a[i] == '#') cnti += 2;
                i--;
                cnti--;
            }
            while (cntj > 0) {
                if (j >= 0 and b[j] == '#') cntj += 2;
                j--;
                cntj--;
            }
        }

        cout << "i: " << i << "  j: " << j << "\t";
        cout << "cnti: " << cnti << "  cntj: " << cntj << "\n";

        while (i >= 0) {
            if (a[i] != '#') {
                break;
            }
            else {
                while (i >= 0 and a[i] == '#') {
                    i--;
                    cnti++;
                }
                while (cnti > 0) {
                    if (i >= 0 and a[i] == '#') cnti += 2;
                    i--;
                    cnti--;
                }
            }
        }
        cout << "i: " << i << "  j: " << j << "\t";
        cout << "cnti: " << cnti << "  cntj: " << cntj << "\n";



        while (j >= 0) {
            if (b[j] != '#') {
                break;
            }
            else {
                while (j >= 0 and b[j] == '#') {
                    j--;
                    cntj++;
                }
                while (cntj > 0) {
                    if (j >= 0 and b[j] == '#') cntj += 2;
                    j--;
                    cntj--;
                }
            }
        }


        cout << "i: " << i << "  j: " << j << "\t";
        cout << "cnti: " << cnti << "  cntj: " << cntj << "\n";


        return (i == j) or (i < 0 and j < 0);
    }
};