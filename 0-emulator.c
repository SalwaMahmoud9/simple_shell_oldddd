#include "shell.h"

/**
 * _exitFunc - exitFunc
 * @passInfo: info_Pass
 * Return: int
 */
int _exitFunc(info_Pass *passInfo)
{
	int exitVar;

	if (passInfo->arg_V[1])
	{
		exitVar = _atoierror(passInfo->arg_V[1]);
		if (exitVar == -1)
		{
			passInfo->sta_S = 2;
			p_err(passInfo, "error number: ");
			_put(passInfo->arg_V[1]);
			_putC('\n');
			return (1);
		}
		passInfo->error_N = _atoierror(passInfo->arg_V[1]);
		return (-2);
	}
	passInfo->error_N = -1;
	return (-2);
}

/**
 * _helpFunc - helpFunc
 * @passInfo: info_Pass
 * Return: int
 */
int _helpFunc(info_Pass *passInfo)
{
	char **var_arr;

	var_arr = passInfo->arg_V;
	_puts("help \n");
	if (0)
		_puts(*var_arr);
	return (0);
}

/**
 * _historyFunc - _historyFunc
 * @passInfo: info_Pass
 * Return: int
 */
int _historyFunc(info_Pass *passInfo)
{
	p_list(passInfo->his_T);
	return (0);
}
