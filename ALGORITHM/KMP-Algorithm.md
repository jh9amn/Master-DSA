```markdown
# Mastering the Knuth-Morris-Pratt (KMP) Algorithm

The **Knuth-Morris-Pratt (KMP)** algorithm is an elegant, highly optimized string-matching algorithm designed to solve a foundational computer science problem: **finding all occurrences of a `pattern` string inside a `text` string.**

While the naive string-matching approach can degrade to a sluggish $O(n \times m)$ time complexity, KMP guarantees a linear runtime of **$O(n + m)$**. It achieves this by enforcing a golden rule: **the algorithm never looks backward at characters in the `text` that it has already processed.** Instead, it analyzes the structure of the pattern itself to skip redundant checks.

---

## 1. The Core Intuition: Leveraging Mismatches

In a naive string search, whenever a character mismatch occurs, the pattern shifts forward by exactly one position, and the comparison restarts from scratch. This discards valuable structural context.

Consider searching for the pattern `dsgdsz` inside a text stream:

```text
Text:    d s g d s g d s g d s z
Pattern: d s g d s z
                     ▲
              Mismatch here!

```

A naive approach would shift the pattern forward by one space and re-evaluate starting at the second character (`s`).

KMP operates smarter. It notes that prior to the breakdown, we successfully matched the subsegment `dsgds`. Within this substring, the opening prefix `ds` is identical to the trailing suffix `ds`. Because we already know those characters match the text, KMP holds our position in the text stationary and shifts the pattern forward to instantly align the prefix `ds` with the text's trailing `ds`:

```text
Text:    d s g d s g d s g d s z
Pattern:       d s g d s z
                     ▲
             Resume check here!

```

---

## 2. The Engine: The LPS Array

To determine exactly how many shifts to skip during a mismatch, KMP precomputes an auxiliary lookup table known as the **LPS Array** (**L**ongest **P**refix which is also a **S**uffix), sometimes called the $\pi$ (Pi) table or failure function.

For any given substring slice `pattern[0...i]`, `LPS[i]` stores the length of the longest proper prefix that is also a valid suffix of that slice.

* **Proper Prefix:** A prefix that is not equal to the entire string itself.

### LPS Construction Trace

Let's analyze how the table is built step-by-step for the pattern `P = "ababaca"` by matching the pattern against itself:

1. **`"a"`** $\rightarrow$ No proper prefix/suffix available $\rightarrow$ **0**
2. **`"ab"`** $\rightarrow$ Prefixes: `["a"]` | Suffixes: `["b"]`. No overlap $\rightarrow$ **0**
3. **`"aba"`** $\rightarrow$ Prefixes: `["a", "ab"]` | Suffixes: `["a", "ba"]`. **`"a"`** matches $\rightarrow$ **1**
4. **`"abab"`** $\rightarrow$ Prefixes: `["a", "ab", "aba"]` | Suffixes: `["b", "ab", "bab"]`. **`"ab"`** matches $\rightarrow$ **2**
5. **`"ababa"`** $\rightarrow$ Longest matching prefix/suffix is **`"aba"`** $\rightarrow$ **3**
6. **`"ababac"`** $\rightarrow$ The character `'c'` breaks the pattern progression $\rightarrow$ **0**
7. **`"ababaca"`** $\rightarrow$ Ends with `'a'`, matching the absolute starting character **`"a"`** $\rightarrow$ **1**

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Pattern** | `a` | `b` | `a` | `b` | `a` | `c` | `a` |
| **LPS Value** | **0** | **0** | **1** | **2** | **3** | **0** | **1** |

---

## 3. C++ Implementation

Here is the complete production-ready C++ implementation. It is split into two distinct phases: creating the LPS table, and executing the main search loop.

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Phase 1: Precompute the Longest Prefix Suffix (LPS) array.
 * Time Complexity: O(m) where m is the length of the pattern.
 */
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Fall back to the previous longest prefix suffix window
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

/**
 * Phase 2: Perform the linear-time KMP string matching search.
 * Time Complexity: O(n) where n is the length of the text string.
 */
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    // Generate the failure lookup table
    vector<int> lps = computeLPSArray(pattern);
    
    int i = 0; // Scanning pointer for Text
    int j = 0; // Scanning pointer for Pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // Entire pattern successfully matched!
        if (j == m) {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1]; // Reset pointer to catch overlapping matches
        }
        // Mismatch scenario encountered
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                // Shift pattern based on precomputed prefix boundaries
                j = lps[j - 1];
            } else {
                // Base fallback: advance through the text
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    cout << "Searching text: \"" << text << "\"\n";
    cout << "Searching for:  \"" << pattern << "\"\n\n";
    
    KMPSearch(text, pattern);
    
    return 0;
}

```

---

## 4. Complexity & Evaluation Blueprint

When assessing whether to choose KMP for a problem, consider these performance profiles:

* **Time Complexity:** $\mathcal{O}(n + m)$. Precomputing the lookup table takes $\mathcal{O}(m)$ time, and the scanning window evaluates the text string exactly once in $\mathcal{O}(n)$ time.
* **Space Complexity:** $\mathcal{O}(m)$ extra space allocation to hold the structural pointers inside the `lps` array.
* **Structural Advantage:** KMP thrives when the search patterns possess high structural repetition (e.g., `ababab`, `aaaa`). If your search inputs lack repetitive internal prefixes, the `lps` array evaluates mostly to zeroes, causing the loop to drop back into standard linear step intervals.

```

```
