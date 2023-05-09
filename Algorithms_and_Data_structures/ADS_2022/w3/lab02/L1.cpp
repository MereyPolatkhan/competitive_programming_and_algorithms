# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
    Node* cur1 = head;
    int ans_max_sum = -1e7;

    while (cur1 != NULL) {
        Node* cur2 = cur1;
        int cur_sum = 0;
        
        while (cur2 != NULL) {
            cur_sum += cur2->val;

            ans_max_sum = max(ans_max_sum, cur_sum);

            if (cur_sum < 0) cur_sum = 0;

            cur2 = cur2->next;
        }

        cur1 = cur1->next;
    }
	
    return ans_max_sum;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
