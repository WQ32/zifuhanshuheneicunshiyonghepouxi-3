#include <stdio.h>
//
////  strncmp函数
////  int strncmp(const char* string1, const char* string2, size_t count)
//#include <string.h>
//
//int main()
//{
//	const char* p1 = "abczef";
//	// "abcdef"是常量字符串，它本身就是不能变的，所以加上const,只是比较内容，不会改变内容
//	const char* p2 = "abceid";
//	int ret = strncmp(p1, p2,4);
//	//将p1和p2进行比较，比较前4个元素，一一对应比较
//	printf("%d\n", ret);
//	return 0;
//}

//当文档中出现 NULL 时，指的是空指针
//当文档中出现 NUL / null 时，指的是 '\0'


// 模拟实现strstr函数  - 查找字符串
// char* strstr(const char*,const char*)   返回一个地址，
// 返回的是第二个字符串在第一个字符串中第一次出现d地址
#include <string.h>
#include <assert.h>

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;  //char*是为了和上面返回类型不冲突
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;

}

int main()
{
	char* p1 = "abbbcdef";
	char* p2 = "bbc";
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("字符串不存在其中\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	// %s是从返回的那个地址开始向后读取，直至遇到 '\0'
	return 0;
}