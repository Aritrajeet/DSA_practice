
#include <bits/stdc++.h>
using namespace std;

int N = 0;
void wait()
{
	cout << "Channel is occupied by someone" << endl;
}
int show_status(vector<int> time, int x)
{
	int status;
	for (int i = 0; i < x; i++)
	{
		if (time[i] == time[x])
		{
			status = 2;
			break;
		}
		else
		{
			status = 0;
		}
	}
	return status;
}
void solve_collision(vector<int> &time, int x)
{
	int temp = rand() * (pow(2, N - 1) - 1);
	cout << "Waiting for: " << temp << " seconds" << endl;
	// int temp = 1;
	time[x] += temp;
}
void csma(vector<int> time)
{
	int status;
	for (int i = 0; i < time.size(); i++)
	{
		int status = show_status(time, i);
		// sense the channel
		if (status == 0)
		{
			cout << "Channel is free!" << endl;
			wait();
		}
		else
		{
			N++;
			if (N >= 16)
			{
				cout << "Limit reached ! Abort";
				return;
			}
			cout << "Collision" << endl;
			solve_collision(time, i);
			// thread t1(solve_collision, time, i);
			// t1.join();
			i--;
		}
	}
}

int main()
{
	int packets;
	int status = 0; // 0 for idle , 1 for busy , 2 for collision
	cout << "Number of packets: ";
	cin >> packets;
	vector<int> time;
	cout << "Enter the time at which packets are sent: " << endl;
	int temp;
	for (int i = 0; i < packets; i++)
	{
		cin >> temp;
		time.push_back(temp);
	}
	csma(time);
	return 0;
}
