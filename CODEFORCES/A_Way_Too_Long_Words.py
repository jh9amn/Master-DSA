import sys
def solve(word):
    n = len(word)
    if n > 10:
        return word[0] + str(n-2) + word[n-1]
    return word

def main():
    n = int(input().strip())
    
    while(n > 0):
        word = input().strip()
        print(solve(word))
        n -= 1
    
if __name__ == "__main__":
    main()