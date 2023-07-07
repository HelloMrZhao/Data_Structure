#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����׳˵ݹ�Fac��ʱ�䷢���Ӷ�
long long Fac(size_t N)
{
	if (0 == N)
		return 1;
	return Fac(N - 1) * N;
}
//�˴����ʱ�临�Ӷ���O(N)


//����쳲������ݹ�Fib��ʱ�临�Ӷ�
long long Fib(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);
}
//쳲�������ֻ�����ۼ�ֵû��ʵ�ʼ�ֵ
//쳲������ݹ��ѭ���Ժ�ʱ�临�Ӷ���O(N)

int main()
{
	printf("%11d\n", Fac(40)); //2^40=1024*1024*1024*1024==1��������
	printf("%11d\n", Fib(40));

		return 0;
}


//�ռ临�Ӷȣ�
//�ռ临�Ӷ�Ҳ��һ���������ʽ���Ƕ�һ���㷨�����й�������ʱռ�ô洢�ռ��С������
//�ռ临�ӶȲ��ǳ���ռ���˶���byttes�Ŀռ䣬��Ϊ���Ҳû��̫������壬���Կռ临�Ӷ�����Ǳ����ĸ���
//�ռ临�Ӷȼ�����������ʱ�临�Ӷ����ƣ�Ҳ���ô�O������ʾ��

//ע�⣺��������ʱ����Ҫ��ջ�ռ䣨�洢�������ֲ�������һЩ�Ĵ�����Ϣ�ȣ��ڱ����ڼ��ѽ�ȷ�����ˣ���˿ռ临�Ӷ���Ҫͨ������������ʱ����ʾ�������ռ���ȷ��
//ʱ���ǿ����ۻ��Ŀռ��ǲ����ۻ��Ŀ����ظ�����

//����׳˵ݹ�Fac�Ŀռ临�Ӷ�
long long Fac(size_t N)
{
	if (N == 0)
	{
		return 1;

		return Fac(N - 1) * N;
	}
}
//�ռ临�Ӷ���O(N)


//����쳲���������Fib�Ŀռ临�Ӷ�
long long Fibb(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);

}
//�ռ临�Ӷ���O(N)
//ʱ�临�Ӷ���O(2^N)



//��ת����
//����һ�����齫�����е�Ԫ��������תK��λ�ã�����K�ǷǸ�����
//���´���Ŀռ临�Ӷ���O(N)
//���룺nums = [1,2,3,4,5,6,7], k = 3
//�����[5,6,7,1,2,3,4]
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




