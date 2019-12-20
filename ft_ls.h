/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:49:48 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/22 22:57:07 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/xattr.h>
# include <string.h>
# include <time.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>

typedef struct	s_stat
{
	char			*name;
	char			*type;
	char			permissions[10];
	char			*gid;
	char			*uid;
	off_t			st_size;
	long			st_blocks;
	long			st_blksize;
	unsigned long	st_nlink;
	char			*mtime_str;
	long			mtime;
	int				maj;
	int				min;

}				t_stat;

typedef struct	s_dir
{
	t_stat			state;
	struct s_dir	*next;
}				t_dir;

typedef struct	s_spaces
{
	int b_max;
	int u_max;
	int g_max;
	int s_max;
	int min_max;
	int maj_max;
}				t_spaces;

typedef struct	s_input
{
	int		arc;
	char	**arv;
}				t_input;

typedef struct	s_er_count
{
	int		error;
	int		count;
}				t_er_count;

int				ft_get(t_dir **files_dir, char **flag, t_input in, int *error);
int				ft_flags_files(t_dir **files, char **flag, t_input in, int *er);
void			ft_add_flag(char **flags, char **arv, int *i, int memaloc);
void			ft_add_file(t_dir **file, char **arv, int i, int *er);
int				ft_add(t_dir **head, char *file);
int				ft_new(t_stat *element, struct stat state, char *file);
char			*ft_type(struct stat state);
void			ft_permession(char perm[10], struct stat state);
int				ft_f_check(char *flags);
int				ft_used_f(char *flags, char option);
void			ft_print_uid_gid(t_dir *files_dir, char *flags, t_spaces space);
void			ft_print_size(t_dir *files_dir, t_spaces space);
void			ft_print_date(t_dir *file, char *flag);
void			ft_print_link(t_dir *files_dir, char *path);
void			ft_print_info(t_dir *file, t_spaces sp, char *path, char *flag);
void			ft_list(t_dir *head, char *flags);
void			ft_min_maj(t_dir *files_dir, t_spaces sp);
int				ft_link(char *file, char **type);
int				ft_ch_num(int i);
void			ft_set_space(int i, t_spaces *space);
void			ft_info(t_dir *files_dir, t_spaces sp, char *path, char *fg);
int				ft_details(t_dir *head, char *path, char *flags);
void			ft_rec_check(t_dir *file_store, char *path, char *flags);
void			ft_rec(t_dir *file_store, char *path, char *flags);
char			*ft_join_path(char *path, char *name);
void			ft_cal_sp(t_dir *head, t_spaces *space, int *total);
void			ft_read_dir(char *name, char *flags, DIR *pdir, t_dir **file);
t_dir			*ft_extract_dir(char *name, char *falgs);
void			ft_put_dir(t_dir *dirc, char *flg, t_spaces sp, t_er_count er);
void			ft_put_files(t_dir *files, char *flg, t_spaces sp, int *count);
int				ft_put_arg(t_dir *files, char *flags, t_er_count er);
int				ft_put(t_dir *files_dir, char *flags, char *path);
void			ft_swap(t_stat *tmp1, t_stat *tmp2);
int				ft_cond_t(char *flags, t_dir *a, t_dir *b);
void			ft_type_order(t_dir **files_dir, t_dir **dirc);
void			ft_split(t_dir *sc, t_dir **fr, t_dir **ba);
t_dir			*ft_sorted(t_dir *a, t_dir *b, char *flags);
void			ft_merge_sort(t_dir **head, char *flags);
void			ft_f_error(char flags);
void			ft_error(char *file);
void			ft_check_error(char **file);
void			ft_free(t_dir **files_dir);
void			ft_free_2(t_dir *files_dir);
int				ft_cond_size(char *flags, t_dir *a, t_dir *b);
int				ft_cond_re(char *flags, t_dir *a, t_dir *b);
int				ft_cond(t_dir *a, t_dir *b, char *flags);
int				ft_run(t_dir *files_dir, char *flag, t_er_count er, t_input in);
void			ft_future_date(t_dir *file, char *dat, char **dat1);
void			ft_put_extra(t_dir *dirc, char *flg);

#endif
