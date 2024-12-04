from collections import Counter


def main() -> None:
    list_1: list[int] = []
    list_2: list[int] = []

    with open("input", "r", encoding="UTF-8") as file:
        while (line := file.readline()):
            location_1, location_2 = map(int, line.split())

            list_1.append(location_1)
            list_2.append(location_2)

    set_1: set[int] = set(list_1)
    frequency_2: Counter = Counter(list_2)
    score: int = 0

    for element in set_1:
        score += element * frequency_2[element]

    print(score)

    return None


if __name__ == "__main__":
    main()
