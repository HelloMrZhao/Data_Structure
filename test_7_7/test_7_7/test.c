#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//计算阶乘递归Fac的时间发复杂度
long long Fac(size_t N)
{
	if (0 == N)
		return 1;
	return Fac(N - 1) * N;
}
//此代码的时间复杂度是O(N)


//计算斐波那契递归Fib的时间复杂度
long long Fib(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);
}
//斐波那契数只有理论价值没有实际价值
//斐波那契递归改循环以后，时间复杂度是O(N)

int main()
{
	printf("%11d\n", Fac(40)); //2^40=1024*1024*1024*1024==1万亿左右
	printf("%11d\n", Fib(40));

		return 0;
}


//空间复杂度：
//空间复杂度也是一个函数表达式，是对一个算法在运行过程中临时占用存储空间大小的量度
//空间复杂度不是程序占用了多少byttes的空间，因为这个也没有太大的意义，所以空间复杂度算的是变量的个数
//空间复杂度计算规则基本跟时间复杂度类似，也是用大O渐进表示法

//注意：函数运行时所需要的栈空间（存储参数、局部变量、一些寄存器信息等）在编译期间已进确定好了，因此空间复杂度主要通过函数在运行时候显示申请额外空间来确定
//时间是可以累积的空间是不能累积的可以重复利用

//计算阶乘递归Fac的空间复杂度
long long Fac(size_t N)
{
	if (N == 0)
	{
		return 1;

		return Fac(N - 1) * N;
	}
}
//空间复杂度是O(N)


//计算斐波那契数列Fib的空间复杂度
long long Fibb(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);

}
//空间复杂度是O(N)
//时间复杂度是O(2^N)



//轮转数组
//给你一个数组将数组中的元素向右轮转K个位置，其中K是非负数。
//以下代码的空间复杂度是O(N)
//输入：nums = [1,2,3,4,5,6,7], k = 3
//输出：[5,6,7,1,2,3,4]
void reverse(int*p ,int left, int right)
{
	while (left < right)
	{
		int tmp = p[left];
		p[left] = p[right];
		p[right] = tmp;
		++left;
		--right;
	}
}

void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;

	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, 0, numsSize - 1);
}




