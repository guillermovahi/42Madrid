char	*parse_to_hex(unsigned int num)
{
	char			*res;
	unsigned int	aux;
	int				i;

	if (num == 0)
		return ("0");

	i = get_hex_length(num);
	res = (char *) malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return NULL;
	i = 0;
	while (num != 0)
	{
		aux = num % 16;
		if (aux < 10)
			aux += 48;
		else
			aux += 87;
		res[i++] = aux;
		num /= 16;
	}
	return invert_string(res, i);
}

int	put_hex(unsigned int num, int style)
{
	char	*str;
	int		size;

	size = 0;
	if (style == 2)
		size += put_str("0x");
	str = parse_to_hex(num);
	if (style == 1)
		to_upper(str);
	size += put_str(str);
	//free(str);
	return (size);
}