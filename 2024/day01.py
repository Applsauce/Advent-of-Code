from aocd.models import Puzzle
from aocd import submit
import numpy as np

DAY = 1
YEAR = 2024

puzzle = Puzzle(day=DAY, year=YEAR)
print(puzzle.title)


# Maybe the lists are only off by a small amount!
# To find out, pair up the numbers and measure how far apart they are.
# Pair up the !smallest number! in the !left! list with the !smallest! number
# in the !right! list, then the second-smallest left number with
# the second-smallest right number, and so on.
#
# Within each pair, figure out how far apart the
# two numbers are; you'll need to add up all of those distances.
# For example, if you pair up a 3 from the left list with a 7
# from the right list, the distance apart is 4;
# if you pair up a 9 with a 3, the distance apart is 6.
def a():
    print("Starting part a")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_a)

    # Two column input data to np array
    # data = puzzle.examples[0].input_data
    data = puzzle.input_data
    np_input = []
    for line in data.splitlines():
        np_input.append([int(x) for x in line.split()])
    np_input = np.array(np_input)
    print(np_input)

    # Seperate into 2 arrays
    col0 = np_input[:, 0]
    col1 = np_input[:, 1]

    total_diff = 0
    small0 = 0
    small1 = 0

    while min(col0.size, col1.size) > 0:

        # Find smallest two number in each column
        small0 = col0.min()
        small1 = col1.min()
        print(f"Small0 {small0}, small1 {small1}")

        # Difference
        diff = np.abs(small1 - small0)
        print(f"Diff {diff}")

        # Sum it up
        total_diff = total_diff + diff

        print(f"Total diff: {total_diff}")

        # Delete old values
        index = np.argwhere(col0 == small0)[0]
        col0 = np.delete(col0, index)

        index = np.argwhere(col1 == small1)[0]
        print(index)
        col1 = np.delete(col1, index)

        print(min(col0.size, col1.size))

    # submit(total_diff)


# This time, you'll need to figure out exactly how often
# each number from the left list appears in the right list.
# Calculate a total similarity score by adding up each number
# in the left list after multiplying it by the number of times
# that number appears in the right list.
def b():
    print("Starting part b")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_b)

    # Two column input data to np array
    #data = puzzle.examples[0].input_data
    data = puzzle.input_data
    np_input = []
    for line in data.splitlines():
        np_input.append([int(x) for x in line.split()])
    np_input = np.array(np_input)
    print(np_input)

    # Seperate into 2 arrays
    col0 = np_input[:, 0]
    col1 = np_input[:, 1]

    total_similarity = 0
    numleft = 0
    nbr_numleft = 0

    while col0.size > 0:

        # Get left list values
        numleft = int(col0[0])

        # Find all matching values in right list
        nbr_numleft = np.argwhere(col1 == numleft).size

        # update similarity
        similarity = numleft * nbr_numleft

        total_similarity = total_similarity + similarity
        print(total_similarity)
        # Delete old value
        col0 = np.delete(col0, 0)

    # submit(my_answer)


# a()
b()
