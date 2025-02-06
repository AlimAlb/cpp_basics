
int main() {
    int x = 42;
    const int cx = 13;

    int* ptr = &x;  // обычный указатель
    //ptr = &cx;  // ошибка компиляции

    const int* cptr = &x;  // OK: через *cptr нельзя будет изменить x
    cptr = &cx;  // OK

    int* const ptrc = &x;  // OK: *ptrc можно менять, но сам ptrc менять нельзя
    //ptrc = nullptr;  // ошибка компиляции

    const int* const cptrc = &x;  // OK, для &cx тоже бы сработало
}