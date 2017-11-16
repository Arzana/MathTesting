#include <cstdio>
#include "Core\Interpolation.h"

int main(void)
{
	for (float i = 0.0f; i < 1.0f; i += 0.1f)
	{
		printf("%f\n", DeJong::smoothstep(i));
	}

	getchar();
	return 0;
}