#pragma once

#include "queue.hpp"
#include "vector.hpp"

enum Cardinal { S, W, N, E };
enum Cell { EMPTY = 0, WALL = 1 };

/**
 * generates an X by Y boolean grid.
 * This would've been unnecessary if I could
 * use `std::array` which has a size known at
 * compile time so I wouldn't have to declare stuff
 * on the heap for no reason.
 */
bool **generateVisited(int, int);

using Maze       = Vector<Vector<Cell>>;
/**
 * A pair representing an X,Y coordinate
 *
 * not an `unsigned int` in order to allow having
 * a sentinel value that represents no coordinates
 */
using Coordinate = std::pair<int, int>;

/**
 * A 2D grid of coordinates that point to the next
 * coordinate to get to the solution
 */
using Traceback  = Vector<Vector<Coordinate>>;

constexpr Coordinate sentinel{ -1, -1 };

void print(const Vector<Vector<Coordinate>>&,
           const Coordinate&,
           const Coordinate&);

Vector<Coordinate> neighbors(const Maze&, const Coordinate&);

Traceback explore(const Maze&, const Coordinate&, const Coordinate&);

bool isBlockValid(const Maze&, const Coordinate&);

/**
 * The direction that must be taken to get from one coordinate to another
 * Assumes coordinates are adjacent
 * @return
 */
Cardinal pathTo(const Coordinate&, const Coordinate&);

Vector<Coordinate> shortestPath(const Traceback&, const Coordinate&, const Coordinate&);

/**
 * Can the ball stop given its path to the end location
 * @return
 */
bool canStop(const Maze &maze, Vector<Coordinate> &steps, const Coordinate &end);
