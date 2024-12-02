def main() -> None:
    list_1: list[int] = []
    list_2: list[int] = []

    with open("input", "r", encoding="UTF-8") as file:
        while (line := file.readline()):
            location_1, location_2 = map(int, line.split())

            list_1.append(location_1)
            list_2.append(location_2)
    
    list_1.sort()
    list_2.sort()

    distance: int = 0

    for _, value in enumerate(list_1):
        distance += abs(value - list_2[_])

    print(distance)

    return None


if __name__ == "__main__":
    main()
