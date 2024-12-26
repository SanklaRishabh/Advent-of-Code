def find_diagonals(grid: list[str], i: int, j: int, row_size: int, col_size: int) -> bool:
    if not (0 < i < row_size - 1 and 0 < j < col_size - 1):
        return False

    diagonal_1: str = f"{grid[i - 1][j - 1]}{grid[i + 1][j + 1]}"
    diagonal_2: str = f"{grid[i - 1][j + 1]}{grid[i + 1][j - 1]}"
    compare: list[str] = ["MS", "SM"]

    return diagonal_1 in compare and diagonal_2 in compare


def main() -> None:
    grid: list[str] = []
    answer: int = 0

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            grid.append(line)

    m, n = len(grid), len(grid[0])

    for i in range(m):
        for j in range(n):
            if grid[i][j] == "A":
                answer += find_diagonals(grid, i, j, m, n)

    print(answer)

    return None


if __name__ == "__main__":
    main()
