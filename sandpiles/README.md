# Sandpiles Sum

## Description

The task involves simulating the behavior of sandpiles. When sand grains are added to cells in a grid, cells that exceed a certain threshold (3 grains) will "topple" and distribute grains to their neighboring cells. This distribution continues until no cell in the grid exceeds the threshold, leading the grid to a stable state.

This project provides functionality to compute the sum of two sandpiles and stabilize the resulting sandpile.

## How to Use

    Include the header file sandpiles.h.
    Use the sandpiles_sum function to compute the sum of two 3x3 sandpile grids.
    The function will print intermediate states of the sandpile during stabilization.