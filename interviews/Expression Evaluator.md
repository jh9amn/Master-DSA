# Expression Evaluator — Interview Revision Notes

## 1. Problem Statement

Design an **Expression Evaluator** that takes a mathematical expression containing:

- `+`
- `-`
- `*`
- `/`
- Parentheses `(` and `)`
- Multi-digit integers
- Spaces
- Unary `+` and `-`

and returns the integer result while respecting standard operator precedence.

### Example

```text
-7 + 5 * 8 - 5 / 4 + (5 + 4)
```

Using integer division:

```text
-7 + 40 - 1 + 9 = 41
```

Answer:

```text
41
```

---

# 2. What Makes This Problem Important?

This problem tests several concepts together:

1. Parsing a string
2. Operator precedence
3. Parentheses
4. Recursion
5. Unary operators
6. Multi-digit numbers
7. Whitespace handling
8. Edge cases
9. Clean API/design thinking

The key idea is:

> **Don't evaluate everything at the same level. Divide the grammar into precedence levels.**

---

# 3. Operator Precedence

Standard precedence is:

```text
Highest
   |
   | Parentheses
   |
   | Unary + / -
   |
   | * /
   |
   | + -
   |
Lowest
```

For example:

```text
2 + 3 * 4
```

should be:

```text
2 + (3 * 4)
= 14
```

not:

```text
(2 + 3) * 4
= 20
```

---

# 4. Core Idea — Recursive Descent Parser

We divide the expression into three levels:

```text
expression
    |
    +-- handles + and -

term
    |
    +-- handles * and /

factor
    |
    +-- number
    +-- parentheses
    +-- unary + / -
```

The grammar is:

```text
expression → term (+/- term)*

term       → factor (*// factor)*

factor     → number
           | '(' expression ')'
           | unary factor
```

This grammar automatically gives us operator precedence.

---

# 5. Why This Works

Suppose we have:

```text
2 + 3 * 4
```

`parseExpression()` asks `parseTerm()` for the first term.

First term:

```text
2
```

Then it sees `+`.

The next term is:

```text
3 * 4
```

`parseTerm()` handles `3 * 4` completely before returning.

Therefore:

```text
2 + 12
= 14
```

---

# 6. Parser Responsibilities

## parseExpression()

Handles:

```text
+
-
```

Conceptually:

```text
result = parseTerm()

while next operator is + or -:
    parse another term
    apply operator
```

---

## parseTerm()

Handles:

```text
*
/
```

Conceptually:

```text
result = parseFactor()

while next operator is * or /:
    parse another factor
    apply operator
```

---

## parseFactor()

Handles the highest-level atomic values:

```text
number
(parenthesized expression)
unary + / -
```

Examples:

```text
123
(2 + 3)
-7
+8
-(4 + 5)
```

---

# 7. C++ Implementation

```cpp
class Solution {
public:
    string s;
    int i = 0;

    void skipSpaces() {
        while (i < s.size() && s[i] == ' ')
            i++;
    }

    long long parseExpression() {
        long long result = parseTerm();

        while (true) {
            skipSpaces();

            if (i >= s.size() || s[i] == ')')
                break;

            char op = s[i++];

            long long next = parseTerm();

            if (op == '+')
                result += next;
            else
                result -= next;
        }

        return result;
    }

    long long parseTerm() {
        long long result = parseFactor();

        while (true) {
            skipSpaces();

            if (i >= s.size() ||
                s[i] == ')' ||
                s[i] == '+' ||
                s[i] == '-')
                break;

            char op = s[i++];

            long long next = parseFactor();

            if (op == '*')
                result *= next;
            else
                result /= next;
        }

        return result;
    }

    long long parseFactor() {
        skipSpaces();

        // Unary + or -
        if (s[i] == '+' || s[i] == '-') {
            char op = s[i++];

            long long value = parseFactor();

            if (op == '-')
                return -value;

            return value;
        }

        // Parentheses
        if (s[i] == '(') {
            i++; // skip '('

            long long result = parseExpression();

            skipSpaces();

            i++; // skip ')'

            return result;
        }

        // Multi-digit number
        long long num = 0;

        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num;
    }

    long long evaluate(string expression) {
        s = expression;
        i = 0;

        return parseExpression();
    }
};
```

---

# 8. Dry Run

Expression:

```text
-7 + 5 * 8 - 5 / 4 + (5 + 4)
```

Start:

```text
parseExpression()
```

### First term

```text
-7
```

Unary `-` is detected.

```text
-7
```

