class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, bool> startMap;
		for (int x : nums) {

			if (startMap.find(x - 1) == startMap.end()) {
				startMap[x] = true;
			} else {
				startMap[x] = false;
			}

			if (startMap.find(x + 1) != startMap.end()) {
				startMap[x + 1] = false;
			}

		}

		int ans = 0;

		for (pair<int, bool> p : startMap) {
			int key = p.first;
			bool status = p.second;
			if (status) {
				// find the len of the sequence of consecutive
				// elements that start from key
				int cnt = 0;
				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}
				ans = max(ans, cnt);
			}
		}

		return ans;

	}
};