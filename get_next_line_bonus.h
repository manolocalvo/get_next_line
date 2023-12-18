/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:04:12 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/14 13:40:20 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/**
 * @brief función para liberar y retornar null cuando hay algún problema.
 * Le pasamos el char* a liberar, le quita la memoria asignada y anula su 
 * contenido, devolviendo NULL
 * 
 * @param str char* a liberar
 * @return void* retorna NULL y se para el programa
 */
void	*ft_free(char *str);
/**
 * @brief función que lee el fd y lo almacena en storage por medio
 * de una variable char* buffer.
 * Lee fd con la función read y lo va almacenando en buffer 
 * read (fd, buffer, BUFFER_SIZE)
 * si la lectura es correcta, lo concatena a storage
 * strjoin (storage, buffer)
 * libera todo y retorna el nuevo storage
 * 
 * @param fd file descriptor del fichero abierto
 * @param storage variable estática donde voy almacenando todo lo 
 * leído hasta que haya un salto de línea
 * @return char* storage con el buffer concatenado
 */
char	*read_buffer_join(int fd, char *storage);
/**
 * @brief recibe storage con un salto de línea.
 * con substr(storage, start = 0, len) saca la línea desde el principio 
 * hasta el salto, incluyéndolo
 * 
 * @param storage variable estática con la línea completa, incluyendo el 
 * salto y quizá parte de la siguiente línea
 * @return char* devuelve el substring incluyendo el salto
 */
char	*pull_new_line(char *storage);
/**
 * @brief recibe storage con el salto de línea incluído. 
 * con substr(storage, start = ptr, len) saca la línea desde después del 
 * salto hasta el final y lo guarda en una temporal char*.
 * Entonces libera storage y devuelve este substrin, que en la función 
 * principal sustituirá al antiguo storage
 * 
 * @param storage el storage con el salto incluído
 * @return char* La siguiente línea
 */
char	*storage_cleaner(char *storage);
/**
 * @brief función que recibe un fd y va leyendo y guardando en una variable 
 * estática hasta que se encuentra una nueva línea, momento en que la devuelve
 * y repite el proceso hasta el final del docuento. 
 * 
 * @param fd archivo que se genera al abrir otro, al cual se accedo por 
 * medio de éste
 * @return char* siguiente línea, incluyendo el salto si no ha llegado al 
 * final del  * archivo
 */
char	*get_next_line(int fd);
/**
 * @brief función para calcular la longitud de un string
 * 
 * @param str string a medir
 * @return size_t tamaño del string
 */
size_t	ft_strlen(char *str);
/**
 * @brief función que busca en un string la primera aparición de un char en 
 * concreto que recibe como argumento en forma de int
 * 
 * @param str string en el que buscar
 * @param c char que buscar, que le llega como int
 * @return char* posición del char en el string, en caso de encontrarlo
 */
char	*ft_strchr(char *str, int c);
/**
 * @brief función que concatena dos strings
 * 
 * @param s1 string original al que concatenar el otro. En nuestro caso 
 * será la variable estática
 * @param s2 string que pegar al final del original.
 * @return char* string resultante de la concatenación, nullterminated
 */
char	*ft_strjoin(char *s1, char *s2);
/**
 * @brief función que extrae de un string una parte determinada, 
 * comenzando en el byte start y durante len bytes
 * 
 * @param str string que recortar
 * @param start byte desde el que cortar
 * @param len bytes a cortar
 * @return char* substring resultante, nullterminated
 */
char	*ft_substr(char *str, size_t start, size_t len);

#endif