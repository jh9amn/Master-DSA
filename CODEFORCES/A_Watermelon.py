import sys
def solve(w):
    if w >= 2 and w % 2 ==0:
        return "YES"
    return "NO"

def main():
    input = sys.stdin.readline
    w = int(input().strip())
    print(solve(w))
    
if __name__ == "__main__":
    main()