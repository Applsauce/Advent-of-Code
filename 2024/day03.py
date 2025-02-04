from aocd.models import Puzzle
from aocd import submit
import numpy as np
import re

DAY = 3
YEAR = 2024

puzzle = Puzzle(day=DAY, year=YEAR)
print(puzzle.title)


def a():
    print("Starting part a")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    # print(puzzle.examples[0].answer_a)
    data = puzzle.examples[0].input_data
    data = puzzle.input_data

    matches = re.findall(r"mul\((\d+),(\d+)\)", data)

    print(matches)

    sum = 0
    for mul in matches:
        sum += int(mul[0]) * int(mul[1])
        print(f"{sum} = {mul[0]} * {mul[1]}")


def b():
    print("Starting part b")
    print(f"Example data:")
    example_data_b = (
        "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))"
    )
    # print(example_data_b)

    # data = example_data_b
    data = puzzle.input_data

    mul_values = re.findall(r"mul\((\d+),(\d+)\)", data)
    mul_start = [m.start(0) for m in re.finditer(r"mul\((\d+),(\d+)\)", data)]

    mul_dict = dict(zip(mul_start, mul_values))

    do_start = [m.start(0) for m in re.finditer(r"do\(\)", data)]
    do_dict = dict(zip(do_start, ["do"] * len(do_start)))

    dont_start = [m.start(0) for m in re.finditer(r"don't\(.*?\)", data)]
    dont_dict = dict(zip(dont_start, ["dont"] * len(dont_start)))

    instructions = list()
    instructions = mul_start + do_start + dont_start
    instructions.sort()

    instructions_dict = mul_dict | do_dict | dont_dict

    bool_do = True
    sum = 0
    for index in instructions:
        cmd = instructions_dict[index]
        if cmd == "do":
            bool_do = True
        elif cmd == "dont":
            bool_do = False
        else:
            if bool_do:
                mul = cmd
                sum += int(mul[0]) * int(mul[1])
                print(f"{sum} = {mul[0]} * {mul[1]}")


# a()
b()
