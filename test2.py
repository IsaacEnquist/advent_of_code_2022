import os
from functools import cmp_to_key

DPS = ["[[2]]", "[[6]]"]


def main():
    with open(os.path.dirname(__file__) + "/day13.txt") as f:
        lines = f.read().split("\n")

        print(get_in_order_scores(lines))

def get_in_order_scores(lines):
    total = 0
    left = ""

    print(cmp_lines('[[],[5,[[6]],7],[],[4]]' ,  '[[1,[[],10,[]],[]],[],[0,[[5,3],4,[],[4,7,8],2],[[1],[]]],[4],[10,8]]'))
    return int(total)


def cmp_lines(left, right):
    return cmp_packets(eval(left), eval(right))


def cmp_packets(left, right):
    print(left, right)
    for i, r in enumerate(right):
        if i >= len(left):
            return -1

        l = left[i]

        if is_list(l) or is_list(r):
            res = cmp_packets(as_list(l), as_list(r))

            if res != 0:
                return res
            else:
                continue

        if l == r:
            continue
        else:
            return -1 if r > l else 1

    if len(right) == len(left):
        return 0
    else:
        return -1 if len(right) > len(left) else 1


def as_list(val):
    return val if is_list(val) else [val]


def is_list(val):
    return type(val) == list


if __name__ == '__main__':
    main()