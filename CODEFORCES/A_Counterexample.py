# import sys
# def hcf(a, b):
#     while b:
#         a, b = b, a % b
#     return a

# def find_counterexample(l, n):
#     if n - l <= 1:
#         return -1
    
#     for i in range(l, n+1):
#         for j in range(i+1, n+1):
#             if hcf(i,j) != 1:
#                 continue
#             for k in range(j+1, n+1):
#                 if hcf(j,k) != 1:
#                     continue
#                 if hcf(i,k) != 1:
#                     return f"{i} {j} {k}"
#     return -1           
     
  

# def main():
#     input = sys.stdin.read
#     data = input().strip().split()
#     l = int(data[0])
#     n = int(data[1])
    
#     print(find_counterexample(l, n))

# if __name__ == "__main__":
#     main()


import sys
def main():
    l, r = map(int, input().split())
    if r - l < 2:
        return -1
    for a in range(l, r-1):
        if a % 2 == 0:
            b = a + 1
            c = a + 2
            print(a, b, c)
            return 
        print(-1)
        
if __name__ == "__main__":
    main()        
        
        