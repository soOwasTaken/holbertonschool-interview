#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: Points to an array of integers containing size elements
 * @size: Number of elements in line
 * @direction: Direction to slide & merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t start, end, step, pos;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        start = 0;
        end = size;
        step = 1;
    }
    else
    {
        start = size - 1;
        end = -1;
        step = -1;
    }

    for (size_t i = start; i != end; i += step)
    {
        if (line[i] != 0)
        {
            pos = i;
            while (pos != start && line[pos - step] == 0)
            {
                line[pos - step] = line[pos];
                line[pos] = 0;
                pos -= step;
            }
        }
    }

    for (size_t i = start; i != end; i += step)
    {
        if (line[i] != 0 && i + step != end && line[i] == line[i + step])
        {
            line[i] *= 2;
            line[i + step] = 0;
        }
    }

    for (size_t i = start; i != end; i += step)
    {
        if (line[i] != 0)
        {
            pos = i;
            while (pos != start && line[pos - step] == 0)
            {
                line[pos - step] = line[pos];
                line[pos] = 0;
                pos -= step;
            }
        }
    }

    return (1);
}