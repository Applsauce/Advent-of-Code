from aocd.models import Puzzle
from aocd import submit

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
    
    #submit(my_answer)


def b():
    print("Starting part b")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_b)
    #submit(my_answer)


a()
b()