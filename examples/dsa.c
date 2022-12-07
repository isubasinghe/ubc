int simple(int a)
{
    a += 2;
    a = 4;
    a -= 5;
    return a;
}

int two_vars(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    return a + b;
}

int if_join(int cond)
{
    int a = 10;
    if (cond)
    {
        a += 1;
    }
    else
    {
        a -= 4;
    }
    return a;
}

int if_join_different_length(int cond)
{
    int a = 10;
    if (cond)
    {
        a += 1;
    }
    else
    {
        a -= 4;
        a *= 2;
    }
    return a;
}

int if_join_multiple_variables(int cond)
{
    int a = 10;
    int b = 20;
    if (cond)
    {
        a += 1;
        b -= 1;
    }
    else
    {
        a -= 4;
        a -= b + 4;
        a *= 2;
    }
    return a * b;
}

int if_join_multiple_variables_no_ret(int cond)
{
    int a = 10;
    int b = 20;
    if (cond)
    {
        a += 1;
        b -= 1;
    }
    else
    {
        a -= 4;
        a -= b + 4;
        a *= 2;
    }
    return 0;
}



int simple_for_loop(int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += i;
    }
    return s;
}

struct point { int x; int y; };

struct point origin();

struct point shift_diag(struct point p, int offset)
{
    if (offset == 0)
    {
        return origin();
    }
    p.x += offset;
    p.y += offset;
    return p;
}

int one_branch_undefined(int b)
{
    int a;
    if (b)
    {
        a = 2;
    }
    return a;
}

int one_branch_legal(int b)
{
    if (b)
    {
        int a = 2;
        (void) a;
    }
    return 0;
}

int uninit(int b)
{
    int a;
    if (b)
    {
        a = 2;
    }
    return a + 1;
}

int init(int b)
{
    int a = 0;
    if (b)
    {
        a = 2;
    }
    return a + 1;
}

int arr_undefined_behaviour(int i)
{
    int arr[8];
    arr[0] = 2;
    return arr[i];
}

int arr_undefined_behaviour2(int i, int j)
{
    int arr[8];
    if (j)
    {
        arr[0] = 2;
    }
    else
    {
        arr[1] = 3;
    }
    return arr[i];
}

// doesn't compile to graph lang
// int arr_loop_init(int j)
// {
//     int arr[8];
//     for (int i = 0; i < 8; i++)
//     {
//         arr[i] = 1;
//     }
//     return arr[j];
// }

int arr_static()
{
    int arr[8];
    arr[0] = 1;
    return arr[0];
}
