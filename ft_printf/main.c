#include <stdio.h>
#include <time.h>

#define ORIGINAL_PRINTF printf

#ifndef ORIGINAL_PRINTF
# define F	len += ft_printf
#else
# define F	len += ORIGINAL_PRINTF
#endif

int	ft_printf(char const *format, ...);

int main(void)
{
	clock_t start, end;
    double cpu_time_used;
	int	len;

    start = clock();

	for (int i = 1; i <= 10000; ++i)
	{
		len = 0;

		F("Simple test\n");
		F("--Format---");
		F("\n");
		F("%d\n", 0);
		F("%d\n", 42);
		F("%d\n", 1);
		F("%d\n", 5454);
		F("%d\n", (int)2147483647);
		F("%d\n", (int)2147483648);
		F("%d\n", (int)-2147483648);
		F("%d\n", (int)-2147483649);
		F("\n");
		F("%x\n", 0);
		F("%x\n", 42);
		F("%x\n", 1);
		F("%x\n", 5454);
		F("%x\n", (int)2147483647);
		F("%x\n", (int)2147483648);
		F("%x\n", (int)-2147483648);
		F("%x\n", (int)-2147483649);
		F("%x\n", (int)0xFFFFFFFF);
		F("\n");
		F("%s\n", "");
		F("%s\n", "toto");
		F("%s\n", "wiurwuyrhwrywuier");

		#ifndef ORIGINAL_PRINTF
		F("%s\n", NULL);
		#else
		F("%p\n", NULL);
		#endif

		#ifndef ORIGINAL_PRINTF
		F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		#else
		F("-%s-%s-%s-%p-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		#endif

		F("\n--Mixed---\n");
		F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
		F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
		F("\n");

		#ifndef ORIGINAL_PRINTF
		F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		#else
		F("%s%s%s%p\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		F("-%s-%s-%s-%p-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
		#endif

		printf("written: %d\n", len);
	}

	end = clock();

    cpu_time_used = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("The program took %f milliseconds to run.\n", cpu_time_used);

    return (0);
}
