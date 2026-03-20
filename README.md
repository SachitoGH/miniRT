# miniRT

This is an implementation of the miniRT program, part of the 42 curriculum.

This implementation contains a serie of bonuses and details not asked for the original subject. These are:

-	UI: Buttons and Spinners to manipulate some parameters
-	Replace some orientation vectors for Euler degrees
-	Extra figures:
	-	Cuboid
	-	Conoid
-	Textures management through 'Texture' objects
-	Materials management through 'Material' objects
-	Patterns management through 'Pattern' objects
-	Automatic system for detecting unique objects
-	Possibility of having optional arguments for some fields of certain objects

## IMPORTANT

Currently, textures are not implemented, so any try to use them will be ignored

# File Format

Each object of the scene is separated by one or more line separators. The fields of the objects must be
separated for one or more white spaces defined for the ft_isspace function. Elements with multiple fields
must be separated for a separator (by default, the ',')

## Limits:

|      **Field**     | **Min**       | **Max**       | **Type**   |
|:------------------ |:------------- |:------------- |:---------- |
| Brightness         | 0             | 1             | Float      |
| Color              | 0             | 255           | Int        |
| Position           | -50000        | 50000         | Float      |
| Rotation           | -50000        | 50000         | Float      |
| Scale              | -50000        | 50000         | Float      |
| Normal Vector      | 0             | 1             | Float      |
| FOV                | 0             | 180           | Int        |
| ID                 | 1 char.       | 25 char.      | String     |
| Type               | 1 char.       | -             | String     |
| Path               | 1 char.       | -             | String     |


## Types of patterns:

|   **Type**   | **Value**  |
|:-----------  |:---------  |
| Stript       | st         |
| Ring         | rn         |
| Gradient     | gr         |
| Checker      | ch         |

## Materials:

The materials contains a serie of fields who must be assigned in a strict order, these fiels (in order) are:

|      **Field**        | **Min**    | **Max**    | **Type**   |
|:--------------------- |:---------- |:---------- |:---------- |
| Diffuse               | 0          | 1          | Float      |
| Specular              | 0          | 1          | Float      |
| Ambient               | 0          | 1          | Float      |
| Transparence          | 0          | 1          | Float      |
| Reflection Index      | 0          | 4096       | Float      |
| Refraction Index      | 0          | 4096       | Float      |
| Shininess             | 0          | 4096       | Float      |

## Special:

These are a serie of special properties only available for certains objects. These are:

|      **Field**        | **Min**    | **Max**    | **Type**   |
|:--------------------- |:---------- |:---------- |:---------- |
| Minimum               | -50000     | 50000      | Float      |
| Maximum               | -50000     | 50000      | Float      |
| Closed                | 0          | 1          | Int        |

# Objects

## Notation

-	i	:	int
-	f	:	float (ints are also accepted)
-	s	:	string (strictly alfanumeric)
-	{}	:	argument is optional. If not specified, it will take the value of the precedent argument

## Special Objects:

-	Ambient Lightning

```A		Brightness(f)		Color_RGB(i,i,i)```

-	Camera

```C		Position(f,f,f)		Normal_vec(f,f,f)	FOV(i)```

-	Light

```l		Position(f,f,f)		Brightness(f)		Color_RGB(i,i,i)```

## Preloaded Objects:

These are a serie of objects who use an id to identify them, so they can be re used for multiple objects along
the scene. They are called preloaded since they are the first thing to be loaded for making sure the id's are
unique and other resources are available. These elements can be re-used for any element that allows them, putting
them as optional arguments. These objects are:

-	Texture

```t	ID(s)		Path(s)```

-	Pattern

```p	ID(s)		Type(s)		Position(f,f,f)		Rotation(f,f,f)		Scale(f,{f},{f})	Color1_RGB(i,i,i)	Color2_RGB(i,i,i)```

-	Material

```m	ID(s)		material(f,f,f,f,f,f,f)```

## Objects:

-	Ellipsoid (Sphere)

```sp	Position(f,f,f)		Rotation(f,f,f)		Scale(f,{f},{f})						Color_RGB(i,i,i)	{ID_preloaded(s)}```

-	Cuboid

```cb	Position(f,f,f)		Rotation(f,f,f)		Scale(f,{f},{f})						Color_RGB(i,i,i)	{ID_preloaded(s)}```

-	Cylinder

```cy	Position(f,f,f)		Rotation(f,f,f)		Scale(f,{f},{f})	Special(f,f,i)		Color_RGB(i,i,i)	{ID_preloaded(s)}```

-	Conoid

```cn	Position(f,f,f)		Rotation(f,f,f)		Scale(f,{f},{f})	Special(f,f,i)		Color_RGB(i,i,i)	{ID_preloaded(s)}```

-	Plane

```pl	Position(f,f,f)		Rotation(f,f,f)												Color_RGB(i,i,i)	{ID_preloaded(s)}```

For asigning a preloaded object, the ID must be specified. for assigning multiple preloaded objects to the
same object, each ID must be separated for one or more white spaces. Example:

```sp		Other_params...		ID_1	ID_2```

Only a maximun of 3 preloadeds can be assigned to the same object. if there are two or more preloadeds
of the same type (ex, two patterns) assigned to the same object, only the latest in the chain will be
taken. Example:

```sp		Other_params...		TEX_ID1		TEX_ID2```

In this example, only the TEX_ID2 preloaded will be taken.

# Known Problems

-	Due to float presicion issues, the textes of some Spinners are not shown correclty
-	Lightning is not correct for the Cylinders and the cones

# Yet to implement

-	Reflections/Refractions and therefore transparence
-	Textures

# Considerations

-	Skybox
-	Parser:
	-	Hexadecimals as color
-	Extra Figures (Not so hard to add if the right formula is deduced)
-	Multiple cameras for the same scene