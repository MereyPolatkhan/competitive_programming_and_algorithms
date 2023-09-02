// author: @assabiyah


class HitCounter {
public:
    deque<int> d;
    
    HitCounter() {

    }
    
    void hit(int t) { // O(1)
        d.push_back(t);

        // cout << "hit: " << t << "\n";
    }
    
    int getHits(int t) { // O(300)
        // cout << "get hits: " << t << "  res: " << d.size() << "\n";
        
        while (d.empty() == false and t - d.front() >= 300) {
            d.pop_front();
        }
        return d.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

 class HitCounter {
private:
    
    queue<int> hits;
    
public:
    
    /** Initialize your data structure here. */
    HitCounter() {
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front();
            if (diff >= 300) this->hits.pop();
            else break;
        }
        return this->hits.size();
    }
};


class HitCounter {
private:
    
    int total;
    queue<pair<int, int> > hits;
    
public:
    
    /** Initialize your data structure here. */
    HitCounter() {
        this->total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (this->hits.empty() || this->hits.back().first != timestamp) {
            // Insert the new timestamp with count = 1
            this->hits.push({timestamp, 1});
        } else {
            // Update the count of latest timestamp by incrementing the count by 1
            this->hits.back().second++;
        }
        this->total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front().first;
            if (diff >= 300) {
                // Decrement total by the count of the oldest timestamp
                this->total -= this->hits.front().second;
                this->hits.pop();
            }
            else break;
        }
        return this->total;
    }
};