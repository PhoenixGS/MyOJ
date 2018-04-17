#include <cstdio>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <ctime>
int T, N, K;
int main()
{
	srand(time(NULL));
	scanf("%d%d%d", &T, &N, &K);
	printf("%d %d %d\n", T, N, K);
	std::set < std::pair < int, int > > S;
	S.insert({ 0, 0 });
	while (N--)
	{
		int x, y;
		do x = rand() % (T + T + 1) - T, y = rand() % (T + T + 1) - T; while (abs(x) + abs(y) + ((K - 1) << 1) <= T || S.find({ x, y }) != S.end());
		printf("%d %d\n", x, y);
		S.insert({ x, y });
	}
}
