#include <stdio.h>

int main(int argc, char const *argv[])
{
		int i = 0;
		switch(i)
		{
			case 0:
			{
				i = 9;
				break;
			}
			case 1:
			{
				i = 5;
				break;
			}
			case 2:
			{
				i = 6;
				break;
			}
			default:
			{
				i = 10;
			}
		}
		return 0;
		/*if(i < 0)
		{
			i = 9;
		}
		else if(i == 0)
		{
			i = 5;
		}
		else
		{
			i =7;
		}
		return 0;*/		
		
}