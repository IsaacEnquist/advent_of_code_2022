def compare_packets(left, right):
    idx = 0
    print(left, " ", right)
    while True:
        print(idx, "idx")
        if idx == len(left):
            return True
        if idx == len(right):
            print("f0")
            return False
        if type(left[idx]) is int and type(right[idx]) is int:
            if left[idx] > right[idx]:
                print("f1")
                return False
            elif left[idx] < right[idx]:
                return True
        elif type(left[idx]) is int:
            if compare_packets([left[idx]], right[idx]) is False:
                print("f2")
                return False
        elif type(right[idx]) is int:
            if compare_packets(left[idx], [right[idx]]) is False:
                print("f3")
                return False
        else:
            if compare_packets(left[idx], right[idx]) is False:
                print("f4")
                return False
        idx += 1

l1 = [[],[5,[[6]],7],[],[4]]
l2 = [[1,[[],10,[]],[]],[],[0,[[5,3],4,[],[4,7,8],2],[[1],[]]],[4],[10,8]]
print(compare_packets(l1, l2))


