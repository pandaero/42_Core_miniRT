/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/12 18:48:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

// ================================= TYPE PROTOTYPES ===========================
typedef enum element		t_element;
typedef struct s_point		t_point;
typedef struct s_direction	t_direction;
typedef struct s_vector		t_vector;
typedef struct s_ray		t_ray;
typedef struct s_obj		t_obj;
typedef struct s_objlist	t_objlist;

// =================================== 3D ELEMENTS =============================
//Typedef defines different types of elements for a 3D scene.
typedef enum element
{
	EMPTY,
	POINT,
	DIRECTION,
	VECTOR,
	RAY
}	t_element;

//Typedef describes a point in 3D space.
typedef struct s_point
{
	double		x_co;
	double		y_co;
	double		z_co;
}				t_point;

//Typedef describes a direction in 3D space.
typedef struct s_direction
{
	double		x_comp;
	double		y_comp;
	double		z_comp;
}				t_direction;

//Typedef describes a vector and its properties in 3D space.
typedef struct s_vector
{
	double		mag;
	double		x_comp;
	double		y_comp;
	double		z_comp;
	t_direction	*dir;
	t_point		*start;
	t_point		*end;
}				t_vector;

//Typedef describes a ray in 3D space.
typedef struct s_ray
{
	t_point		*ray_orig;
	t_direction	*ray_dir;
}				t_ray;

// =============================== OBJECT LINKED LIST ==========================
//Typedef describes an object in a linked list.
typedef struct s_obj
{
	t_element	elem;
	t_point		*point;
	t_direction	*direction;
	t_vector	*vector;
	t_ray		*ray;
	t_obj		*prev;
	t_obj		*next;
}				t_obj;

//Typedef describes an object linked list.
typedef struct s_objlist
{
	int			list_id;
	int			num_objects;
	t_obj		*first;
	t_obj		*last;
	t_objlist	*prev;
	t_objlist	*next;
}				t_objlist;

//Typedef defines a struct for program data.
typedef struct s_program
{
	int			num_obj_lists;
	t_objlist	*first_objlist;
	t_objlist	*last_objlist;
}		t_program;

// ================================ OBJECT CREATION ============================
//Function creates and initialises a point.
t_point		*point_create(void);
//Function copies a defined point object's properties to a new one.
t_point		*point_copy(t_point *point);
//Function creates a new defined point object from coordinates.
t_point		*point_coords(double x_coord, double y_coord, double z_coord);
//Function creates and initialises a direction.
t_direction	*direction_create(void);
//Function copies a defined direction object's properties to a new one.
t_direction	*direction_copy(t_direction *direction);
//Function creates a defined direction object from two points.
t_direction	*direction_two_points(t_point *start, t_point *end);
//Function creates a defined direction object from a vector.
t_direction	*direction_vector(t_vector *vector);
//Function creates and initialises a vector.
t_vector	*vector_create(void);
//Function copies a defined vector object's properties to a new one.
t_vector	*vector_copy(t_vector *vector);
//Function creates a new defined vector object from two points.
t_vector	*vector_two_points(t_point *start, t_point *end);
//Function creates a new defined vector object from starting point, mag, dir.
t_vector	*vector_start_mag_dir(t_point *start, double mag, t_direction *dir);
//Function creates and initialises a ray.
t_ray		*ray_create(void);
//Function copies a defined ray object's properties to a new one.
t_ray		*ray_copy(t_ray *ray);
//Function creates a defined ray object from a starting point and direction.
t_ray		*ray_start_dir(t_point *origin, t_direction *dir);
//Function creates a defined ray object from a starting and directing point.
t_ray		*ray_two_points(t_point *start, t_point *end);
//Function creates a defined ray object from a vector.
t_ray		*ray_vector(t_vector *vector);
//Function creates and initialises an object.
t_obj		*object_create(void);
//Function copies an object's properties to a new one.
t_obj		*object_copy(t_obj *object);
//Function creates a point object.
t_obj		*object_point(t_point *point);
//Function creates a direction object.
t_obj		*object_direction(t_direction *direction);
//Function creates a direction object.
t_obj		*object_vector(t_vector *vector);
//Function creates a direction object.
t_obj		*object_ray(t_ray *ray);

// ================================ MEMORY FREEING =============================
//Function frees a pointer and returns NULL.
void		*free_null(void *ptr);
//Function frees all the allocations belonging to a point object.
void		free_point(t_point *point);
//Function frees all the allocations belonging to a direction object.
void		free_direction(t_direction *direction);
//Function frees all the allocations belonging to a vector object.
void		free_vector(t_vector *vector);
//Function frees all the allocations belonging to a ray object.
void		free_ray(t_ray *ray);
//Function frees the program struct.
void		free_program(t_program *program);
//Function frees all the object linked lists.
void		free_obj_lists(t_objlist *first);
//Function frees an entire object linked list.
void		free_list(t_objlist *list);
//Function frees an object.
void		free_object(t_obj *object);

// ================================== LINKED LISTS =============================
//Function creates a new program data structure.
t_program	*program_create(void);
//Function adds an object linked list to the program data structure.
void		program_add_obj_list(t_program *program, t_objlist *objlist);
//Function creates and initialises a new object linked list in the program.
t_objlist	*list_create(t_program *program);
//Function adds an object to a linked list.
void		list_add_object(t_objlist *list, t_obj *object);
//Function removes an object from a linked list, freeing its memory.
void		list_remove_object(t_objlist *list, t_obj *object);

// =================================== OPERATIONS ==============================
//Function works out the length/distance between two points.
double		distance_two_points(t_point *point_one, t_point *point_two);

// ================================= ERROR HANDLING ============================
//Function handles cleanly an error that requires the program to exit.
int			error_exit(t_program *program, char *str);
//Function prints an memory allocation error message.
void		error_malloc_print(char *str);

#endif
