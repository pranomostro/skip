#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int waitfor(char* end);

int main(int argc, char** argv)
{
	char c;
	unsigned int i;
	char* begin, * end, * buf;

	if(argc!=3)
	{
		fprintf(stderr, "skip begin end\n");
		exit(1);
	}

	begin=argv[1];
	end=argv[2];

	buf=(char*) malloc(sizeof(char)*
		(strlen(begin)>strlen(end)?strlen(begin):strlen(end)));

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

		if(feof(stdin))
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
	char c;

	while(i<strlen(end))
	{
		c=getchar();

		if(feof(stdin))
			return 0;
		else if(c==end[i])
			i++;
		else if(c==end[0])
			i=1;
		else
			i=0;
	}
	return 1;
}
