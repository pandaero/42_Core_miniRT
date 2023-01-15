/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 20:15:53 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
// # include "./intersections.h"
# if defined (__APPLE__)
#  include "../minilibx_opengl_20191021/mlx.h"
# endif
# if defined (__linux__)
#  include "../minilibx-linux/mlx.h"
# endif

# include <stdbool.h>

// Screen resolution
// # define WIN_WIDTH 800
// # define WIN_HEIGHT 600
// Factor for screen-pixel coordinate sizing. 
# define VIEW_SCALING 0.5
# define SPHERE_CENTER_X 0
# define SPHERE_CENTER_Y 50
# define SPHERE_CENTER_Z 0
# define SPHERE_RADIUS 10

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
	RAY,
	CAMERA,
	SCREEN
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
	double		x_comp;
	double		y_comp;
	double		z_comp;
	double		mag;
	t_direction	*dir;
}				t_vector;

typedef struct s_Vector3
{
	double	x;
	double	y;
	double	z;
}			t_Vector3;

//Typedef describes a ray in 3D space.
typedef struct s_ray
{
	t_point		*ray_orig;
	t_direction	*ray_dir;
}				t_ray;

//state shows if the ray intesects with the object or not
typedef struct s_intersect
{
    bool    state;
    t_point    *point;
}            t_intersect;

// ================================= 3D COMPOSITES =============================
//Typedef describes points required to define the pixels composing a screen.
typedef struct s_scr_pts
{
	t_point	*centre;
	t_point	*top_centre;
	t_point	*tl_corner;
	t_point	*first_px;
	t_point	***px_coords;
}			t_scr_pts;

//Typedef describes vectors required to define a screen.
typedef struct s_scr_vec
{
	t_direction	*normal;
	t_direction	*screen_up;
	t_direction	*screen_right;
	t_vector	*vec_up;
	t_vector	*vec_down;
	t_vector	*vec_left;
	t_vector	*vec_right;
	t_vector	*vec_corner_up;
	t_vector	*vec_corner_left;
	t_vector	*vec_screen_rd;
	t_vector	*vec_screen_rd_0th;
}				t_scr_vec;

//Typedef describes a pixel screen.
typedef struct s_screen
{
	int			width;
	int			height;
	t_scr_vec	*vecs;
	t_scr_pts	*pts;
}			t_screen;

// ================================= SCENE ELEMENTS ============================
//Typedef describes ambient lighting.
//Typedef describes the camera.
typedef struct s_camera
{
	double		horiz_fov;
	t_point		*location;
	t_direction	*view_dir;
}			t_camera;
//Typedef describes a spot light.

