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

def get_solution(snacks_per_elf: list[list]) -> int:
    return max([sum(x) for x in snacks_per_elf])


def get_snacks(input_file: Path):
    total_snacks_raw = open_file(input_file)
    return split_snacks_per_elf(total_snacks_raw)



@click.command()
@click.argument('input_file', type=click.Path(exists=True))
def main(input_file: Path):
    snacks_per_elf = get_snacks(input_file)
    print(f'Max total calories per elf are: {get_solution(snacks_per_elf)}')



if __name__ == '__main__':
    main(obj={})
