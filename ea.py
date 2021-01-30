def find_Novowels(words):
    novowelwords = []
    vowel = ['a', 'e', 'i', 'o', 'u']
    for word in words:
        novowel = True    

        for letter in word:
            if letter in vowel:
                novowel=False

        if novowel == True:
            novowelwords.append(word)
    return novowelwords

print(find_Novowels(['wqrty','swpty','spwrt']))