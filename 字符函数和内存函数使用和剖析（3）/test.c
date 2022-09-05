#include <stdio.h>
//
////  strncmp����
////  int strncmp(const char* string1, const char* string2, size_t count)
//#include <string.h>
//
//int main()
//{
//	const char* p1 = "abczef";
//	// "abcdef"�ǳ����ַ�������������ǲ��ܱ�ģ����Լ���const,ֻ�ǱȽ����ݣ�����ı�����
//	const char* p2 = "abceid";
//	int ret = strncmp(p1, p2,4);
//	//��p1��p2���бȽϣ��Ƚ�ǰ4��Ԫ�أ�һһ��Ӧ�Ƚ�
//	printf("%d\n", ret);
//	return 0;
//}

//���ĵ��г��� NULL ʱ��ָ���ǿ�ָ��
//���ĵ��г��� NUL / null ʱ��ָ���� '\0'


// ģ��ʵ��strstr����  - �����ַ���
// char* strstr(const char*,const char*)   ����һ����ַ��
// ���ص��ǵڶ����ַ����ڵ�һ���ַ����е�һ�γ���d��ַ
#include <string.h>
#include <assert.h>

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;  //char*��Ϊ�˺����淵�����Ͳ���ͻ
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
		printf("�ַ�������������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	// %s�Ǵӷ��ص��Ǹ���ַ��ʼ����ȡ��ֱ������ '\0'
	return 0;
}