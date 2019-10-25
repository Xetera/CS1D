#include "maze.hpp"
#include <iostream>

bool isBlockValid(const Maze &maze, const Coordinate &coords) {
  try {
    return maze.at(coords.first).at(coords.second) != Cell::WALL;
  } catch (const std::out_of_range &) {
    return false;
  }
}

Cardinal pathTo(const Coordinate &from, const Coordinate &to) {
  if (from.first == to.first && from.second + 1 == to.second) {
    return Cardinal::E;
  }
  if (from.first == to.first && from.second - 1 == to.second) {
    return Cardinal::W;
  }
  if (from.second == to.second && from.first - 1 == to.first) {
    return Cardinal::N;
  }
  if (from.second == to.second && from.first + 1 == to.first) {
    return Cardinal::S;
  }
  throw std::runtime_error("non-adjacent blocks");
}

void print(const Vector<Vector<Coordinate>> &trail, const Coordinate &init, const Coordinate &end) {
  for (size_t i = 0; i < trail.size; ++i) {
    for (size_t j = 0; j < trail.at(i).size; ++j) {
      const Coordinate c = trail.at(i).at(j);
      if (i == init.first && j == init.second) {
        std::cout << " ★ ";
      } else if (c == sentinel) {
        std::cout << " ▒ ";
      } else if (i == end.first && j == end.second) {
        std::cout << " ⚫ ";
      } else {
        const Cardinal path = pathTo({i, j}, c);
        switch (path) {
          case Cardinal::N:
            std::cout << " ↑ ";
            break;
          case Cardinal::S:
            std::cout << " ↓ ";
            break;
          case Cardinal::W:
            std::cout << " ← ";
            break;
          case Cardinal::E:
            std::cout << " → ";
            break;
        }
      }
    }
    std::cout << "\n";
  }
}

bool canStop(const Maze &maze, Vector<Coordinate> &steps, const Coordinate &end) {
  const auto[x, y] = end;
  // we want the second to last element as the last element is always the final coordinate itself
  Coordinate first = steps.at(steps.size - 2);
  const Cardinal direction = pathTo(end, first);
  if (direction == Cardinal::E && isBlockValid(maze, {x, y - 1})) {
    return false;
  } else if (direction == Cardinal::W && isBlockValid(maze, {x, y + 1})) {
    return false;
  } else if (direction == Cardinal::S && isBlockValid(maze, {x - 1, y})) {
    return false;
  } else if (direction == Cardinal::N && isBlockValid(maze, {x + 1, y})) {
    return false;
  }
  return true;
}

Vector<Coordinate> neighbors(const Maze &maze, const Coordinate &coords) {
  const auto[x, y] = coords;
  const Vector<Coordinate> checks{
    std::make_pair(x + 1, y),
    std::make_pair(x, y - 1),
    std::make_pair(x - 1, y),
    std::make_pair(x, y + 1),
  };
  return checks.filter([maze](const Coordinate &coordinate) {
    return isBlockValid(maze, coordinate);
  });
}

bool **generateVisited(int maxWidth, int maxHeight) {
  bool **visited = new bool *[maxWidth];
  for (size_t i = 0; i < maxWidth; ++i) {
    visited[i] = new bool[maxHeight];
    for (size_t j = 0; j < maxHeight; ++j) {
      visited[i][j] = false;
    }
  }
  return visited;
}

Vector<Coordinate> shortestPath(const Traceback &directions, const Coordinate &start, const Coordinate &end) {
  Coordinate next = directions.at(end.first).at(end.second);
  Vector<Coordinate> out{end};
  while (next != sentinel) {
    const auto[x, y] = next;
    out.push_back({x, y});
    next = directions.at(x).at(y);
  }
  return out;
}

Traceback explore(const Maze &maze,
                  const Coordinate &start,
                  const Coordinate &end) {
  Queue<Coordinate> toExplore{start};
  const size_t maxWidth = maze.size;
  const size_t maxHeight = maze.at(0).size;
  bool **visited = generateVisited(maxWidth, maxHeight);
  // empty trail to leave "breadcrumbs" in
  Traceback trail(maxWidth, Vector<Coordinate>(maxHeight, sentinel));

  while (!toExplore.empty()) {
    const Coordinate current = toExplore.dequeue();
    const Vector<Coordinate> cells = neighbors(maze, current);
    for (const Coordinate &cell : cells) {
      const auto[x, y] = cell;
      if (!visited[x][y]) {
        toExplore.enqueue(cell);
        visited[x][y] = true;
        const bool isFirstBlock = x == start.first && y == start.second;
        if (!isFirstBlock) {
          trail[x][y] = current;
        }
      }
    }
  }

  for (size_t i = 0; i < maxWidth; ++i) {
    delete[] visited[i];
  }
  delete[] visited;

  return trail;
}

int main() {
  Maze maze{
    Vector<Cell>{Cell::EMPTY, Cell::EMPTY, Cell::WALL,  Cell::EMPTY, Cell::EMPTY},
    Vector<Cell>{Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY},
    Vector<Cell>{Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::WALL,  Cell::EMPTY},
    Vector<Cell>{Cell::WALL,  Cell::WALL,  Cell::EMPTY, Cell::WALL,  Cell::WALL },
    Vector<Cell>{Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY},
  };
  Coordinate start{0, 4};
  Coordinate end{4, 4 };
  const Traceback traceback = explore(maze, start, end);
  print(traceback, start, end);
  Vector<Coordinate> solution = shortestPath(traceback, start, end);
  // the solution is reached from the end goal to the start, so we have to reverse it in place
  solution.reverse();
  const bool stopping = canStop(maze, solution, end);

  std::cout << "Solution:\n";
  for (const Coordinate &coord : solution) {
    std::cout << "(" << coord.first << ", " << coord.second << ")\n";
  }
  std::cout << "Once the ball has reached the goal it" << (stopping ? " CAN " : " CANNOT ") << "stop";
  return 0;
}