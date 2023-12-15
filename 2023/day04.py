from aocd.models import Puzzle
from collections import defaultdict

YEAR = 2023
DAY = 4

puzzle = Puzzle(year=YEAR, day=DAY)


def a():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_a)
    puzzle.input_data
    total_points = 0
    input = puzzle.input_data
    for line in input.splitlines():
        game_points = 0
        game = line.split(":")[1]
        winning_cards = game.split("|")[0].split()
        my_cards = game.split("|")[1].split()

        for card in my_cards:
            if card in winning_cards:
                if game_points == 0:
                    game_points += 1
                else:
                    game_points *= 2
        total_points += game_points
        print(game_points, total_points)


def b():
    print(puzzle.examples[0].input_data)
    print(puzzle.examples[0].answer_b)

    puzzle.input_data
    total_cards = 0
    input = puzzle.input_data

    number_cards = len(input.splitlines())
    line_nbr = 0
    card_copies = [1] * number_cards
    for line in input.splitlines():
        game_points = 0
        game = line.split(":")[1]
        winning_cards = game.split("|")[0].split()
        my_cards = game.split("|")[1].split()

        for card in my_cards:
            if card in winning_cards:
                game_points += 1
        forward_search_stop = line_nbr + game_points + 1
        if forward_search_stop > number_cards:
            forward_search_stop = number_cards
        for forward_index in range(line_nbr + 1, line_nbr + game_points + 1):
            card_copies[forward_index] += 1 * card_copies[line_nbr]
        total_cards += card_copies[line_nbr]
        line_nbr += 1
        print(total_cards)


b()
