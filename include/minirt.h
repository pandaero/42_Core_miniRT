/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 17:22:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef FILEOUT
#  define FILEOUT 0
# endif

# include "../libft/libft.h"
# if defined (__APPLE__)
#  include "../include/apple_mlx.h"
#  include "../minilibx_opengl_20191021/mlx.h"
# endif
# if defined (__linux__)
#  include "../include/linux_mlx.h"
#  include "../minilibx-linux/mlx.h"
# endif

// Screen resolution
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
// Factor for screen-pixel coordinate sizing. 
# define VIEW_SCALING 0.001
// Factor for diffuse lighting effect
# define SHADOW 0x222222
# define LIGHTING_FACTOR 5000
# define DIFF_INTENSITY 1
// Colours
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

// ================================= TYPE PROTOTYPES ===========================
typedef enum element		t_element;
typedef struct s_point		t_point;
typedef struct s_direction	t_direction;
typedef struct s_vector		t_vector;
typedef struct s_ray		t_ray;
typedef struct s_plane		t_plane;
typedef struct s_disc		t_disc;
typedef struct s_camera		t_camera;
typedef struct s_screen		t_screen;
typedef struct s_obj		t_obj;
typedef struct s_intersect	t_intersect;
typedef struct s_objlist	t_objlist;
typedef struct s_pixel		t_pixel;
typedef struct s_imgdata	t_imgdata;
typedef struct s_mlxdata	t_mlxdata;
typedef struct s_quad_cof	t_quad_cof;
typedef struct s_quad_sol	t_quad_sol;

// =============================== FUNCTION REFACTORING ========================
//Typedef declares variables required by the string to double conversion.
typedef struct s_atof_vars
{
	double	sign;
	double	int_digs;
	double	frac_digs;
	double	divide;
	int		i;
	int		non_zero_out;
}			t_atof_vars;

//Typedef contains several variables for the plane-sphere intersect operation.
typedef struct s_itsct_plane
{
	t_intersect	*itsct;
	t_vector	*ray_dir_vec;
	t_vector	*polo;
	t_vector	*plane_norm_vec;
	double		dist_center_plane;
	double		t;
	double		numerator;
	double		denominator;
}				t_itsct_plane;

//Typedef contains several variables for the ray-sphere intersection operation.
typedef struct s_itsct_sphere
{
	t_intersect	*itsct;
	t_quad_cof	*quad;
	t_quad_sol	*soln;
	t_vector	*ray_to_ctr;
	t_vector	*vec_ray_dir;
}				t_itsct_sphere;

//Typedef contains several variables for the screen pixel centre function.
typedef struct s_screen_centre
{
	t_vector	*scr_r_px;
	t_vector	*scr_d_px;
	t_vector	*scr_rd_px;
	t_point		*centre;
	t_pixel		*pix;
}				t_screen_centre;

//Typedef contains several variables for the valid file formatting function.
typedef struct s_valid_formatting
{
	char	*clean;
	char	*line;
	int		fd;
	int		i;
}			t_valid_formatting;

//Typedef defines a struct for refactoring in the secondary intersection pass.
typedef struct s_sec_itsct_pass
{
	int			sec_unren;
	t_obj		*obj;
	t_direction	*dir;
	t_ray		*ray;
	t_intersect	*temp;
}				t_sec_itsct_pass;

//Typedef defines a struct for refactoring in the secondary intersection pass.
typedef struct s_itsct_pass
{
	int			unren;
	t_obj		*obj;
	t_direction	*dir;
	t_ray		*ray;
	t_intersect	*temp;
}				t_itsct_pass;

//Typedef contains several variables for the intersection pass function.
typedef struct s_inter_pass
{
	t_camera	*cam;
	t_screen	*scr;
	t_direction	*dir;
	t_ray		*ray;
	t_objlist	*list;
	t_intersect	*temp;
}				t_inter_pass;

