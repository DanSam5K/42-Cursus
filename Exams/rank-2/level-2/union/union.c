int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int seen[256] = {0};
        int i = 0;
        int j = 0;

        while (argv[1][i])
        {
            if (!seen[argv[1][i]])
            {
                write(1, argv[1][i], 1);
                seen[argv[1][i]] = 1;
            }
            i++;
        }
        while (argv[2][i])
        {
            if (!seen[argv[2][i]])
            {
                write(1, argv[1][i], 1);
                seen[argv[2][j]] = 1;
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}