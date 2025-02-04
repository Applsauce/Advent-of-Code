from aocd.models import Puzzle
from aocd import submit
import numpy as np
import re

DAY = 1
YEAR = 2024

puzzle = Puzzle(day = DAY, year = YEAR)
print(puzzle.title)

def a():
    print("Starting part a")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_a)
    #data = puzzle.input_data


def b():
    print("Starting part b")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_b)


a()
b()