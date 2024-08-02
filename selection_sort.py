inputt=list(input("Enter the elements you want to sort: ").split())
for i in range (len(inputt)):
    min=i
    for j in range (i+1,len(inputt)):
        if inputt[j]<inputt[min]:
            min=j
        inputt[i],inputt[min]=inputt[min],inputt[i]
for i in range (len(inputt)):
    print(inputt[i])
        

