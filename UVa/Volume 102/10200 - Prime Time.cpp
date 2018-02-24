#include <iostream>
#include <iomanip>
#include <cmath>

bool isPrime(int n) {
	for(int i=2;i*i<=n;++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

double round(double n) {
	return floor((n+0.005) * 100) / 100;
}

double T[10000+10] = {0};

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	double *count = &T[1];
	count[-1] = 0;
	for(int i=0;i<=10005;++i) {
		count[i] = count[i-1];
		if (isPrime(i*i+i+41)) {
			count[i] += 1;
		}
	}
	int a, b;
	while(std::cin >> a >> b) {
		printf("%.2lf\n", round((count[b]-count[a-1]) / (double)(b-a+1) * 100));
	}
	return 0;
}
