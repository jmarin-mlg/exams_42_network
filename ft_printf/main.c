#ifndef ORIGINAL_PRINTF
	#define F	len += ft_printf
#else
	#define F	len += printf
#endif

#ifndef LOOP
	#define LOOP 1
#else
	#if	LOOP < 1 || LOOP > 2147483647
		#error "LOOP must be between 1 and 2147483647"
	#endif
#endif

#include <stdio.h> // For printf
#include <time.h>  // For type clock_t and clock function

// PROTOTYPES
int	ft_printf(char const *format, ...);

int main(void)
{
	clock_t start, end;
    double	cpu_time_used;
	int		len;

    start = clock();

	for (int i = 1; i <= LOOP; ++i)
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

		F("\n--Mixed---\n");
		F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int) -2147483648, (int) -2147483648);
		F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int) -2147483648, (int) -2147483648);

		// The Linux compiler does not support NULL parameters
		// for the %s conversion
		#ifndef __linux__
			F("\n--Nulleables---\n");
			F("%s\n", NULL);
			F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
			F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
			F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	    #endif

		F("written: %d\n\n\n", len);
	}

	end = clock();

    cpu_time_used = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("The program took %f milliseconds to run.\n", cpu_time_used);

    return (0);
}
