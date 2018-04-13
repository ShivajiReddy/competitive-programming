from collections import Counter

def isValid(s):
    cnt = Counter(s)
    if len(set(cnt.values())) == 1:
        return "1"
    elif len(set(cnt.values())) > 2:
        return "0"
    else:
        m1 = max(cnt.values())
        m2 = min(cnt.values())
        if cnt.values().count(m2) == 1:
            return "1"
        if cnt.values().count(m1) > 1 or m1 - m2 > 1:
            return "0"
        return "1"

s = raw_input().strip()
result = isValid(s)
print(result)