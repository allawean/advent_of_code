import numpy as np
import click
from pathlib import Path

def count_calories_one_elf(snacks: np.array):
    pass

def open_file(input_file: Path) -> list[str]:
    with open(input_file) as f:
        return f.read().split('\n\n')

def split_snacks_per_elf(total_snacks_raw: list[str]) -> np.array:
    return [[eval(x) for x in elf.splitlines()] for elf in total_snacks_raw]

def get_sums_of_calories_per_elf(snacks_per_elf: list[list[int]]) -> list[int]:
    return [sum(x) for x in snacks_per_elf]

def sort_elves(total_snacks: list[int]) -> None:
    total_snacks.sort()


def get_snacks(input_file: Path):
    total_snacks_raw = open_file(input_file)
    return split_snacks_per_elf(total_snacks_raw)

def get_max_n_elves(sorted_total_snacks: list[int], number_of_elves: int) -> int:
    return sum(sorted_total_snacks[-number_of_elves:])



@click.command()
@click.option('--number-of-elves', default=3)
@click.argument('input_file', type=click.Path(exists=True))
def main(number_of_elves: int, input_file: Path):
    snacks_per_elf = get_snacks(input_file)
    calories_per_elf = get_sums_of_calories_per_elf(snacks_per_elf)
    print(f'Max total calories per elf are: {max(calories_per_elf)}')
    sort_elves(calories_per_elf)
    print(f'Max total calories of {number_of_elves} maximal elves are: {get_max_n_elves(calories_per_elf, number_of_elves)}')



if __name__ == '__main__':
    main(obj={})
