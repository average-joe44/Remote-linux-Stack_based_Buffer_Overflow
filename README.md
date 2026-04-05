# REMOTE-LINUX STACK BOF
This is a remote exploit for linux 64-bit.  
This exploit is basically a local exploit with different offset and shellcode with socket connection.  
I'm not going to say pretty much here because it's literally the same with the local one.

# ABOUT
This exploit is exploiting a vulnerable program from C that i made with making a char buffer that was originally 64 byte is read as 512 byte.  
When the program received a byte from socket connection it will instantly write to the buffer, after that it will send back whether it's sigtrap or a sigsegv.  
Running the exploit at the client
```
python exploit.py <target-ip>
```
with netcat
```
nc -lnvp <your-port>
```


but firstly compile it
```
gcc -std=gnu89 -Wno-implicit-function-declaration -o vuln vuln_program.c -w -no-pie -fno-stack-protector -z execstack
```
```
chmod +x vuln
```
then run
```
./vuln
```
