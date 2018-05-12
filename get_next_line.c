#include "libft/libft.h"
#include "get_next_line.h"

char    *xtnd_buf(int const fd, char *buf, int *ret)
{
    char    tmp[BUFF_SIZE + 1];
    char    *str = NULL;

    *ret = read(fd, tmp, BUFF_SIZE);
    tmp[*ret] = '\0';
    str = ft_strjoin(buf, tmp);
    free(buf);
    return (str);
}

int     get_next_line(int const fd, char **line)
{
    static char     *buf = "";
    int             ret;
    char            *str;

    if (!line || fd < 0 || fd > 5000)
        return (-1);
    ret = 1;
    if (buf[0] == '\0')
        buf = ft_strnew(0);
    while (ret > 0)
    {
        if ((str = ft_strchr(buf, '\n')) != NULL)
        {
            *str = '\0'; //replce newline with nullchar
            *line = ft_strdup(buf); //dup til nullchar
            ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
            return (1);
        }
        buf = xtnd_buf(fd, buf, &ret);
    }
    if (*buf)
    {
        *line = ft_strdup(buf);
    //    free(buf);
        ft_bzero(buf, ft_strlen(buf));
        return (1);
    }
    if (ret < 0)
        return(-1);
    return(0);
}