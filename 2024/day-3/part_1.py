import re


def main() -> None:
    pattern: str = r"mul\((\d+),(\d+)\)"
    answer: int = 0

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            finds = re.findall(pattern, line)

            for find in finds:
                x, y = map(int, find)
                answer += x * y

    print(answer)

    return None


if __name__ == "__main__":
    main()
