# CMake - cvičení

1. Vytvořte CMake projekt pro sestavení spustitelného souboru math.exe ze zdrojového souboru main.c.
2. Sestavte program pomocí MinGW
   - vygenerujte Makefile pomocí CMake GUI
   - sestavte pomocí mingw32-make
3. Sestavte program pomocí Visual Studia
   - vygenerujte VS projekt pomocí CMake GUI
   - sestavte projekt v IDE
4. Sestavte statickou knihovnu my-math ze souborů my-math.c a my-math.h
5. Přilinkujte knihovnu k math.exe
6. Pomocí CMake zařidťe využití vlastní matematické knihovny namísto systémové
7. Podmiňte sestavení a použití vlastní knihovny uživatelským přepínačem
8. Rozčleňte projekt do více souborů

---

## Bonusové úkoly:
9.  Sestavte dynamickou knihovnu namísto statické a předveďte funkčnost sestaveného programu
10. Vytvořte balíček obsahující knihovnu a použijte jej v jiném projektu
    - pomocí proměnných
    - vytvořením importovaného cíle
