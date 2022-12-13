def compare_packets(left, right):
    #print(left, " ", right)
    #print(len(left), " ", len(right))
    #print(type(right))
    r_idx = 0
    moves = 0
    for i in range(len(left)):
        if r_idx == len(right):
            return False
        elif type(left[i]) is int and type(right[r_idx]) is int:
            if left[i] > right[r_idx]:
                return False
            elif left[i] < right[r_idx]:
                r_idx -= 1
                moves += 1
        elif type(left[i]) is int:
            left[i] = [left[i]]
            if compare_packets(left[i], right[r_idx]) is False:
                return False
        elif type(right[r_idx]) is int:
            right[r_idx] = [right[r_idx]]
            if compare_packets(left[i], right[r_idx]) is False:
                return False
        else:
            if compare_packets(left[i], right[r_idx]) is False:
                return False
        r_idx += 1
    if len(left) - moves > len(right):
        return False
    return True


input = open('day13.txt', 'r')
input = input.readlines()

list_of_strings = []
for i in range(len(input)-1):
    if i % 3 != 2:
        list_of_strings.append(input[i][:-1])


list_of_packets = [eval(list_of_strings[i]) for i in range(len(list_of_strings))]
list_of_packets += [[[],[[4,[9,4,5,2,8],[3,9],2],6,10,2],[0,[]]]]


total = 0

for i in range(int(len(list_of_packets)/2)):
    #print(list_of_packets[2*i], " ", list_of_packets[2*i+1])
    #print(compare_packets(list_of_packets[2*i], list_of_packets[2*i+1]))
    if compare_packets(list_of_packets[2*i], list_of_packets[2*i+1]):
        total += i+1

print(total)
