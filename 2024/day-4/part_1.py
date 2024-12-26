STRING: str = "XMAS"


def find_string(grid: list[str], i: int, j: int, row_size: int, col_size: int) -> int:
    found: int = 0

    for dx in range(-1, 2):
        for dy in range(-1, 2):
            valid: bool = True

            for k, char in enumerate(STRING):
                row: int = i + dx * k
                col: int = j + dy * k

                if (
                    row < 0
                    or row >= row_size
                    or col < 0
                    or col >= col_size
                    or grid[row][col] != char
                ):
                    valid = False

            found += valid

    return found


def main() -> None:
    grid: list[str] = []
    answer: int = 0

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            grid.append(line.strip("\n"))

    m, n = len(grid), len(grid[0])

    for i in range(m):
        for j in range(n):
            if grid[i][j] == "X":
                answer += find_string(grid, i, j, m, n)

    print(answer)

    return None


if __name__ == "__main__":
    main()
