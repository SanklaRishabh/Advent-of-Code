import re


def main() -> None:
    answer: int = 0
    enabled: bool = True
    pattern: str = r"mul\((\d+),(\d+)\)|(do\(\))|(don't\(\))"

    with open("input", "r", encoding="UTF-8") as file:
        for line in file:
            finds = re.findall(pattern, line)

            for x, y, start, stop in finds:
                if start or stop:
                    enabled = bool(start)
                elif enabled:
                    answer += int(x) * int(y)

    print(answer)

    return None


if __name__ == "__main__":
    main()
