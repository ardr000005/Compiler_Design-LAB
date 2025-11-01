# ⚙️ Code Optimization in Compiler Design

This experiment demonstrates **Code Optimization** — one of the key phases of a compiler.  
It shows how the **GCC compiler** optimizes code at the assembly level to produce efficient, smaller, and faster programs.

---

## 🧩 Objective

To analyze the effect of compiler optimization options on generated assembly code and compare  
**optimized** vs **non-optimized** outputs.

---

## 🧠 Theory

Code Optimization is the process of improving intermediate or final code without changing its output or behavior.  
It aims to make code:
- Execute faster ⏩  
- Use less memory 💾  
- Consume fewer CPU cycles ⚙️  

### Common optimization techniques:
- Constant folding  
- Dead code elimination  
- Loop unrolling  
- Strength reduction  
- Inline expansion  
- Common subexpression elimination  

GCC provides several optimization levels using the `-O` flag:

| Flag | Meaning |
|------|----------|
| `-O0` | No optimization (default) |
| `-O1` | Basic optimizations |
| `-O2` | Moderate optimizations |
| `-O3` | High-level optimizations |
| `-Os` | Optimize for size |
| `-Ofast` | Aggressive optimizations (may break strict standards) |

---

## 🧪 Steps Performed

### 1️⃣ Create a simple C program (e.g., `sum.c`)

2️⃣ Generate Optimized and Non-Optimized Assembly Code
🔹 Optimized Code
```
gcc -S -O -o optimized.s sample.c
```
🔹 Non-Optimized Code
```
gcc -S -O0 -o non_optimized.s sample.c
```
   
-S → generates assembly code
-O → enables optimization
-O0 → disables optimization

3️⃣ Compare Line Counts of Assembly Files
```
wc -l optimized.s
```
```
wc -l non_optimized.s
```
The optimized version will generally have fewer lines, indicating more compact code.

The non-optimized version will have more lines due to redundant instructions and extra function calls.

4️⃣ (Optional) Generate Executable Files
```
gcc optimized.s -o optimized
gcc non_optimized.s -o non_optimized
```
You can then run:
```
./optimized
./non_optimized
```
Both outputs will be identical — but the optimized binary may be smaller and faster.

📊 Example Output

Type	Command	Lines in Assembly
Non-Optimized	wc -l non_optimized.s	150 lines
Optimized	wc -l optimized.s	95 lines

✅ Result: The optimized assembly file has fewer lines → code is simplified and efficient.
🧩 Conclusion

    Compiler optimizations significantly reduce the size of generated code.

    Optimized code executes faster and consumes fewer resources.

    GCC’s -O options allow developers to control optimization levels based on their needs.
