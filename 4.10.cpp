#define _CRT_SECURE_NO_WARNINGS 1

static const char* const task_state_array[] = 
{
	"R (running)", /* 0 */
	"S (sleeping)", /* 1 */
	"D (disk sleep)", /* 2 */
	"T (stopped)", /* 4 */
	"t (tracing stop)", /* 8 */
	"X (dead)", /* 16 */
	"Z (zombie)", /* 32 */
};

struct runqueue
{
	int num;
	task_struct* q;
};

int main()
{
	while (1)
	{
		;
	}
	return 0;
}