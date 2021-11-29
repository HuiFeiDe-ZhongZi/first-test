//#include<iostream>
//using namespace std;
//
//void merge(int* nums1, int m, int* nums2, int n)
//{
//	for (int i = 0; i<n; i++)
//	{
//		int j = m - 1;
//		for (; j >= 0; j--)
//		{
//			if (nums2[i]<nums1[j])
//			{
//				nums1[j + 1] = nums1[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		nums1[j + 1] = nums2[i];
//		m++;
//	}
//	for (int i = 0; i < 6; i++)
//	{
//		cout << nums1[i] << endl;
//	}
//}
//int main()
//{
//	// 传入的是插入位置
//	int arr1[] = { 1,8,11,0,0,0 };
//	int arr2[] = { 2,7,10 };
//	int m = 3;
//	int n = 3;
//	merge(arr1, m, arr2, n);
//	return 0;
//}