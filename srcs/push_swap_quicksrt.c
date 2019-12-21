/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksrt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:09:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/19 12:54:48 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *ps)
{
	ps_info(ps);
	print_list(A_LST, "ORG A", ' ');
	A_LST = ps_do_quicksort(A_LST, &(CMD), 'a');
	print_cmd_list(CMD);
	print_list(A_LST, "RES A", ' ');
	clear_ps(ps);
}

void	init_ps(t_ps *ps)
{
	ft_bzero(ps, sizeof(t_ps));
	ps->org = NULL;
	ps->a = (t_stk*)malloc(sizeof(t_stk));
	ft_bzero(ps->a, sizeof(t_stk));
	ps->a->lst = NULL;
	ps->b = (t_stk*)malloc(sizeof(t_stk));
	ft_bzero(ps->b, sizeof(t_stk));
	ps->b->lst = NULL;
	ps->cmds = NULL;
}

void	ps_info(t_ps *ps)
{
	ps->count = count_list(ps->a->lst);
	ps->min = find_min(ps->a->lst);
	ps->max = find_max(ps->a->lst);
	ps->a->count = count_list(ps->a->lst);
	ps->a->min = find_min(ps->a->lst);
	ps->a->max = find_max(ps->a->lst);
	ps->b->count = count_list(ps->b->lst);
	ps->b->min = find_min(ps->b->lst);
	ps->b->max = find_max(ps->b->lst);
}

void	do_pb(t_ps *ps)
{
	ft_printf("@do_pb\n");
	push(&(B_LST), &(A_LST));
	CMD = create_cmd_back(CMD, "pb");
	ps_info(ps);
}

void	do_pa(t_ps *ps)
{
	ft_printf("@do_pa\n");
	push(&(A_LST), &(B_LST));
	CMD = create_cmd_back(CMD, "pa");
	ps_info(ps);
}

void	do_sa(t_ps *ps)
{
	ft_printf("@do_sa\n");
	A_LST = swap_top2(A_LST);
	CMD = create_cmd_back(CMD, "sa");
}

void	do_sb(t_ps *ps)
{
	ft_printf("@do_sb\n");
	B_LST = swap_top2(B_LST);
	CMD = create_cmd_back(CMD, "sb");
}

void	do_ra(t_ps *ps)
{
	ft_printf("@do_ra\n");
	A_LST = rotate(A_LST);
	CMD = create_cmd_back(CMD, "ra");
}

void	do_rb(t_ps *ps)
{
	ft_printf("@do_rb\n");
	B_LST = rotate(B_LST);
	CMD = create_cmd_back(CMD, "rb");
}

void	do_rra(t_ps *ps)
{
	ft_printf("@do_rra\n");
	A_LST = rev_rotate(A_LST);
	CMD = create_cmd_back(CMD, "rra");
}

void	do_rrb(t_ps *ps)
{
	ft_printf("@do_rrb\n");
	B_LST = rev_rotate(B_LST);
	CMD = create_cmd_back(CMD, "rrb");
}