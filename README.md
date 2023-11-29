# premutations
Вывод и подсчет всех перестановок без повторений

```
int main()
{
    std::list<int> input = {1, 2, 3};
    auto result = permutations_rec(input);
    PrintResult(result);
}
```
Вывод:
```
1: 123
2: 132
3: 213
4: 231
5: 312
6: 321
----
total: 6
```
