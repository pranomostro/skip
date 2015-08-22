#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int waitfor(char* end);

int main(int argc, char** argv)
{
	int c;
	unsigned int i;

	if(argc!=3)
	{
		fprintf(stderr, "error: skip BEGIN END expected, exiting.\n");
		exit(1);
	}

	char* begin=argv[1];
	char* end=argv[2];

	char* buf=(char*) malloc(sizeof(char)*
		(strlen(begin)>strlen(end)?strlen(begin):strlen(end))
		);

	if(buf==NULL)
	{
		fprintf(stderr, "error: no random access memory left, exiting.\n");
		exit(2);
	}

	while(1)
	{
		if((c=getchar())==begin[0])
		{
			for(i=0; begin[i]==c&&i<=strlen(begin); i++)
			{
				buf[i]=c;
				c=getchar();

			}
			ungetc(c, stdin);
			if(i==strlen(begin))
			{
				if(waitfor(end))
					continue;
				else
					break;
			}
			else
			{
				buf[i]='\0';
				printf("%s", buf);
				continue;
			}

		}

		if(c==EOF)
			break;
		else
			putchar(c);
	}

	free(buf);

	return 0;
}

int waitfor(char* end)
{
	unsigned int i=0;
	int c;

	while(i!=strlen(end))
	{
		c=getchar();

		if(c==EOF)
			return 0;
		if(end[i]==c)
			i++;
		else
			i=0;
	}
	return 1;
}
