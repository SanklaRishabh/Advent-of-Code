def main() -> None:
    safe_count: int = 0

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            array: list[int] = list(map(int, line.strip().split()))

            is_increasing: bool
            is_decreasing: bool
            is_valid: bool

            is_increasing = is_decreasing = is_valid = True

            for _ in range(len(array) - 1):
                diff = array[_] - array[_ + 1]

                if not diff or diff < -3 or diff > 3:
                    is_valid = False

                    break

                if diff < 0:
                    is_decreasing = False
                elif diff > 0:
                    is_increasing = False

                if not is_decreasing and not is_increasing:
                    is_valid = False

                    break

            if is_valid:
                safe_count += 1

    print(safe_count)


if __name__ == "__main__":
    main()