// =============================== OBJECT LINKED LIST ==========================
//Typedef describes an object in a linked list.
typedef struct s_obj
{
	t_element	elem;
	t_point		*point;
	t_direction	*direction;
	t_vector	*vector;
	t_ray		*ray;
	t_camera	*camera;
	t_screen	*screen;
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
//Function creates a point resulting from a vector and a starting point.
t_point		*point_point_vector(t_point *start, t_vector *vector);
//Function creates and initialises a direction.
t_direction	*direction_create(void);
//Function copies a defined direction object's properties to a new one.
t_direction	*direction_copy(t_direction *direction);
//Function creates a defined direction from components.
t_direction	*direction_components(double x_comp, double y_comp, double z_comp);
//Function creates a defined direction object from two points.
t_direction	*direction_two_points(t_point *start, t_point *end);
//Function creates a defined direction object from a vector.
t_direction	*direction_vector(t_vector *vector);
//Function creates and initialises a vector.
t_vector	*vector_create(void);
//Function copies a defined vector object's properties to a new one.
t_vector	*vector_copy(t_vector *vector);
//Function creates a new defined vector from a scalar and a direction.
t_vector	*vector_scale_direction(double scalar, t_direction *dir);
//Function creates a new defined vector object from two points.
t_vector	*vector_two_points(t_point *start, t_point *end);
//Function creates a new defined vector object from magnitude and direction.
t_vector	*vector_mag_dir(double mag, t_direction *dir);
//Function creates and initialises a ray.
t_ray		*ray_create(void);
//Function copies a defined ray object's properties to a new one.
t_ray		*ray_copy(t_ray *ray);
//Function creates a defined ray object from a starting point and direction.
t_ray		*ray_start_dir(t_point *origin, t_direction *dir);
//Function creates a defined ray object from a starting and directing point.
t_ray		*ray_two_points(t_point *start, t_point *end);
//Function creates a defined ray object from a vector.
t_ray		*ray_start_vector(t_point *start, t_vector *vector);
// -------------------------------- SCENE OBJECTS ------------------------------
//Function creates and initialises a camera.
t_camera	*camera_create(void);
//Function creates a camera from input parameters.
t_camera	*camera_input(t_point *loc, t_direction *view_dir, double hfov_deg);
//Function creates and initialises a screen points structure.
t_scr_pts	*screen_pts_create(void);
//Function creates and initialises a screen vectors structure.
t_scr_vec	*screen_vecs_create(void);
//Function creates and initialises a screen.
t_screen	*screen_create(void);
//Function defines a screen based on a camera element.
t_screen	*screen_camera(int width, int height, t_camera *camera);

// -------------------------------- GENERIC OBJECT -----------------------------
//Function creates and initialises an object.
t_obj		*object_create(void);
//Function copies an object's properties to a new one.
t_obj		*object_copy(t_obj *object);
//Function creates a point object.
t_obj		*object_point(t_point *point);
//Function creates a direction object.
t_obj		*object_direction(t_direction *direction);
//Function creates a vector object.
t_obj		*object_vector(t_vector *vector);
//Function creates a ray object.
t_obj		*object_ray(t_ray *ray);
//Function creates a camera object.
t_obj		*object_camera(t_camera *camera);
//Function creates a screen object.
t_obj		*object_screen(t_screen *screen);

// ================================ MEMORY FREEING =============================
//Function frees a pointer and returns NULL.
void		*free_void_null(void *ptr);
//Function frees all the allocations belonging to a point object.
void		free_point(t_point *point);
//Function frees all the allocations belonging to a point object, returns NULL.
void		*free_point_null(t_point *point);
//Function frees all the allocations belonging to a direction object.
void		free_direction(t_direction *direction);
//Function frees all the allocations in a direction object, returns NULL.
void		*free_direction_null(t_direction *direction);
//Function frees all the allocations belonging to a vector object.
void		free_vector(t_vector *vector);
//Function frees all the allocations belonging to a vector object, returns null.
void		*free_vector_null(t_vector *vector);
//Function frees all the allocations belonging to a ray object.
void		free_ray(t_ray *ray);
//Function frees all the allocations belonging to a ray object, returns null.
void		*free_ray_null(t_ray *ray);
//Function frees all the allocations belonging to a camera.
void		free_camera(t_camera *camera);
//Function frees a screen.
void		free_screen(t_screen *screen);
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
//Function converts degrees to radians.
double		radians_degrees(double deg);
//Function works out the length/distance between two points.
double		distance_two_points(t_point *point_one, t_point *point_two);
//Function works out the magnitude of a vector from its components.
double		magnitude_components(double x_comp, double y_comp, double z_comp);
//Function works out the vector cross product of two directions.
t_direction	*direction_cross(t_direction *first, t_direction *second);
//Function returns the cross product with a positive z-axis component.
t_direction	*direction_cross_up(t_direction *first, t_direction *second);
//Function adds two vectors together.
t_vector	*vector_add(t_vector *first, t_vector *second);
//Function subtracts two vectors.
t_vector	*vector_subtract(t_vector *first, t_vector *second);
//Function works out the vector cross product of two vectors.
t_vector	*vector_cross(t_vector *first, t_vector *second);
//Function scales a vector.
t_vector	*vector_scale(double scalar, t_vector *vector);
// --------------------------------- INTERSECTIONS -----------------------------
double		length_two_points_local(t_Vector3 *point_one, t_Vector3 *point_two);
t_Vector3	*direction_two_points_local(t_Vector3 *start, t_Vector3 *end);
double		dot(t_Vector3 *first, t_Vector3 *second);
t_Vector3	*substract_vectors(t_Vector3 *V, t_Vector3 *W);
void		populate_point(t_Vector3 *to_fill, double x, double y, double z);
t_Vector3	*scalar_times_vector(double scalar, t_Vector3 *v);
void 		solveQuadratic(double a, double b, double c);
// t_intersect *ray_sphere_intersection(t_ray	*ray);

// ============================= CAMERA/VIEW PROJECTION ========================
//Function works out the screen-up direction.
t_direction	*screen_up(t_camera *camera);
//Function works out the centre of the screen based on the camera properties.
t_point		*screen_centre(double width, t_camera *camera);
//Function works out the centres of the pixels in a screen.
void		screen_pixel_centres(int width, int height, t_camera *camera, \
										t_screen *screen);

// ================================= ERROR HANDLING ============================
//Function handles cleanly an error that requires the program to exit.
int			error_exit(t_program *program, char *str);
//Function prints an memory allocation error message.
void		error_malloc_print(char *str);
int 		ray_sphere_intersection(t_ray	*ray);

#endif
