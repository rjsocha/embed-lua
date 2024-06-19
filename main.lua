local function printf(...) return io.stdout:write(string.format(...)) end

printf("ARRAY:\n")

for i = 0, #arg do
   printf("%d =>  %s\n", i, arg[i])
end

printf("PAIRS:\n")
for k,v in pairs(arg) do
  printf("%d => %s\n", k, v)
end
return(0)