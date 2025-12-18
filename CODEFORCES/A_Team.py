import sys
def main():
    ans = 0
    input = sys.stdin.readline
    n = int(input().strip())
    
    while(n > 0):
        line = input().split()
        a = int(line[0])
        b = int(line[1])
        c = int(line[2])
        
        if a + b + c >= 2:
            ans += 1
        n -= 1
    print(ans)
        
if __name__ == "__main__":
    main()