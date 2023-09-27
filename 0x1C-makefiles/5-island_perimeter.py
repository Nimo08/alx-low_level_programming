#!/usr/bin/python3
"""
Module contains the grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """
    rows = len(grid)
    cols = len(grid[0])
    res = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                res += 4
                if i > 0:
                    res -= grid[i-1][j] * 2
                if j > 0:
                    res -= grid[i][j-1] * 2
    return res