Then:

```text
+
```

Next term:

```text
5 * 8
```

`parseTerm()` evaluates:

```text
5 * 8 = 40
```

Current result:

```text
-7 + 40 = 33
```

Next:

```text
- 5 / 4
```

`parseTerm()` evaluates:

```text
5 / 4 = 1
```

Current result:

```text
33 - 1 = 32
```

Next:

```text
+ (5 + 4)
```

Parentheses cause a recursive call:

```text
parseExpression()
```

Inside:

```text
5 + 4 = 9
```

Final:

```text
32 + 9 = 41
```

---

# 9. Unary Operators

Unary operators are different from binary operators.

### Binary minus

```text
7 - 3
```

Means:

```text
7 minus 3
```

### Unary minus

```text
-7
```

Means:

```text
negative 7
```

Our parser handles unary operators inside `parseFactor()`:

```cpp
if (s[i] == '+' || s[i] == '-') {
    char op = s[i++];

    long long value = parseFactor();

    if (op == '-')
        return -value;

    return value;
}
```

Because `parseFactor()` calls itself, expressions such as these work:

```text
-7
+7
--7
+-7
-(-7)
-(2 + 3)
```

---

# 10. Multi-Digit Numbers

For:

```text
12345
```

we cannot process only one character.

Use:

```cpp
long long num = 0;

while (i < s.size() && isdigit(s[i])) {
    num = num * 10 + (s[i] - '0');
    i++;
}
```

Example:

```text
1
12
123
1234
12345
```

The final value is:

```text
12345
```

---

# 11. Spaces

Spaces can appear anywhere:

```text
2 + 3
```

```text
2+3
```

```text
2   +   3
```

We handle them using:

```cpp
void skipSpaces() {
    while (i < s.size() && s[i] == ' ')
        i++;
}
```

Call it before reading an operator or factor.

---

# 12. Parentheses

For:

```text
2 * (3 + 4)
```

when `parseFactor()` encounters:

```text
(
```

it does:

```cpp
i++;

long long result = parseExpression();

i++;
```

The recursive call evaluates:

```text
3 + 4
```

and returns:

```text
7
```

Then:

```text
2 * 7
= 14
```

---

# 13. Nested Parentheses

The same recursion handles:

```text
2 * (3 + (4 * (5 - 2)))
```

Evaluation:

```text
5 - 2 = 3

4 * 3 = 12

3 + 12 = 15

2 * 15 = 30
```

Answer:

```text
30
```

No special nested-parentheses logic is required.

---

# 14. Important Edge Cases

Always think about these during an interview.

### Single number

```text
123
```

Answer:

```text
123
```

### Leading unary minus

```text
-123
```

Answer:

```text
-123
```

### Spaces

```text
  10 + 20
```

Answer:

```text
30
```

### Multiplication precedence

```text
2 + 3 * 4
```

Answer:

```text
14
```

### Division precedence

```text
20 - 8 / 4
```

Answer:

```text
18
```

### Parentheses

```text
(2 + 3) * 4
```

Answer:

```text
20
```

### Nested parentheses

```text
((2 + 3) * (4 + 1))
```

Answer:

```text
25
```

### Negative number after operator

```text
2 * -5
```

Answer:

```text
-10
```

### Negative parentheses

```text
-(5 + 3)
```

Answer:

```text
-8
```

### Multiple unary operators

```text
--5
```

Answer:

```text
5
```

---

# 15. Division Behavior

If the problem says the result must be an integer, clarify what division means.

In C++:

```cpp
5 / 2
```

gives:

```text
2
```

and:

```cpp
-5 / 2
```

gives:

```text
-2
```

because C++ integer division truncates toward zero.

If the interviewer expects mathematical floor division instead, the implementation needs to change.

---

# 16. Division by Zero

Expression:

```text
10 / 0
```

is invalid.

Depending on the problem specification, you should either:

- throw an exception,
- return an error,
- or state that division by zero is not allowed.

For a coding interview, explicitly mentioning this edge case is good.

---

# 17. Why Use `long long`?

Even if the input numbers are `int`, intermediate results may become larger.

For example:

```text
100000 * 100000
```

Using:

```cpp
long long
```

is safer than:

```cpp
int
```

assuming the problem's constraints allow `long long`.

---

# 18. Complexity

Let `N` be the length of the expression.

### Time

```text
O(N)
```

Each character is processed approximately once.

### Space

```text
O(D)
```

where `D` is the maximum nesting depth of parentheses/unary expressions.

For example:

