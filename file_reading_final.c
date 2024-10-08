#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define MIN_ARGS 2
#define IN_ARG 1

void validate_args(int argc, char *argv[])
{
	if (argc < MIN_ARGS)
	{
		fprintf(stdout, "usage: %s input\n", argv[0]);
		exit(-1);
	}
}

FILE *open_file(char *name, char *mode)
{
	FILE *file = fopen(name, mode);
	if (file == NULL)
	{
		perror(name);
		exit(-1);
	}
	return file;
}

void echo_contents_fscanf(FILE *in_file)
{
	char c; 
	while(fscanf(in_file, "%c", &c) != EOF)
	{
		printf("%c", c);
	}
}

void echo_contents_getline(FILE *in_file)
{
	char *line = NULL;
	size_t size;
	
	while(getline(&line, &size, in_file) > 0)
	{
		printf("%s", line);
	}
	free(line);
}

int main(int argc, char *argv[])
{
	FILE *in;
	validate_args(argc, argv);
	in = open_file(argv[IN_ARG], "r");
	echo_contents_getline(in);
	fclose(in);
	return 0;
}
