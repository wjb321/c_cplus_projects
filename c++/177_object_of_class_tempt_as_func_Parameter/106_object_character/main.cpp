#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//#define TarrValue                        0
//#define TpscValue                        83
//float Radian = 0.523;
//float Radius = 0.045;//4.5//
//#define PI                               3.14159
//float Decelerate = 30;
//float STMFxCLK = 84;
//float TmethodFreq = (1.0 / (((TarrValue + 1)*(TpscValue + 1)) / (STMFxCLK * pow(10.0, 6.0))));
//float Pulse = 30;
//float ENCODER_TIM_PSC = 0;        /*计数器分频*/
//float ENCODER_TIM_PERIOD = 65535;  /*计数器最大值*/
//float CNT_INIT = 0;
//float ENCODER_RESOLUTION = 11;  /*编码器一圈的物理脉冲数*/
//float ENCODER_MULTIPLE = 4;     /*编码器倍频，通过定时器的编码器模式设置*/
//float MOTOR_REDUCTION_RATIO = 4.4; /*电机的减速比*/
//float TOTAL_RESOLUTION = (ENCODER_RESOLUTION*ENCODER_MULTIPLE*MOTOR_REDUCTION_RATIO);
//float TvCoefficient = (2.0* PI * Radius * 60 * TmethodFreq * Pulse) / (TOTAL_RESOLUTION *1.0);
//float Intermediate_parameter = (4 * Decelerate * Radian * Radius);
//float Denominator_parameter = (-2 * Decelerate) / (TmethodFreq*1.0);
//float Numerator_parameter = (Radian * TmethodFreq * Radius);
//float Top_parameter = 0;
//int  frequencyVal0  = 4712;
//float  frequencyVal1 = 0;
//float kkk = 0;
//void main()
//{
//	Top_parameter = Numerator_parameter / (frequencyVal0*1.0);
//	printf("Numerator_parameter %.10f\n", Numerator_parameter);
//	printf("Top_parameter %.7f\n", Top_parameter);
//	kkk = sqrt(Top_parameter * Top_parameter - Intermediate_parameter);
//	printf("kkk %.11f\n", kkk);
//	printf("Intermediate_parameter %.7f\n", Intermediate_parameter);
//	printf("Denominator_parameter %.6f\n", Denominator_parameter);
//	frequencyVal1 = ((-Top_parameter + kkk) / Denominator_parameter);
//	
//	printf("frequencyVal1 %9f\n", frequencyVal1);
//	printf("top %.9f\n", -Top_parameter + sqrt(Top_parameter * Top_parameter - Intermediate_parameter));
//	
//	printf("TmethodFreq %.7f\n", TmethodFreq);
//	
//	getchar();
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int partition(int *arr, int left, int right) {
//	int pivot = arr[right];  // 以最后一个元素为基准
//	int i = left - 1;
//	for (int j = left; j <= right - 1; j++) {
//		if (arr[j] < pivot) {
//			i++;
//			int temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//		}
//	}
//	int temp = arr[i + 1];
//	arr[i + 1] = arr[right];
//	arr[right] = temp;
//	return i + 1;
//}
//
//int select(int *arr, int left, int right, int k) {
//	if (left == right) {
//		return arr[left];
//	}
//	int pivotIndex = partition(arr, left, right);
//	int len = pivotIndex - left + 1;
//	if (k == len) {
//		return arr[pivotIndex];
//	}
//	else if (k < len) {
//		return select(arr, left, pivotIndex - 1, k);
//	}
//	else {
//		return select(arr, pivotIndex + 1, right, k - len);
//	}
//}
//
//int cmp(const void *a, const void *b) {
//	return (*(int*)a - *(int*)b);
//}
//
//int main() {
//	int arr[] = { 5, 2, 9, 1, 7, 6, 8, 3, 4, 10, 10, 10, 10};//1 2 3 4 5 6 7 8 9 10 10 10 10 
//	int len = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, len, sizeof(int), cmp);  // 先排序
//	int median;
//	if (len % 2 == 0) {  // 偶数个元素
//		median = (select(arr, 0, len - 1, len / 2) + select(arr, 0, len - 1, len / 2 + 1)) / 2;
//	}
//	else {  // 奇数个元素
//		median = select(arr, 0, len - 1, len / 2 + 1);
//	}
//	printf("The median of the array is: %d\n", median);
//	getchar();
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SWAP(a, b) { typeof(a) temp = a; a = b; b = temp; }
//
//int partition(int arr[], int low, int high)
//{
//    int pivot = arr[high];
//    int i = low - 1;
//
//    for (int j = low; j < high; j++)
//    {
//        if (arr[j] < pivot)
//        {
//            i++;
//            SWAP(arr[i], arr[j]);
//        }
//    }
//    SWAP(arr[i + 1], arr[high]);
//
//    return i + 1;
//}
//
//int quick_select(int arr[], int low, int high, int k)
//{
//    if (low == high)
//    {
//        return arr[low];
//    }
//
//    int pivot_idx = partition(arr, low, high);
//    int left_len = pivot_idx - low + 1;
//
//    if (k == left_len)
//    {
//        return arr[pivot_idx];
//    }
//    else if (k < left_len)
//    {
//        return quick_select(arr, low, pivot_idx - 1, k);
//    }
//    else
//    {
//        return quick_select(arr, pivot_idx + 1, high, k - left_len);
//    }
//}
//
//int median(int arr[], int len)
//{
//    int k = len / 2 + 1;
//    return quick_select(arr, 0, len - 1, k);
//}
//
//int main()
//{
//    int arr[] = { 5, 2, 9, 1, 7, 6, 8, 3, 4 };
//    int len = sizeof(arr) / sizeof(int);
//
//    int med = median(arr, len);
//    printf("Median: %d\n", med);
//
//    return 0;
//}

#include <stdio.h>

int quick_select(int arr[], int left, int right, int k);

void swap(int *a, int *b);

int partition(int arr[], int left, int right, int pivot_index);

int median(int arr[], int n);

int main() {
	int arr[] = { 5, 2, 9, 1, 7, 6, 8, 3, 4 ,10, 11, 12, 13, 14, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = median(arr, n);
	printf("Median = %d\n", m);
	getchar();
	return 0;
}

int quick_select(int arr[], int left, int right, int k) {
	if (left == right) {
		return arr[left];
	}
	int pivot_index = left + (right - left) / 2;
	pivot_index = partition(arr, left, right, pivot_index);
	if (k == pivot_index) {
		return arr[k];
	}
	else if (k < pivot_index) {
		return quick_select(arr, left, pivot_index - 1, k);
	}
	else {
		return quick_select(arr, pivot_index + 1, right, k);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right, int pivot_index) {
	int pivot_value = arr[pivot_index];
	swap(&arr[pivot_index], &arr[right]);
	int store_index = left;
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot_value) {
			swap(&arr[i], &arr[store_index]);
			store_index++;
		}
	}
	swap(&arr[store_index], &arr[right]);
	return store_index;
}

int median(int arr[], int n) {
	if (n % 2 == 1) {
		return quick_select(arr, 0, n - 1, n / 2);
	}
	else {
		int left = quick_select(arr, 0, n - 1, n / 2 - 1);
		int right = quick_select(arr, 0, n - 1, n / 2);
		return (left + right) / 2;
	}
}
