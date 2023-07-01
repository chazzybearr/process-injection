
# Process Injection

This projects demonstrates process injection using the Win32 API. Process injection is a malicious technique used to insert code into the memory of a running process. By inserting a malicious payload, one can potential gain unauthorized access to a system.

## Motivation

The motivation behind this project was to gain an understanding of the underlying mechanisms and vulnerabilities of processes.

Additionally, one can explore the Win32 API, a crucial step towards windows application development.

This project serves as a practical demonstration and a solid template for helping others grasp the concept of process injection.
## Takeaways


During the development of this project, we encountered several important lessons and insights:

1. **Process security**: Process injection techniques showcase the challenges faced by modern operating systems in isolating processes and maintaining security. Understanding these vulnerabilities can help in building more robust and secure applications and operating systems.

2. **APIs**: Working with the Win32 API requires a *very* thorough understanding of its documentation and functions. This project provided me an opportunity to explore the API functions related to handling processes and memory management within a process.


3. **Memory management and code execution**: Process injection involves manipulating the memory of a target process and executing the injected code. I learned about memory allocation, and code execution techniques.

4. **Security implications**: Process injection is a technique used by malware developers. By building this project, I gained insight into the  risks associated with process injection and potential methods to detect and prevent these attacks.

## Usage

Download the binary from [releases](#releases)

Run the command in command prompt
```bash
> injection.exe [PID]
```

## Releases
[v1.0](https://github.com/chazzybearr/process-injection/releases/tag/v1.0)
## License

[MIT](https://choosealicense.com/licenses/mit/)
