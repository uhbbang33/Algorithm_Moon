#include <iostream>
using namespace std;

void rowCheck(int N, char board[], int& max, int sameCandy[]);
void colCheck(int N, char board[], int& max, int sameCandy[]);

int main()
{
	int N = 0;
	cin >> N;

	char* board = new char[N * N]{};
	for (int i = 0; i < N * N; ++i)
		cin >> board[i];

	int max = 0;

	int* sameCandy = new int[N] {};
	for (int i = 0; i < N; ++i)
		sameCandy[i] = 1;

	// 위아래 바꾸기
	for (int l = 0; l < N * (N - 1); ++l) {

		swap(board[l], board[l + N]);

		rowCheck(N, board, max, sameCandy);
		colCheck(N, board, max, sameCandy);

		swap(board[l], board[l + N]);
	}

	// 왼쪽 오른쪽 바꾸기
	for (int l = 0; l < N * N - 1; ++l) {
		if ((l + 1) % N == 0)
			continue;

		swap(board[l], board[l + 1]);

		rowCheck(N, board, max, sameCandy);
		colCheck(N, board, max, sameCandy);

		swap(board[l], board[l + 1]);
	}
	
	cout << max << endl;

	delete[] board, sameCandy;

	return 0;
}

void rowCheck(int N, char board[], int& max, int sameCandy[])
{
	char lastBoard = 'A';

	int cnt = 0;
	
	for (int i = 0; i < N; ++i) {					// 행
		lastBoard = 'A';
		for (int j = i * N; j < (i + 1) * N; ++j) {	// 행의 원소 하나하나
			if (board[j] == lastBoard)
				++sameCandy[cnt];
			else if (max > sameCandy[cnt])
				sameCandy[cnt] = 1;
			else
				++cnt;

			lastBoard = board[j];
		}
	}

	for (int i = 0; i < N; ++i) {
		if (max < sameCandy[i])
			max = sameCandy[i];
		sameCandy[i] = 1;
	}
}

void colCheck(int N, char board[], int& max, int sameCandy[])
{
	char lastBoard = 'A';

	int cnt = 0;

	for (int i = 0; i < N; ++i) {					// 열
		lastBoard = 'A';
		for (int j = i; j <= N * (N - 1) + i; j += N) {
			if (board[j] == lastBoard)
				++sameCandy[cnt];
			else if (max > sameCandy[cnt])
				sameCandy[cnt] = 1;
			else
				++cnt;

			lastBoard = board[j];
		}
	}

	for (int i = 0; i < N; ++i) {
		if (max < sameCandy[i])
			max = sameCandy[i];
		sameCandy[i] = 1;
	}
}