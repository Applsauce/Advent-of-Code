from aocd.models import Puzzle
import re

YEAR = 2023
DAY = 1

puzzle = Puzzle(year=YEAR, day=DAY)


# print(puzzle.examples[0].input_data)


def a():
    print(puzzle.input_data)
    sum_calib = 0
    for line in puzzle.input_data.splitlines():
        print(line)
        digits = re.findall("^.*?(\d).*(\d).*$|(\d)", line)[0]
        print(digits)
        if digits[2] != "":
            temp = digits[2] + digits[2]
            temp2 = int(temp)

            sum_calib += temp2
        else:
            temp = digits[0] + digits[1]
            temp2 = int(temp)
            sum_calib += temp2
        print(sum_calib)


def convert_int(s):
    if s == "one":
        return "1"
    if s == "two":
        return "2"
    if s == "three":
        return "3"
    if s == "four":
        return "4"
    if s == "five":
        return "5"
    if s == "six":
        return "6"
    if s == "seven":
        return "7"
    if s == "eight":
        return "8"
    if s == "nine":
        return "9"

    return s


def b():
#     ex = """two1nine
# eightwothree
# abcone2threexyz
# xtwone3four
# 4nineeightseven2
# zoneight234
# 7pqrstsixteen"""
    print(puzzle.input_data)
    sum_calib = 0
    for line in puzzle.input_data.splitlines():
        print(line)
        digits = re.findall(
            "^.*?(\d|one|two|three|four|five|six|seven|eight|nine).*(\d|one|two|three|four|five|six|seven|eight|nine).*$|(\d|one|two|three|four|five|six|seven|eight|nine)",
            line,
        )[0]
        print(digits)
        if digits[2] != "":
            temp = convert_int(digits[2]) + convert_int(digits[2])
            temp2 = int(temp)

            sum_calib += temp2
        else:
            temp = convert_int(digits[0]) + convert_int(digits[1])
            temp2 = int(temp)
            sum_calib += temp2
        print(sum_calib)


b()
