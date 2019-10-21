#pragma once

#include <variant>
#include "queue.hpp"
#include "vector.hpp"

enum Cardinal { S, W, N, E };
enum Cell { EMPTY = 0, WALL = 1 };

using Maze       = Vector<Vector<Cell>>;
using Coordinate = std::pair<int, int>;
using Traceback  = Vector<Vector<Coordinate>>;

constexpr Coordinate sentinel{ -1, -1 };

void print(const Vector<Vector<Coordinate>>&,
           const Coordinate&,
           const Coordinate&);

Vector<Coordinate> neighbors(const Maze&, const Coordinate&);

Traceback explore(const Maze&, const Coordinate&, const Coordinate&);

bool isBlockValid(const Maze&, const Coordinate&);

Cardinal pathTo(const Coordinate&, const Coordinate&);

Vector<Coordinate> shortestPath(const Traceback&, const Coordinate&, const Coordinate&);

/**
 * Can the ball stop given its path to the end location
 * @return
 */
bool canStop(const Maze &maze, Vector<Coordinate> &steps, const Coordinate &end);
