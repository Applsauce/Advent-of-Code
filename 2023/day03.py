from aocd.models import Puzzle
from collections import defaultdict

YEAR = 2023
DAY = 3

puzzle = Puzzle(year=YEAR, day=DAY)


def a():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_a)

    input = puzzle.input_data
    # Need to determine whenever the 8 neighbourhood of any digit touches a symbol except '.'
    height = len(input.splitlines())
    length = len(input.splitlines()[0])

    sum_valid = 0
    for row in range(0, height):
        prev_digits = ""
        col = 0
        inrange = col < length
        while inrange:
            curr_symb = input.splitlines()[row][col]

            # Skip forward these amount of digits
            forward_skip = 0
            valid_number = False
            if curr_symb.isdigit():
                # Keep track of the potential number using previous digits

                # Check 4 neighbourhood
                for y in [-1, 0, 1]:
                    for x in [-1, 0, 1]:
                        if valid_number == False:
                            # Dont check ourselves
                            if y == x and x == 0:
                                continue
                            new_y = row + y
                            new_x = col + x

                            # Skip if we are outside bounds
                            if (
                                new_x < 0
                                or new_y < 0
                                or new_x >= length
                                or new_y >= height
                            ):
                                continue

                            new_symb = input.splitlines()[new_y][new_x]

                            # Found a valid symbol
                            if (new_symb != ".") and (not new_symb.isdigit()):
                                valid_number = True

                                # Check forward to find the rest of the number
                                next_part_is_digit = True
                                search_col = col
                                curr_symb = prev_digits + curr_symb
                                while next_part_is_digit:
                                    search_col += 1
                                    if search_col < length:
                                        if input.splitlines()[row][
                                            search_col
                                        ].isdigit():
                                            next_part_is_digit = True
                                            curr_symb += input.splitlines()[row][
                                                search_col
                                            ]
                                            forward_skip += 1
                                        else:
                                            next_part_is_digit = False
                                    else:
                                        next_part_is_digit = False
                if valid_number == False:
                    prev_digits += curr_symb
            else:
                prev_digits = ""

                col += 1
                inrange = col < length
                continue
            if valid_number:
                sum_valid += int(curr_symb)
                col += forward_skip
                print(sum_valid, int(curr_symb))
            valid_number = False
            col += 1
            inrange = col < length


def b():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_b)

    input = puzzle.input_data

    # Need to determine whenever the 8 neighbourhood of any digit touches a * and which other number touches the same *
    height = len(input.splitlines())
    length = len(input.splitlines()[0])

    # on format, ("rowcol"), number
    touching_gears = defaultdict(list)

    for row in range(0, height):
        prev_digits = ""
        col = 0
        inrange = col < length
        while inrange:
            curr_symb = input.splitlines()[row][col]

            gear_pos = ""
            # Skip forward these amount of digits
            forward_skip = 0
            valid_number = False
            if curr_symb.isdigit():
                # Keep track of the potential number using previous digits

                # Check 4 neighbourhood
                for y in [-1, 0, 1]:
                    for x in [-1, 0, 1]:
                        if valid_number == False:
                            # Dont check ourselves
                            if y == x and x == 0:
                                continue
                            new_y = row + y
                            new_x = col + x

                            # Skip if we are outside bounds
                            if (
                                new_x < 0
                                or new_y < 0
                                or new_x >= length
                                or new_y >= height
                            ):
                                continue

                            new_symb = input.splitlines()[new_y][new_x]

                            # Found a valid symbol
                            if new_symb == "*":
                                valid_number = True

                                gear_pos = f"{new_y}{new_x}"

                                # Check forward to find the rest of the number
                                next_part_is_digit = True
                                search_col = col
                                curr_symb = prev_digits + curr_symb
                                while next_part_is_digit:
                                    search_col += 1
                                    if search_col < length:
                                        if input.splitlines()[row][
                                            search_col
                                        ].isdigit():
                                            next_part_is_digit = True
                                            curr_symb += input.splitlines()[row][
                                                search_col
                                            ]
                                            forward_skip += 1
                                        else:
                                            next_part_is_digit = False
                                    else:
                                        next_part_is_digit = False
                if valid_number == False:
                    prev_digits += curr_symb
            else:
                prev_digits = ""

                col += 1
                inrange = col < length
                continue
            if valid_number:
                col += forward_skip
                touching_gears[gear_pos].append(int(curr_symb))
                print(gear_pos, int(curr_symb))
            valid_number = False
            col += 1
            inrange = col < length

    sum = 0
    for key in touching_gears:
        mul_sum = 0
        if ( 1<len(touching_gears[key])):
            mul_sum = 1
            for mult in touching_gears[key]:
                mul_sum =mul_sum* mult
        sum += mul_sum
    print(sum)
b()
