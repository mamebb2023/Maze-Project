#ifndef PARSER_H
#define PARSER_H

// parser.c
int count_rows(FILE *fp);
int in_array(char needle, char *haystack, unsigned int haystack_size);
void validate_line_data(int max_line_count, char *line, FILE *fp,
		int line_number);
char *concat(const char *s1, const char *s2);
void free_map(map_t *map);

// files.c
void close_file(FILE *fp);
map_t handle_file(char *filename);
FILE *open_file(char *filename);
map_t read_file(FILE *fp);
char *get_row(char *line);

#endif /* PARSER_H */
