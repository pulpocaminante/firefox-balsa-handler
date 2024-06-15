Firefox can't correctly pass a mailto link to Balsa, so I made this little handler that will do it. This is just a little project for an old retro system I made.

Compile with:
```
    gcc main.c -o main
```
And set it as the mailto handler in about:config. Make sure that `Balsa` is in your `$PATH`. 
