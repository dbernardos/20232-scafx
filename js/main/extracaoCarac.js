function extrair(lista_codigo, carac) {
  const dicionario = {}; // Objeto para armazenar contagens

  for (const cmd of carac) {
    let count = 0;

    for (const frase of lista_codigo) {
      if (cmd === "if") {
        if (frase.includes("if(") || frase.includes("if (")) {
          count += 1;
        }
      } else if (cmd === "for") {
        if (frase.includes("for(") || frase.includes("for (")) {
          count += 1;
        }
      } else if (cmd === "getchar") {
        if (frase.includes("getchar(") || frase.includes("getchar (")) {
          count += 1;
        } else if (cmd === "getche") {
          if (frase.includes("getche(") || frase.includes("getche (")) {
            count += 1;
          } else if (cmd === "getch") {
            if (frase.includes("getch(") || frase.includes("getch (")) {
              count += 1;
            } else if (cmd === "gets") {
              if (frase.includes("gets(") || frase.includes("gets (")) {
                count += 1;
              } else if (cmd === "fgets") {
                if (frase.includes("fgets(") || frase.includes("fgets (")) {
                  count += 1;
                } else if (cmd === "putchar") {
                  if (frase.includes("putchar(") || frase.includes("putchar (")) {
                    count += 1;
                  } else if (cmd === "puts") {
                    if (frase.includes("puts(") || frase.includes("puts (")) {
                      count += 1;
                    } else if (cmd === "else") {
                      if (frase.includes("else(") || frase.includes("else (")) {
                        count += 1;
                      } else if (cmd === "switch") {
                        if (frase.includes("switch(") || frase.includes("switch (")) {
                          count += 1;
                        } else if (cmd === "case") {
                          if (frase.includes("case(") || frase.includes("case (")) {
                            count += 1;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else if (frase.includes(cmd)) {
        count += 1;
      }
    }

    dicionario[cmd] = count;
  }

  return dicionario;
}

const lista_codigo = [
  "if (condition){",
  "}",
  "for (let i = 0; i< 5; i++){",
  "}",
  "while (true){",
  "}",
  "switch (x) {",
  "  case 1:",
  "    break;",
  "  case 2:",
  "    break;",
  "}",
  "else {",
  "}",
  "puts('Hello, world!');",
  "puts('Another line');",
  "getchar();",
  "getche();",
  "getch();",
  "gets();",
  "fgets();",
  "break;",
  "return;",
  "exit;",
  "do {",
  "} while (condition);",
  "strcpy(destination, source);",
  "strcmp(string1, string2);",
  "strncpy(destination, source, n);",
  "strlen(string);",
  "strupr(string);",
  "strlwr(string);",
  "strrev(string);",
  "tolower(character);",
  "toupper(character);",
  "isalpha(character);",
  "fopen(filename, mode);",
  "fclose(file);",
  "feof(file);",
  "remove(filename);",
  "fflush(file);",
  "sizeof(type);",
  "typedef struct { int x; } MyStruct;",
  "struct MyStruct { int x; };",
  "malloc(size);",
  "free(pointer);",
  "#include <stdio.h>",
  "system(command);",
  "default:",
  "int main(int argc, char *argv[]) {",
  "}",
];

const carac = [
  "if", "for", "while", "case", "else", "fgets", "getch", "getchar", "getche",
  "putchar", "puts", "switch", "gets", "break", "return", "exit", "do", "strcpy",
  "strcmp", "strncpy", "strlen", "strupr", "strlwr", "strrev", "tolower", "toupper",
  "isalpha", "fopen", "fclose", "feof", "remove", "fflush", "sizeof", "typedef",
  "struct", "malloc", "free", "#include", "system", "default", "main", "functions",
  "argc", "argv"
];

const resultado = extrair(lista_codigo, carac);
console.log(resultado);
