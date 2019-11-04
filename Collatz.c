#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>

int main()
{
	int n = 0;
	int k = 0;

	int pid;

	do
	{
		printf("Collatz Problemi Çözümü için Bir Sayý Giriniz: .\n");
		scanf("%d", &k);
	} while (k <= 0);

	pid = fork();

	if (pid == 0)
	{
		printf("Child process çalýþýyor...\n");
		printf("%d\n", k);
		while (k != 1)
		{
			if (k % 2 == 0)
			{
				k = k / 2;
			}
			else if (k % 2 == 1)
			{
				k = 3 * (k)+1;
			}

			printf("%d\n", k);
		}

		printf("Child process tamamlandý.\n");
	}
	else
	{
		printf("Parents process child process’ i bekliyor...\n");
		wait();
		printf("Parent process tamamlandý.\n");
	}
	return 0;
}
