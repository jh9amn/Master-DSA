## https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM

def getInversions(arr, n):
    # write your code here !!
    def merge(left, mid, right):
        ans = 0
        n1 = (mid- left + 1)
        n2 = (right - mid)

        arr1 = []
        arr2 = []
        for i in range(n1):
            arr1.append(arr[left + i])
        for j in range(n2):
            arr2.append(arr[mid + 1 + j])

        i,j = 0, 0
        k = left
        
        while(i < n1 and j < n2):
            if (arr1[i] <= arr2[j]):
                arr[k] = arr1[i]
                i += 1
                k += 1
            else:
                arr[k] = arr2[j]
                ans += (n1 - i) 
                j += 1
                k += 1

        while(j < n2):
            arr[k] = arr2[j]
            j += 1
            k += 1
        while(i < n1):
            arr[k] = arr1[i]
            i += 1
            k += 1

        return ans

    def mergeSort(left, right):
        if(right <= left):
            return 0
        mid = left + (right - left) // 2

        cnt_invertion = 0
        cnt_invertion += mergeSort(left, mid)
        cnt_invertion += mergeSort(mid+1, right)

        cnt_invertion += merge(left, mid, right)
        return cnt_invertion

    return mergeSort(0, n-1)


