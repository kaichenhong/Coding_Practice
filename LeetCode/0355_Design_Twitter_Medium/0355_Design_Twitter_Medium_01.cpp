/*
 *  Results:    AC (0 ms [100.00%];  7.1 MB [92.91%])
 */


class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweet_map[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        std::vector<int> results;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_q;

        for (const auto &id : follow_map[userId]) {
            for (const auto &tweet : tweet_map[id]) {
                if (min_q.size() >= 10 && (min_q.top().first > tweet.first))
                    continue;
                min_q.push(tweet);
                if (min_q.size() > 10)
                    min_q.pop();
            }
        }

        results.resize(min_q.size());
        for (int i = min_q.size() - 1; i >= 0; --i) {
            results[i] = min_q.top().second;
            min_q.pop();
        }

        return results;
    }

    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        follow_map[followerId].erase(followeeId);
    }

private:
    unsigned int timestamp;
    std::unordered_map<int, unordered_set<int>> follow_map;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweet_map;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

