//STDHEADER
#include "get_next_line.h"

static char *read_line(int fd, char *saved)
{
    char    *buffer;
    ssize_t bytes_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(saved, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        saved = ft_strjoin(saved, buffer);
    }
    free(buffer);
    return (saved);
}

char    *get_next_line(int fd)
{
    static char *saved;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    saved = read_line(fd, saved);
    if (!saved)
        return (NULL);
    line = extract_line(saved);
    saved = update_saved(saved);
    return (line);
}