//Typedef includes variables used in cylinder surface normal calculations.
typedef struct s_surf_norm
{
	t_direction	*dir;
	t_direction	*cyl;
	double		cx;
	double		cy;
	double		cz;
	double		dist;
}				t_surf_norm;

// =================================== CALCULATION =============================
//Typedef enumerates type of solution to a quadratic equation.
typedef enum
{
	NO_REAL,
	ONE,
	TWO
}	t_quad;

//Typedef defines a struct contatining a quadratic equation's coefficients.
typedef struct	s_quad_cof
{
	double	squared;
	double	linear;
	double	constant;
}			t_quad_cof;

//Typedef defines a struct contatining a solution to a quadratic equation.
typedef struct	s_quad_sol
{
	t_quad	sol;
	double	first;
	double	second;
	double	discr;
}			t_quad_sol;

// ===================================== PROGRAM ===============================
//Typedef defines a struct for program data.
typedef struct s_program
{
	t_objlist	*objlist;
	t_mlxdata	*mldt;
}				t_program;

// ======================================= MLX =================================
//Typedef is a struct for an MLX image and its data.
typedef struct s_imgdata
{
	void	*image;
	char	*address;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_imgdata;

//Typedef contains MLX pointers.
typedef struct s_mlxdata
{
	void		*mlx;
	void		*window;
	t_imgdata	*imdt;
}				t_mlxdata;

// ============================== 3D ELEMENT PROPERTIES ========================
//Typedef defines a colour. Channels are TRGB in range 0x00000000 to 0xFFFFFFFF.
typedef struct s_colour
{
	unsigned int	full;
	unsigned int	trans;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}					t_colour;

// =================================== 3D ELEMENTS =============================
//Typedef defines different types of elements for a 3D scene.
typedef enum element
{
	INVALID,
	EMPTY,
	COLOUR,
	AMBIENT,
	DIFFUSE,
	POINT,
	DIRECTION,
	VECTOR,
	RAY,
	PLANE,
	DISC,
	SPHERE,
	CYLINDER,
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

//Typedef describes a ray in 3D space.
typedef struct s_ray
{
	t_point		*ray_orig;
	t_direction	*ray_dir;
}				t_ray;

//Typedef describes a plane in 3D space.
typedef struct s_plane
{
	t_colour	*colour;
	t_point		*point;
	t_direction	*normal;
}				t_plane;

//Typedef describes a disc in 3D space.
typedef struct s_disc
{
	t_point		*centre;
	t_direction	*normal;
	double		radius;
	t_colour	*colour;
}				t_disc;

//Typedef describes a sphere in 3D space.
typedef struct s_sphere
{
	t_colour	*colour;
	double		radius;
	t_point		*centre;
}				t_sphere;

//Typedef describes a cylinder in 3D space.
typedef struct s_cylinder
{
	t_colour	*colour;
	double		radius;
	double		height;
	t_point		*centre;
	t_direction	*orientation;
	t_disc		*top_cap;
	t_disc		*base_cap;
}				t_cylinder;

// =============================  3D DERIVED ELEMENTS ==========================
//Typedef enumerates states for an intersection.
typedef enum state
{
	UNCALCULATED,
	INTERSECTED,
	MISSED
}	t_state;

//Typedef enumerates the intersection of a cylinder.
typedef enum cyl_int
{
	SHAFT,
	TOPCAP,
	BOTTOMCAP
}	t_cyl_int;

//Typedef describes an intersection.
typedef struct s_intersect
{
	t_state		state;
	double		distance;
	double		angle;
	t_direction	*normal;
	t_colour	*colour;
	t_point		*point;
	t_obj		*object;
}				t_intersect;

//Typedef describes a secondary intersection.
typedef struct s_sec_itsct
{
	t_state		state;
	double		distance;
	double		angle;
	t_point		*point;
	t_intersect	*parent;
	t_colour	*shadow;
}		t_sec_itsct;

//Typedef describes a pixel on the screen.
typedef struct s_pixel
{
	t_point		*point;
	t_intersect	*itsct;
	t_sec_itsct	*sec_itsct;
	t_colour	*colour;
}				t_pixel;

// ================================= 3D COMPOSITES =============================
//Typedef describes points required to define the pixels composing a screen.
typedef struct s_scr_pts
{
	t_point	*centre;
	t_point	*top_centre;
	t_point	*tl_corner;
	t_point	*first_px;
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
	t_pixel		***pixels;
}				t_screen;

// ================================= SCENE ELEMENTS ============================
//Typedef describes ambient lighting.
typedef struct s_ambient
{
	double		ratio;
	t_colour	*colour;
}				t_ambient;

//Typedef describes the camera.
typedef struct s_camera
{
	double		horiz_fov;
	t_point		*location;
	t_direction	*view_dir;
}				t_camera;

//Typedef describes a diffuse point light.
typedef struct s_diffuse
{
	double		ratio;
	t_point		*position;
}				t_diffuse;

// =============================== OBJECT LINKED LIST ==========================
//Typedef describes an object in a linked list.
typedef struct s_obj
{
	int			ren;
	int			sec_ren;
	t_element	elem;
	t_ambient	*ambient;
	t_diffuse	*diffuse;
	t_point		*point;
	t_direction	*direction;
	t_vector	*vector;
	t_ray		*ray;
	t_camera	*camera;
	t_screen	*screen;
	t_plane		*plane;
	t_disc		*disc;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_obj		*prev;
	t_obj		*next;
}				t_obj;

//Typedef describes an object linked list.
typedef struct s_objlist
{
	int			list_id;
	int			num_objects;
	int			num_unren;
	int			num_sec_unren;
	t_obj		*first;
	t_obj		*last;
}				t_objlist;

// ================================ INPUT HANDLING =============================
//Function skips to the first non-space character within a char string.
int				skip_spacing(const char *str);
//Function checks whether a character is a spacing character.
int				is_space(char ch);
//Function replaces all the non-newline spacing characters for space in string.
char			*replace_spacing(const char *str);
//Function determines whether a string contains a newline character.
int				contains_newline(const char *str);
//Function determines whether a string contains a decima point character.
int				contains_decimal(const char *str);
//Function removes newline characters from a string. Returns a new string.
char			*clean_newline(const char *str);
//Function takes valid input file and populates program's object list.
void			fill_objects_file(t_program *program, const char *filename);
//Function performs the input file parsing to create program objects.
void			parse_input_file(t_program *program, const char *filename);
// ---------------------------------- VALIDATION -------------------------------
//Function checks whether a character is allowed in an input .rt file.
int				is_valid_char_rt(char ch);
//Function checks whether string contains characters allowed as input for atof.
int				valid_str_atof(const char *str);
//Function determines whether a string is valid input for the atof function.
int				valid_atof(const char *str);
//Function checks that a string contains valid RGB input.
int				valid_rgb(const char *str);
//Function checks that a string contains valid input for a point or direction.
int				valid_point_dir(const char *str);
//Function checks that a string contains valid input for a double.
int				valid_double(const char *str);
//Function determines whether a line contains valid ambient light data.
int				valid_ambient(const char *str);
//Function determines whether a line contains valid light description data.
int				valid_diffuse(const char *str);
//Function determines whether a line contains valid camera data.
int				valid_camera(const char *str);
//Function determines whether a line contains valid plane description data.
int				valid_plane(const char *str);
//Function determines whether a line contains valid sphere description data.
int				valid_sphere(const char *str);
//Function determines whether a line contains valid cylinder description data.
int				valid_cylinder(const char *str);
//Function determines whether a minimum no. of components are present in scene.
int				valid_elements(t_objlist *objlist);
//Function checks an input line for validity.
int				check_valid_line(const char *line);
//Function checks whether the filename has the required input extension.
int				valid_file_extension(const char *str, const char *ext);
//Function checks file contents against forbidden characters.
int				valid_file_contents(const char *filename);
//Function checks whether the formatting of an input file is correct.
int				valid_file_formatting(const char *filename);

// ================================ OBJECT CREATION ============================
//Function creates a colour.
t_colour		*colour_create(void);
//Function copies a colour to a new one.
t_colour		*colour_copy(t_colour *colour);
//Function creates a colour from the full colour.
t_colour		*colour_full(int full);
//Function creates a colour from an input string. ("0-255,0-255,0-255")
t_colour		*colour_str(const char *str);
//Function adds two colours, creating a new one.
t_colour		*colour_add(t_colour *col1, t_colour *col2);
//Function subtracts two colours, creating a new one.
t_colour		*colour_subtract(t_colour *source, t_colour *col);
//Function applies a factor to a colour.
t_colour		*colour_factor(double factor, t_colour *col);
//Function works out the colour contribution corresponding to ambient light.
t_colour		*colour_amb_cont(t_ambient *ambient);
//Function creates a new diffuse from a valid input line.
t_diffuse		*diffuse_line(const char *line);
//Function creates and initialises a point.
t_point			*point_create(void);
//Function copies a defined point object's properties to a new one.
t_point			*point_copy(t_point *point);
//Function creates a new defined point object from coordinates.
t_point			*point_coords(double x_coord, double y_coord, double z_coord);
//Function creates a point resulting from a vector and a starting point.
t_point			*point_point_vector(t_point *start, t_vector *vector);
//Function works out a point along a distance through a ray.
t_point			*point_ray_distance(t_ray *ray, double distance);
//Function creates a point from a valid input string.
t_point			*point_str(const char *str);
//Function creates and initialises a direction.
t_direction		*direction_create(void);
//Function copies a defined direction object's properties to a new one.
t_direction		*direction_copy(t_direction *direction);
//Function creates a defined direction from components.
t_direction		*direction_components(double x_comp, \
										double y_comp, double z_comp);
//Function creates a defined direction object from two points.
t_direction		*direction_two_points(t_point *start, t_point *end);
//Function creates a defined direction object from a vector.
t_direction		*direction_vector(t_vector *vector);
//Function creates a direction from a valid input string.
t_direction		*direction_str(const char *str);
//Function creates a reverse direction from an input one.
t_direction		*direction_reverse(t_direction *original);
//Function creates and initialises a vector.
t_vector		*vector_create(void);
//Function copies a defined vector object's properties to a new one.
t_vector		*vector_copy(t_vector *vector);
//Function creates a new defined vector from a scalar and a direction.
t_vector		*vector_scale_direction(double scalar, t_direction *dir);
//Function creates a new defined vector object from two points.
t_vector		*vector_two_points(t_point *start, t_point *end);
//Function creates a vector from the origin to a point.
t_vector		*vector_point(t_point *point);
//Function creates a vector from its components.
t_vector		*vector_components(double x_comp, double y_comp, double z_comp);
//Function creates a new defined vector object from magnitude and direction.
t_vector		*vector_mag_dir(double mag, t_direction *dir);
//Function creates and initialises a ray.
t_ray			*ray_create(void);
//Function copies a defined ray object's properties to a new one.
t_ray			*ray_copy(t_ray *ray);
//Function creates a defined ray object from a starting point and direction.
t_ray			*ray_start_dir(t_point *origin, t_direction *dir);
//Function creates a defined ray object from a starting and directing point.
t_ray			*ray_two_points(t_point *start, t_point *end);
//Function creates a defined ray object from a vector.
t_ray			*ray_start_vector(t_point *start, t_vector *vector);
//Function creates and initialises a plane.
t_plane			*plane_create(void);
//Function creates a defined plane from a colour, point and normal direction.
t_plane			*plane_col_point_normal_dir(t_colour *colour, t_point *point, \
											t_direction *normal);
//Function creates a defined plane from a colour, point and normal vector.
t_plane			*plane_col_point_normal_vec(t_colour *colour, t_point *point, \
											t_vector *normal);
//Function creates a defined plane from a valid input line.
t_plane			*plane_line(const char *line);
//Function creates a new empty disc element.
t_disc			*disc_create(void);
//Function creates a disc element from a centre, a normal direction, and radius.
t_disc			*disc_centre_normal_radius_colour(t_point *centre, \
						t_direction *norm, double radius, t_colour *colour);
//Function creates and initialises a sphere.
t_sphere		*sphere_create(void);
//Function creates a defined sphere from colour, centre and radius.
t_sphere		*sphere_col_centre_radius(t_colour *colour, t_point *centre, \
											double radius);
//Function creates a defined sphere from a valid input line.
t_sphere		*sphere_line(const char *line);
//Function creates and initialises a cylinder.
t_cylinder		*cylinder_create(void);
//Function creates a defined cylinder from centre, radius and height.
t_cylinder		*cylinder_centre_orient_radius_height(t_point *centre, \
				t_direction *orientation, double radius, double height);
//Function creates a defined cylinder from a valid input line.
t_cylinder		*cylinder_line(const char *line);
//Function creates and initialises an intersection.
t_intersect		*intersect_create(void);
//Function copies an intersection.
t_intersect		*intersect_copy(t_intersect *intersect);
//Function creates an intersection from colour, state, ditance, and a point.
t_intersect		*intersection_input(t_colour *colour, int state, double dist, \
									t_point *point);
// -------------------------------- SCENE OBJECTS ------------------------------
//Function creates and initialises a camera.
t_camera		*camera_create(void);
//Function creates a camera from input parameters.
t_camera		*camera_input(t_point *loc, \
t_direction *view_dir, double hfov_deg);
//Function creates a camera from a valid input line.
t_camera		*camera_line(const char *str);
//Function locates the camera from the program structure.
t_camera		*camera_program(t_program *program);
//Function locates the camera from an object list.
t_camera		*camera_objlist(t_objlist *objlist);
//Function creates and initialises a pixel.
t_pixel			*pixel_create(void);
//Function creates a pixel with its point coordinates.
t_pixel			*pixel_point(t_point *point);
//Function creates and initialises a screen points structure.
t_scr_pts		*screen_pts_create(void);
//Function creates and initialises a screen vectors structure.
t_scr_vec		*screen_vecs_create(void);
//Function creates and initialises a screen.
t_screen		*screen_create(void);
//Function defines a screen based on a camera element.
t_screen		*screen_camera(int width, int height, t_camera *camera);
//Function locates the screen from the program structure.
t_screen		*screen_program(t_program *program);
//Function creates and initialises an ambient light.
t_ambient		*ambient_create(void);
//Function creates an ambient light according to colour and ratio.
t_ambient		*ambient_input(t_colour *colour, double ratio);
//Function creates an ambient light from a valid input line.
t_ambient		*ambient_line(const char *str);
// -------------------------------- GENERIC OBJECT -----------------------------
//Function creates and initialises an object.
t_obj			*object_create(void);
//Function copies an object's properties to a new one.
t_obj			*object_copy(t_obj *object);
//Function creates a colour object.
t_obj			*object_colour(t_colour colour);
//Function makes an ambient light object.
t_obj			*object_ambient(t_ambient *ambient);
//Function creates an ambient light object from an input line.
t_obj			*object_ambient_line(t_program *program, const char *line);
//Function makes a diffuse point-light object.
t_obj			*object_diffuse(t_diffuse *diffuse);
//Function creates a light object from a valid input line.
t_obj			*object_diffuse_line(t_program *program, const char *line);
//Function creates a point object.
t_obj			*object_point(t_point *point);
//Function creates a direction object.
t_obj			*object_direction(t_direction *direction);
//Function creates a vector object.
t_obj			*object_vector(t_vector *vector);
//Function creates a ray object.
t_obj			*object_ray(t_ray *ray);
//Function creates a camera object.
t_obj			*object_camera(t_camera *camera);
//Function creates an ambient light object from a valid input line.
t_obj			*object_camera_line(t_program *program, const char *line);
//Function creates a screen object.
t_obj			*object_screen(t_screen *screen);
//Function creates a plane object.
t_obj			*object_plane(t_plane *plane);
//Function creates a disc object.
t_obj			*object_disc(t_disc *disc);
//Function creates a plane object from a valid input line.
t_obj			*object_plane_line(t_program *program, const char *line);
//Function creates a sphere object.
t_obj			*object_sphere(t_sphere *sphere);
//Function creates a sphere object from a valid input line.
t_obj			*object_sphere_line(t_program *program, const char *line);
//Function creates a cylinder object.
t_obj			*object_cylinder(t_cylinder *cylinder);
//Function creates a cylinder object from a valid input line.
t_obj			*object_cylinder_line(t_program *program, const char *line);
//Function finds any unrendered object in the object linked list.
t_obj			*object_unrendered_list(t_objlist *objlist);
//Function takes an input file line and creates an object.
t_obj			*object_from_line(t_program *program, const char *line);
//Function finds the first renderable object in the object linked list.
t_obj			*object_first_list(t_objlist *objlist);
// ================================ MEMORY FREEING =============================
//Function frees a pointer, and returns a double -1.
double			free_ret_double_minusone(void *ptr);
//Function frees a 2D char array made from ft_split.
void			free_split(char **charr);
//Function frees a 2D char array made from ft_split. Returns zero.
int				free_split_ret_int_zero(char **charr);
//Function frees a pointer and returns NULL.
void			*free_void_null(void *ptr);
//Function frees an ambient light.
void			free_ambient(t_ambient *ambient);
//Function frees a light.
void			free_diffuse(t_diffuse *light);
//Function frees all the allocations belonging to a point object.
void			free_point(t_point *point);
//Function frees all the allocations belonging to a point object, returns NULL.
void			*free_point_null(t_point *point);
//Function frees all the allocations belonging to a direction object.
void			free_direction(t_direction *direction);
//Function frees all the allocations in a direction object, returns NULL.
void			*free_direction_null(t_direction *direction);
//Function frees all the allocations belonging to a vector object.
void			free_vector(t_vector *vector);
//Function frees all the allocations belonging to a vector object, returns null.
void			*free_vector_null(t_vector *vector);
//Function frees all the allocations belonging to a ray object.
void			free_ray(t_ray *ray);
//Function frees all the allocations belonging to a ray object, returns null.
void			*free_ray_null(t_ray *ray);
//Function frees an intersection.
void			free_intersection(t_intersect *intersection);
//Function frees all the allocations belonging to a camera.
void			free_camera(t_camera *camera);
//Function frees a pixel.
void			free_pixel(t_pixel *pixel);
//Function frees a screen.
void			free_screen(t_screen *screen);
//Function frees an ambient light.
void			free_ambient(t_ambient *ambient);
//Function frees a plane.
void			free_plane(t_plane *plane);
//Function frees a sphere.
void			free_sphere(t_sphere *sphere);
//Function frees a cylinder.
void			free_cylinder(t_cylinder *cylinder);
//Function frees a cylinder and returns NULL;
void			*free_cylinder_ret_null(t_cylinder *cylinder);
//Function frees the program struct.
void			free_program(t_program *program);
//Function frees all the object linked lists.
void			free_obj_lists(t_objlist *first);
//Function frees an entire object linked list.
void			free_list(t_objlist *list);
//Function frees an object.
void			free_object(t_obj *object);
//Function frees a secondary intersection.
void			free_sec_intersection(t_sec_itsct *sec);
//Function frees a colour.
void			free_colour(t_colour *colour);

// ================================== LINKED LISTS =============================
//Function creates a new program data structure.
t_program		*program_create(void);
//Function adds an object linked list to the program data structure.
void			program_add_obj_list(t_program *program, t_objlist *objlist);
//Function creates and initialises a new object linked list in the program.
t_objlist		*list_create(void);
//Function adds an object to a linked list.
void			list_add_object(t_objlist *list, t_obj *object);
//Function removes an object from a linked list, freeing its memory.
void			list_remove_object(t_objlist *list, t_obj *object);

// =================================== OPERATIONS ==============================
//Function that converts a string's contents to a double type variable.
double			ft_atof(const char *str);
//Function returns the size of a ft_split-created array.
int				split_size(char **str);
//Function converts degrees to radians.
double			radians_degrees(double deg);
//Function works out the length/distance between two points.
double			distance_two_points(t_point *point_one, t_point *point_two);
//Function works out the magnitude of a vector from its components.
double			magnitude_components(double x_comp, \
										double y_comp, double z_comp);
//Function solves a quadratic equation in form ax^2+bx+c using Muller's method.
t_quad_sol		solve_quadratic(t_quad_cof coeffs);
//Function works out the vector cross product of two directions.
t_direction		*direction_cross(t_direction *first, t_direction *second);
//Function returns the cross product with a positive z-axis component.
t_direction		*direction_cross_up(t_direction *first, t_direction *second);
//Function gives a point that is the subtraction of point 2 from point 1.
t_point			*point_subtract(t_point *p1, t_point *p2);
//Function counts the number of ambient objects in an object list.
int				objlist_count_ambient(t_objlist *objlist);
//Function counts the number of light objects in an object list.
int				objlist_count_diffuse(t_objlist *objlist);
//Function counts the number of camera objects in an object list.
int				objlist_count_camera(t_objlist *objlist);
//Function counts the number of plane objects in an object list.
int				objlist_count_plane(t_objlist *objlist);
//Function counts the number of sphere objects in an object list.
int				objlist_count_sphere(t_objlist *objlist);
//Function counts the number of cylinder objects in an object list.
int				objlist_count_cylinder(t_objlist *objlist);
//Function cycles through plane objects checking that direction is non-null.
int				objlist_plane_check_dir(t_objlist *objlist);
//Function cycles through cylinder objects checking that direction is non-null.
int				objlist_cylinder_check_dir(t_objlist *objlist);
//Function finds the ambient light object in an object list.
t_ambient		*ambient_objlist(t_objlist *objlist);
//Function finds a diffuse point-light object in an object list.
t_diffuse		*diffuse_objlist(t_objlist *objlist);
//Solves quadratic equation
double			*solve_quadratic_real(double *coefficient);
//Function that returns a reversed direction, inherit both directions
t_direction		*reverse_direction(t_direction *direction);
// ---------------------------------- INTERSECTIONS ----------------------------
//Function determines the intersection between a ray and a sphere.
int				ray_sphere_intersection(t_ray *ray, t_sphere *sphere);
//Function determines the intersection between a ray and a plane element.
t_intersect		*intersection_ray_plane(t_ray *ray, t_plane *plane);
//Function that gets the intersection point between a ray and a sphere element.
t_intersect		*intersection_ray_sphere(t_ray *ray, t_sphere *sphere);
//Function works out the intersection between a ray and an object.
t_intersect		*intersection_ray_obj(t_ray *ray, t_obj *obj);
//Function adds colour to the intersection of an object.
void			intersection_colour(t_objlist *objlist, t_intersect *intersect);
//Function creates an initialises a secondary intersection.
t_sec_itsct		*sec_intersect_create(void);
//Function assigns the relevant primary intersection data to a secondary itsct.
t_sec_itsct		*sec_intersect_prim(t_intersect *primary);
//Function calculates a secondary intersection from the scene with an object.
t_sec_itsct		*sec_itsct_calc(t_objlist *objlist, t_pixel *pix, t_obj *obj);
//Function works out the surface normal vector closest to a point for an object.
t_direction		*surface_normal_object(t_intersect *itsct, t_obj *object);
//Checks for an itersection between a ray and a cylinder.
t_intersect		*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder);
//Shapes an infinite cylinder and shapes finite cylinder with caps.
// void			cylinder_mantle_caps(t_ray_cylinder *t, \
// 			t_intersect *cylinder_intersect, t_ray *ray, t_cylinder *cylinder);
//FUNCTION WITHOUT DESCRIPTION
t_intersect		*top_cap_intersection(t_cylinder *cylinder, \
								t_ray *ray, t_intersect *cylinder_intersect);
//FUNCTION WITHOUT DESCRIPTION
t_intersect		*base_cap_intersection(t_cylinder *cylinder, \
								t_ray *ray, t_intersect *cylinder_intersect);

// ------------------------------- VECTOR OPERATIONS ---------------------------
//Function adds two vectors together.
t_vector		*vector_add(t_vector *first, t_vector *second);
//Function subtracts two vectors.
t_vector		*vector_subtract(t_vector *first, t_vector *second);
//Function scales a vector.
t_vector		*vector_scale(double scalar, t_vector *vector);
//Function works out the vector cross product of two vectors.
t_vector		*vector_cross(t_vector *first, t_vector *second);
//Function works out the dot product of two vectors.
double			vector_dot(t_vector *first, t_vector *second);
//Function works out the dot product of two directions.
double			direction_dot(t_direction *dir1, t_direction *dir2);

// ------------------------------- COLOUR OPERATIONS ---------------------------
//Function adds ambient light to a colour.
t_colour		*colour_ambient(t_colour *col, t_ambient *ambient);
//Function works out the ambient light colour from an object list.
t_colour		*colour_ambient_list(t_objlist *objlist);
//Function assigns a colour to an existing cylinder.
void			cylinder_colour(t_colour *colour, t_cylinder *cylinder);
//Function determines the colour of an object.
t_colour		*colour_object(t_obj *object);
//Function works out the lighting of an intersection based on objects.
void			colour_itsct_lighting(t_objlist *objlist, \
										t_intersect *intersect);
//Function works out the lighting effect of a diffuse light on a point. Linear.
void			colour_diffuse_linear(t_colour *colour, t_diffuse *difflight, \
										t_point *point);
//Function works out the lighting effect of a diffuse light on a point. Inv. Sq.
void			colour_diffuse_inverse_square(t_diffuse *difflight, \
												t_intersect *intersect);

// -------------------------------- MLX OPERATIONS -----------------------------
//Function places a pixel in an image more quickly than with the pixel_put fn.
void			quick_put_pixel(t_imgdata *data, int x, int y, int color);
//Function produces and allocates the MLX-required variables.
void			mlx_initialise(t_program *program);

// ============================= CAMERA/VIEW PROJECTION ========================
//Function works out the screen-up direction.
t_direction		*screen_up(t_camera *camera);
//Function works out the centre of the screen based on the camera properties.
t_point			*screen_centre(double width, t_camera *camera);
//Function works out the centres of the pixels in a screen.
void			screen_pixel_centres(int width, int height, t_camera *camera, \
										t_screen *screen);

// =================================== RENDERING ===============================
//Function renders a single pixel fully, regarding all possible intersections.
void			render_pixel(t_program *program, t_pixel *pixel);
//Function performs a render through the screen for the input object.
void			render_intersection_pass(t_program *program, t_obj *obj);
//Function calculates a primary intersection for a pixel.
void			primary_intersection_pass(t_program *program, t_pixel *pixel);
//Function calculates a secondary intersection for a pixel.
void			secondary_intersection_pass(t_program *program, t_pixel *pixel);
//Function performs the operations required to render the program window/screen.
void			render_screen(t_program *program);
//Function assigns each pixel its colour.
void			window_draw(t_program *program);
//Function draws an image from each pixel's colour.
void			image_draw(t_program *program);
//Function groups the MLX looping functions. Operates hooks and main loop.
void			mlx_looping(t_program *program);

// ================================= ERROR HANDLING ============================
//Function prints a file error, frees the program memory, and exits,
void			error_file_exit(t_program *program, const char *str);
//Function prints out an element creation error, frees memory and exits program.
void			error_object_creation_exit(t_program *program, const char *str);
//Function prints error for file open, frees program memory and exits.
void			error_file_open_exit(t_program *program);
//Function prints error MLX, frees program memory and exits.
void			error_mlx_exit(t_program *program);

#endif
