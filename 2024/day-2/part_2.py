def is_safe(arr: list[int]) -> bool:
    is_increasing = is_decreasing = True

    for _ in range(len(arr) - 1):
        diff: int = arr[_] - arr[_ + 1]

        if not diff or diff < -3 or diff > 3:
            return False

        if diff < 0:
            is_decreasing = False
        else:
            is_increasing = False

        if not is_increasing and not is_decreasing:
            return False

    return True


def apply_dampener(arr: list[int]) -> bool:
    for _ in range(len(arr)):
        if is_safe(arr[:_] + arr[_ + 1:]):
            return True

    return False


def main() -> None:
    safe_count: int = 0

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            array: list[int] = list(map(int, line.strip().split()))

            (is_safe(array) or apply_dampener(array)) and (safe_count := safe_count + 1)

    print(safe_count)

    return None


if __name__ == "__main__":
    main()
