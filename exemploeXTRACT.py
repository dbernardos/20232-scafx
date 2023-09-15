def aux_Text_Based_Count(ls_codigo, commands):
    dict_text = {}
    for cmd in commands:
        count = 0
        for frase in ls_codigo:
            if cmd == "if":
                if "if(" in frase or "if (" in frase:
                    count+=1
            elif cmd == "for":
                if "for(" in frase or "for (" in frase:
                    count+=1
            elif cmd in frase:
                count+=1
        dict_text.update({cmd: count})
    return dict_text
    