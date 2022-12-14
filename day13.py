def compare_packets(left, right):
    idx = 0
    while True:
        if idx == len(left) and idx == len(right):
            return 
        if idx == len(left):
            return True
        if idx == len(right):
            return False
        if type(left[idx]) is int and type(right[idx]) is int:
            if left[idx] > right[idx]:
                return False
            elif left[idx] < right[idx]:
                return True
        elif type(left[idx]) is int:
            istrue = compare_packets([left[idx]], right[idx])
            if istrue is False:
                return False
            elif istrue is True:
                return True
        elif type(right[idx]) is int:
            istrue = compare_packets(left[idx], [right[idx]])
            if istrue is False:
                return False
            elif istrue is True:
                return True
        else:
            istrue = compare_packets(left[idx], right[idx])
            if istrue is False:
                return False
            elif istrue is True:
                return True
        idx += 1

input = open('day13.txt', 'r')
input = input.readlines()

list_of_strings = []
for i in range(len(input)-1):
    if i % 3 != 2:
        list_of_strings.append(input[i][:-1])

#print(len(list_of_strings))
list_of_packets = [eval(list_of_strings[i]) for i in range(len(list_of_strings))]
list_of_packets += [[[],[[4,[9,4,5,2,8],[3,9],2],6,10,2],[0,[]]]]




total = 0
tot = 0



for i in range(int(len(list_of_packets)/2)):
    if compare_packets(list_of_packets[2*i], list_of_packets[2*i+1]) is not False:
        total += i+1
        print(i+1)


print(total)
print(len(list_of_packets))


list_of_packets += [[[2]]]
list_of_packets += [[[6]]]



for i in range(len(list_of_packets)):
    for j in range(i, len(list_of_packets)):
        if compare_packets(list_of_packets[i], list_of_packets[j]) is False:
            temp = list_of_packets[i]
            list_of_packets[i] = list_of_packets[j]
            list_of_packets[j] = temp

print(list_of_packets)

print(len(list_of_packets))

p2 = 0
p6 = 0
for j in range(len(list_of_packets)):
    if list_of_packets[j] == [[2]]:
        p2 = j+1
    if list_of_packets[j] == [[6]]:
        p6 = j+1   

print(p2*p6) 