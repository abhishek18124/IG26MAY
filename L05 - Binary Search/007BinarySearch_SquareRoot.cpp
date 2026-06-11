#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

bool f(int n, int t, vector<ll> arr, ll mid) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += mid / arr[i];
	}
	return sum >= t;
}

int main() {

	int n, t;
	cin >> n >> t;

	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll lo = 1;
	ll hi = *min_element(arr.begin(), arr.end()) * t;

	ll ans;

	while (lo <= hi) { // log(hi-lo) * n ~ 60 * n

		ll mid = lo + (hi - lo) / 2;

		// can n machines make t products in mid time ?

		if (f(n, t, arr, mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}

	}

	cout << ans;

	return 0;
}