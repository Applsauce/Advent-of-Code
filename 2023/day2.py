from aocd.models import Puzzle
import re

YEAR = 2023
DAY = 2

puzzle = Puzzle(year=YEAR, day=DAY)


def a():
    # print(puzzle.examples[0].input_data)
    # print(puzzle.examples[0].answer_a)

    # 12 r, 13g, 14b
    red_max = 12
    green_max = 13
    blue_max = 14
    id_tot = 0
    for line in puzzle.input_data.splitlines():
        id = line.split(":")[0]
        id = int(re.search(r"\d+", id).group())

        game = line.split(":")[1]
        game = game.replace(";", ",")
        game = game.split(",")
        red_largest = 0
        green_largest = 0
        blue_largest = 0

        for gline in game:
            if "red" in gline:
                red = int(re.search(r"\d+", gline).group())
                if red > red_largest:
                    red_largest = red
            elif "green" in gline:
                green = int(re.search(r"\d+", gline).group())
                if green > green_largest:
                    green_largest = green
            elif "blue" in gline:
                blue = int(re.search(r"\d+", gline).group())
                if blue > blue_largest:
                    blue_largest = blue

        print(id, red_largest, green_largest, blue_largest)
        if (
            (red_largest <= red_max)
            and (green_largest <= green_max)
            and (blue_largest <= blue_max)
        ):
            id_tot += id
            print(id_tot)


# Minimum cubes present
def b():
    print(puzzle.examples[0].input_data)

    id_tot = 0
    for line in puzzle.input_data.splitlines():
        id = line.split(":")[0]
        id = int(re.search(r"\d+", id).group())

        game = line.split(":")[1]
        game = game.replace(";", ",")
        game = game.split(",")
        red_largest = 0
        green_largest = 0
        blue_largest = 0

        for gline in game:
            if "red" in gline:
                red = int(re.search(r"\d+", gline).group())
                if red > red_largest:
                    red_largest = red
            elif "green" in gline:
                green = int(re.search(r"\d+", gline).group())
                if green > green_largest:
                    green_largest = green
            elif "blue" in gline:
                blue = int(re.search(r"\d+", gline).group())
                if blue > blue_largest:
                    blue_largest = blue

        smallest_cube = red_largest * green_largest * blue_largest
        print(smallest_cube, red_largest, green_largest, blue_largest)
        id_tot += smallest_cube
        print(id_tot)


b()