```text
((((((1))))))
```

has depth:

```text
6
```

---

# 19. Common Mistakes

## Mistake 1 — Evaluate strictly left to right

Wrong:

```text
2 + 3 * 4
```

Doing:

```text
2 + 3 = 5
5 * 4 = 20
```

Correct:

```text
2 + (3 * 4)
= 14
```

---

## Mistake 2 — Treat `-` only as binary

This fails:

```text
-5
```

and:

```text
2 * -5
```

You need to recognize unary `-`.

---

## Mistake 3 — Ignore parentheses

This fails:

```text
(2 + 3) * 4
```

Parentheses require recursive parsing.

---

## Mistake 4 — Read only one digit

This would incorrectly parse:

```text
123
```

as:

```text
1
```

then:

```text
2
```

then:

```text
3
```

Use a loop to construct the entire number.

---

## Mistake 5 — Use `stoi()` on every number

You can, but manual parsing is usually cleaner for an evaluator because you already maintain an index into the expression.

---

# 20. Alternative Approach — Stack

Another common solution is a stack-based evaluator.

The basic idea:

```text
numbers + operators
```

Use precedence rules:

```text
* / → calculate immediately
+ - → wait for lower precedence
(   → push onto stack
)   → evaluate until '('
```

This approach is useful when the interviewer specifically asks for an iterative solution.

However, for this problem with unary operators and nested parentheses, **recursive descent is generally easier to reason about and explain**.

---

# 21. Recursive Descent vs Stack

| Feature | Recursive Descent | Stack |
|---|---|---|
| Operator precedence | Very clean | Manual handling |
| Parentheses | Natural recursion | Stack |
| Unary operators | Easy | More complicated |
| Code readability | High | Medium |
| Iterative | No | Yes |
| Interview explanation | Excellent | Good |

For this particular problem:

> **Prefer recursive descent unless the interviewer asks for an iterative/stack-based solution.**

---

# 22. Interview Explanation

A concise explanation you can give:

> "I'll use recursive descent parsing. I'll divide the grammar into expression, term, and factor. Expression handles `+` and `-`, term handles `*` and `/`, and factor handles numbers, parentheses, and unary operators. Since expression calls term and term calls factor, multiplication and division are evaluated before addition and subtraction. Parentheses recursively call expression, which naturally handles nesting."

This is a strong explanation because it directly addresses:

```text
Parsing
Precedence
Parentheses
Unary operators
```

---

# 23. Mental Model

Remember:

```text
Expression
    ↓
   +/- 
    ↓
   Term
    ↓
   * /
    ↓
  Factor
    ↓
 number / (...) / unary
```

Or simply:

```text
+ -
 ↓
* /
 ↓
unary / ()
 ↓
number
```

When you see a new expression evaluator problem, think:

```text
"Build the grammar according to precedence."
```

---

# 24. Quick Revision Template

Before coding, write:

```text
expression → term (+/- term)*

term → factor (*// factor)*

factor → number
       | '(' expression ')'
       | (+/-) factor
```

Then implement:

```text
parseExpression()
    ↓
parseTerm()
    ↓
parseFactor()
```

And maintain:

```cpp
string s;
int i;
```

---

# 25. Final Checklist

Before submitting, verify:

- [ ] Multi-digit numbers work
- [ ] Spaces work
- [ ] `+` works
- [ ] `-` works
- [ ] `*` works
- [ ] `/` works
- [ ] Unary `+` works
- [ ] Unary `-` works
- [ ] Parentheses work
- [ ] Nested parentheses work
- [ ] Operator precedence works
- [ ] Division behavior is understood
- [ ] Division by zero is handled according to the specification
- [ ] Integer overflow constraints are considered
- [ ] Time complexity is `O(N)`

---

# 26. Practice Expressions

Use these for revision:

```text
1 + 2 * 3
```

Expected:

```text
7
```

```text
(1 + 2) * 3
```

Expected:

```text
9
```

```text
-7 + 5 * 8 - 5 / 4 + (5 + 4)
```

Expected:

```text
41
```

```text
2 * -5 + 10
```

Expected:

```text
0
```

```text
-(5 + 3) * 2
```

Expected:

```text
-16
```

```text
2 * (3 + (4 * (5 - 2)))
```

Expected:

```text
30
```

```text
--5 + -(-3)
```

Expected:

```text
8
```

---

# 27. One-Line Takeaway

> **Expression evaluator = Recursive Descent + Grammar based on Operator Precedence + Recursive Parentheses Handling.**
