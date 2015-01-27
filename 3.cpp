/* 
 *求子数组的最大和(数组)
 */

#include <iostream>

using namespace std;


int GetMax(int *a, int n)
{
	int i;
	bool flag = true; //判别是否全部是负数
  	int max = a[0];	
	for (i = 0; i < n; i++) {
		if (a[i] >= 0) {
			flag = false;
			break;
		}
		if (a[i] > max)
			max = a[i];
	}

	if (flag)
		return max;

	int temp = 0;;
	int maxSubSum = 0;
	for (i = 0; i < n; i++) {
		temp += a[i];
		if (temp < 0) 
			temp = 0;
		else {
			if (temp > maxSubSum)
				maxSubSum = temp;
		}
	}
	
	return maxSubSum;
}

int main()
{
	int a[] = {1,-2,3,10,-4,7,2,-5};
	cout << GetMax(a, 8) << endl;

	int b[] = {-1,-6,-7,0};
	int c[] = {-1,-6,-3};

	cout << GetMax(b, 4) << " " << GetMax(c,3) << endl;

	return 0;
}
