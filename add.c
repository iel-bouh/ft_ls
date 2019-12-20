/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:46:17 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/22 23:13:22 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_add(t_dir **head, char *file)
{
	t_dir		*tmp;
	t_dir		*element;
	struct stat state;

	element = (t_dir *)malloc(sizeof(t_dir));
	if (!element)
		return (0);
	element->next = NULL;
	if (lstat(file, &state) == -1)
	{
		return (-1);
	}
	tmp = *head;
	if (ft_new(&(element->state), state, file) == -1)
		return (-1);
	if (!(*head))
	{
		*head = element;
		return (0);
	}
	while ((tmp)->next)
		tmp = (tmp)->next;
	(tmp)->next = element;
	return (0);
}

int		ft_new(t_stat *element, struct stat state, char *file)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(state.st_uid);
	grp = getgrgid(state.st_gid);
	(element)->st_size = state.st_size;
	(element)->type = ft_type(state);
	if (element->type[0] == 'l')
	{
		if (ft_link(file, &(element->type)) == -1)
			return (-1);
	}
	(element)->name = ft_strdup(file);
	ft_permession((element)->permissions, state);
	(element)->uid = ft_strdup(pwd->pw_name);
	(element)->gid = ft_strdup(grp->gr_name);
	(element)->st_blksize = state.st_blksize;
	(element)->st_blocks = state.st_blocks;
	(element)->mtime_str = ft_strdup(ctime(&(state.st_mtime)));
	(element)->mtime = state.st_mtime;
	(element)->st_nlink = state.st_nlink;
	(element)->maj = major(state.st_rdev);
	(element)->min = minor(state.st_rdev);
	return (0);
}

int		ft_link(char *file, char **type)
{
	char		buf[4097];
	char		*buff;
	struct stat	state1;

	ft_memset(buf, 0, sizeof(buf));
	readlink(file, buf, sizeof(buf) - 1);
	if (file[0] == '/')
		buff = ft_strjoin("/", buf);
	else
		buff = strdup(buf);
	lstat(buff, &state1);
	ft_memdel((void **)&buff);
	*type = ft_strjoin(*type, ft_type(state1));
	if (!*type)
		return (-1);
	return (0);
}

char	*ft_type(struct stat state)
{
	if (S_ISLNK(state.st_mode))
		return ("l");
	else if (S_ISDIR(state.st_mode))
		return ("d");
	else if (S_ISFIFO(state.st_mode))
		return ("p");
	else if (S_ISCHR(state.st_mode))
		return ("c");
	else if (S_ISBLK(state.st_mode))
		return ("b");
	else if (S_ISSOCK(state.st_mode))
		return ("s");
	else if (S_ISREG(state.st_mode))
		return ("-");
	else
		return ("?");
}

void	ft_permession(char perm[10], struct stat state)
{
	perm[0] = (state.st_mode & S_IRUSR) ? 'r' : '-';
	perm[1] = ((state.st_mode) & S_IWUSR) ? 'w' : '-';
	perm[2] = ((state.st_mode) & S_IXUSR) ? 'x' : '-';
	perm[3] = ((state.st_mode) & S_IRGRP) ? 'r' : '-';
	perm[4] = ((state.st_mode) & S_IWGRP) ? 'w' : '-';
	perm[5] = ((state.st_mode) & S_IXGRP) ? 'x' : '-';
	perm[6] = ((state.st_mode) & S_IROTH) ? 'r' : '-';
	perm[7] = ((state.st_mode) & S_IWOTH) ? 'w' : '-';
	perm[8] = ((state.st_mode) & S_IXOTH) ? 'x' : '-';
	if ((state.st_mode) & S_ISUID)
		perm[2] = (perm[2] == 'x') ? 's' : 'S';
	if ((state.st_mode) & S_ISGID)
		perm[5] = (perm[5] == 'x') ? 's' : 'S';
	if ((state.st_mode) & S_ISVTX)
		perm[8] = (perm[8] == 'x') ? 't' : 'T';
	perm[9] = '\0';
}
