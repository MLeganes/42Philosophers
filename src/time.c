/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:50:15 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/04 13:14:22 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Returns the timestamp in milliseconds
*/
long    get_mtime(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

/*
** Prints time, sleeps 200ms, repeats!
*/

int print_mtime(void)
{
    long start_time;
		
		// Remember when we started
    start_time = get_mtime();

    while (1)
    {
				// Print time from start, in ms
        printf("%ld\n", get_mtime() - start_time);

				// Sleep 200 times 1000 microseconds (1 millisecond)
        usleep(200 * 1000);
    }
}

/*
** Returns the timestamp in milliseconds
*/
long    print_milis(void)
{
	long start_time;
	long one_mili_more;

	start_time = get_mtime();
	one_mili_more = start_time  * 1000;
	printf("Start time: %ld One mili more: %ld \n", start_time, one_mili_more);
	while(1)
	{
		//printf("%ld \n", get_mtime() - start_time);
		//usleep(999900); //1 second
		
		start_time = get_mtime();
		one_mili_more = start_time  * 1000;
		while (start_time < one_mili_more)
		{
			usleep(200);
		}
		printf("%ld \n", get_mtime() - start_time);
		
	}
}
