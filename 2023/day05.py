from aocd.models import Puzzle
from collections import defaultdict
import numpy as np

YEAR = 2023
DAY = 5

puzzle = Puzzle(year=YEAR, day=DAY)


def a():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_a)
    puzzle.input_data
    input = puzzle.examples[0].input_data
    seed_pos = []
    map_dicts = {}
    forward_skip = 0
    line_index = 0
    # Create maps
    for line in input.splitlines():
        if "seeds" in line:
            seed_pos = (line.split("seeds:")[1]).split()
            seed_pos = [int(x) for x in seed_pos]
            line_index += 1
            continue
        elif len(line.strip()) == 0:
            line_index += 1
            continue
        elif forward_skip > 0:
            line_index += 1
            forward_skip -= 1
            continue
        else:
            map_name = line.split()[0]

            # Search forward and send the entire array to the next function
            numerical_array = ""
            for forward_line_index in range(line_index + 1, len(input.splitlines())):
                if len(input.splitlines()[forward_line_index].strip()) == 0:
                    break
                else:
                    forward_skip += 1
                    numerical_array += input.splitlines()[forward_line_index] + "\n"

            map_dicts[map_name] = map_converter(numerical_array)

        line_index += 1

    # Search through the maps
    input_map = "seed"
    output_map = ""
    found_conversion = False
    keys = []
    while found_conversion == False:
        for key in map_dicts:
            # Format map1-to-map2
            if key.split("-")[0] == input_map:
                output_map = key.split("-")[2]

                keys.append(key)
                # Done searching
                if output_map == "location":
                    found_conversion = True
                    break
                else:
                    input_map = output_map
            else:
                continue

    # Select matching seed
    locations = []
    for seed in seed_pos:
        temp = seed
        for key in keys:
            temp = map_dicts[key][temp]
        locations.append(temp)
    # Return
    print(1)


def map_converter(arr):
    dest_array = []
    source_array = []
    for line in arr.split("\n"):
        if len(line.strip()) == 0:
            continue  # end of segment

        num_line = line.split()
        dest_start_range = int(num_line[0])
        source_start_range = int(num_line[1])
        range_length = int(num_line[2])

        dest_array_seg = list(range(dest_start_range, dest_start_range + range_length))
        source_array_seg = list(
            range(source_start_range, source_start_range + range_length)
        )
        # Try and fit in segment in existing arrays
        if source_array == []:
            dest_array = dest_array_seg
            source_array = source_array_seg
        # if the segment is larger
        elif source_array_seg[0] > source_array[len(source_array) - 1]:
            # https://sparkbyexamples.com/python/python-append-list-to-a-list/
            dest_array.extend(dest_array_seg)
            source_array.extend(source_array_seg)
        # if the segment is smaller
        elif source_array_seg[len(source_array_seg) - 1] < source_array[0]:
            dest_array_seg.extend(dest_array)
            dest_array = dest_array_seg
            source_array_seg.extend(source_array)
            source_array = source_array_seg
        # Should be the only options.....

    # Finally expanding the missing numbers down
    # Expand missing parts
    filled = False
    broke_diff = False
    start_index = 1
    while filled == False:
        for i in range(start_index, len(source_array)):
            diff = source_array[i] - source_array[i - 1]
            if diff > 1:
                # https://stackoverflow.com/questions/48561673/adding-items-in-the-middle-of-a-list-in-python
                source_array = (
                    source_array[:i]
                    + list(range(source_array[i - 1] + 1, source_array[i]))
                    + source_array[i:]
                )
                dest_array = (
                    dest_array[:i]
                    + list(range(source_array[i - 1] + 1, source_array[i]))
                    + dest_array[i:]
                )
                start_index = i + 1
                broke_diff = True
                break
            else:
                broke_diff = False
        if (broke_diff == False) or (
            broke_diff == True and (i == (len(source_array) - 1))
        ):
            filled = True

    # Expand down
    start = source_array[0]
    if start > 0:
        temp = list(range(0, start))
        temp.extend(source_array)
        source_array = temp
        temp = list(range(0, start))
        temp.extend(dest_array)
        dest_array = temp
    # https://stackoverflow.com/questions/209840/make-a-dictionary-dict-from-separate-lists-of-keys-and-values
    return dict(zip(source_array, dest_array))


def b():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_b)
    puzzle.input_data


a()
