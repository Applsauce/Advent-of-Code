from aocd.models import Puzzle
from aocd import submit
import numpy as np

DAY = 2
YEAR = 2024

puzzle = Puzzle(day=DAY, year=YEAR)
print(puzzle.title)


def a():
    print("Starting part a")
    # print(f"Example data:")
    # print(puzzle.examples[0].input_data)
    # print("Example answer:")
    # print(puzzle.examples[0].answer_a)

    # Two column input data to np array
    # data = puzzle.examples[0].input_data
    data = puzzle.input_data
    # np_input = np.array(np_input)
    # print(np_input)

    safe = 0
    np_input = []
    for line in data.splitlines():
        row = np.array([int(x) for x in line.split()])
        print(row)
        # The levels are either all increasing or all decreasing.
        # Any two adjacent levels differ by at least one and at most three.

        # Check decreasing as the default
        decreasing = False
        increasing = False
        first_run = True
        row_safe = True
        if isinstance(row, int):
            safe = safe + 1
            print("\tRow Safe")
        else:
            prev_num = row[0]
            for index in range(1, row.size):
                diff = prev_num - row[index]

                if abs(diff) > 3 or abs(diff) < 1:
                    print("\tRow Unsafe")
                    row_safe = False
                    break  # Unsafe

                elif diff > 0 and first_run:
                    decreasing = True
                    first_run = False

                elif diff < 0 and first_run:
                    increasing = True
                    first_run = False

                elif diff < 0 and decreasing == True:
                    print("\tRow Unsafe")
                    row_safe = False
                    break  # Unsafe

                elif diff > 0 and increasing == True:
                    print("\tRow Unsafe")
                    row_safe = False
                    break  # Unsafe

                prev_num = row[index]
            if row_safe:
                safe = safe + 1
                print("\tRow Safe")

        # print(row)

    print(f"Safe: {safe}")
    # submit(my_answer)


def b():
    print("Starting part b")
    print(f"Example data:")
    print(puzzle.examples[0].input_data)
    print("Example answer:")
    print(puzzle.examples[0].answer_b)
    #data = puzzle.examples[0].input_data
    data = puzzle.input_data
    # np_input = np.array(np_input)
    # print(np_input)

    safe = 0
    for line in data.splitlines():
        row = np.array([int(x) for x in line.split()])
        print(row)
        # The levels are either all increasing or all decreasing.
        # Any two adjacent levels differ by at least one and at most three.
        # We may remove a single level per report
        decreasing = False
        increasing = False
        first_run = True
        row_safe = True
        remake_row = False
        orig_row = row
        bad_num_inx = 0
        changed_curr_index = False
        changed_prev_index = False
        changed_initial_index = False
        if isinstance(row, int):
            safe = safe + 1
            print("\tRow Safe")
        else:
            prev_num = row[0]
            index = 1
            while index < row.size and row_safe:
                diff = prev_num - row[index]

                if abs(diff) > 3 or abs(diff) < 1:
                    remake_row = True

                elif diff > 0 and first_run:
                    decreasing = True
                    first_run = False

                elif diff < 0 and first_run:
                    increasing = True
                    first_run = False

                elif diff < 0 and decreasing == True:
                    remake_row = True

                elif diff > 0 and increasing == True:
                    remake_row = True

                # Try and remove the offending value if we fail once - a second chance
                if remake_row:
                    # Remake the row
                    # How do we know if the current index is the problem, or the past index?

                    # Check every single one
                    if bad_num_inx < orig_row.size:
                        row = np.delete(orig_row, bad_num_inx)
                        bad_num_inx += 1
                        index = 1
                        prev_num = row[0]
                        first_run = True
                        remake_row = False
                        decreasing = False
                        increasing = False
                    else:
                        row_safe = False
                        break

                    # # Check both, I guess
                    # if changed_curr_index == False:
                    #     row = np.delete(orig_row, index)
                    #     changed_curr_index = True
                    # elif changed_curr_index == True and changed_prev_index == False:
                    #     row = np.delete(orig_row, index - 1)
                    #     changed_prev_index = True
                    # elif (
                    #     changed_curr_index == True
                    #     and changed_prev_index == True
                    #     and changed_initial_index == False
                    # ):
                    #     row = np.delete(orig_row, 0)
                    #     changed_initial_index = True
                    # else:
                    #     row_safe = False
                    #     break

                    # index = 1
                    # first_run = True
                    # prev_num = row[0]
                    # remake_row = False

                else:
                    prev_num = row[index]
                    index += 1

            if row_safe:
                safe = safe + 1
                print("\tRow Safe")
            else:
                print("\tRow Unsafe")

        # print(row)

    print(f"Safe: {safe}")


# a()
b()  # 317 too low, 323 too low, 336 bad, 332 bad.
