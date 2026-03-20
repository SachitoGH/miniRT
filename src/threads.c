#include <pthread.h> // Required for pthreads
#include "../headers/miniRT.h"

/*
 * Structure to hold data passed to each rendering thread.
 * Each thread will render a specific portion of the image.
 */
typedef struct
{
    t_scene* s;      // Pointer to the scene data (camera, world, objects)
    t_image* img;    // Pointer to the image canvas where pixels will be written
    int         start_y; // The starting row (y-coordinate) for this thread to process
    int         end_y;   // The ending row (y-coordinate) for this thread to process
    int         step;    // The step size (number of threads) for interleaved row processing
} thread_data;

/*
 * Function executed by each rendering thread.
 * It calculates and writes pixel colors for its assigned portion of the image.
 *
 * Parameters:
 * arg: A void pointer to a thread_data structure, containing all necessary
 * information for the thread to perform its rendering task.
 *
 * Returns:
 * NULL (as required by pthread_create signature).
 */
void* render_portion(void* arg)
{
    thread_data* data = (thread_data*)arg;
    t_render_info   info; // Render info specific to each pixel
    unsigned int    pixel_color; // Stores the computed color for the current pixel
    int             i; // Current row index (y-coordinate)
    int             j; // Current column index (x-coordinate)

    // Iterate through the assigned rows for this thread.
    // The 'step' ensures that rows are interleaved among threads,
    // which helps with load balancing.
    for (i = data->start_y; i < data->end_y; i += data->step)
    {
        // Iterate through all columns for the current row.
        for (j = 0; j < data->img->width; j++) // Use img->width for horizontal size
        {
            // Set the ray tracing depth for the current pixel.
            // This determines how many times a ray can bounce in the scene.
            info.depth = 4; // Example depth, can be a parameter if needed

            // Calculate the direction of the ray for the current pixel (j, i).
            // ray_for_pixel uses the camera's internal transformation to compute
            // the ray direction from the camera's origin through the pixel.
            info.dir = ray_for_pixel(&data->s->camera, j, i);

            // Compute the color at the current pixel by tracing the ray into the scene.
            // 'paint' function handles ray intersection, lighting, and material properties.
            pixel_color = paint(data->s, &info);

            // Write the computed color to the corresponding pixel in the image buffer.
            // This directly accesses the image memory provided by minilibx.
            *(unsigned int *)(data->img->addr + (i * data->img->line_length + j
                                * (data->img->bits_per_pixel / 8))) = pixel_color;
        }
    }
    return NULL;
}

/*
 * Multi-threaded rendering function.
 * Divides the rendering task among multiple threads to speed up image generation.
 *
 * Parameters:
 * rt: A pointer to the t_minirt structure, which contains the scene data (camera, objects)
 * and the rendering image buffer (rt->render) as well as mlx pointers.
 */
void thread_render(t_minirt *rt)
{
    int             num_threads; // Number of threads to use
    pthread_t       *threads;    // Array of thread identifiers
    thread_data     *thread_args; // Array of thread_data structures for each thread
    int             i;           // Loop counter

    // Determine the number of available CPU cores to optimize thread count.
    // sysconf(_SC_NPROCESSORS_ONLN) is a portable way to get online processors.
    num_threads = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_threads <= 0)
        num_threads = 4; // Fallback to a default if detection fails or for systems with 1 core

    // Allocate memory for thread identifiers and thread arguments dynamically.
    // It's crucial to check for allocation failures.
    threads = (pthread_t*)malloc(sizeof(pthread_t) * num_threads);
    thread_args = (thread_data*)malloc(sizeof(thread_data) * num_threads);
    if (!threads || !thread_args)
    {
        // Basic error handling for memory allocation failure.
        // In a real application, you might want more robust error reporting.
        if (threads) free(threads);
        if (thread_args) free(thread_args);
        // fprintf(stderr, "Error: Failed to allocate memory for threads.\n");
        return;
    }

    // Create and launch each rendering thread.
    for (i = 0; i < num_threads; i++)
    {
        // Populate the thread_data structure for the current thread.
        thread_args[i].s = &rt->scene; // Pass a pointer to the main scene data
        thread_args[i].img = &rt->render; // Pass a pointer to the image buffer
        thread_args[i].start_y = i; // Each thread starts at a different row to interleave
        thread_args[i].end_y = rt->render.height; // All threads process up to the full height
        thread_args[i].step = num_threads; // The step ensures interleaved processing

        // Create the thread, passing render_portion as the function to execute
        // and a pointer to its specific thread_data as argument.
        pthread_create(&threads[i], NULL, render_portion, &thread_args[i]);
    }

    // Wait for all created threads to complete their execution.
    // pthread_join blocks until the specified thread terminates.
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Free the dynamically allocated memory for threads and arguments.
    free(threads);
    free(thread_args);

    // After all threads have completed rendering, put the final image to the window.
    mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
        rt->render.ptr, rt->render.x, rt->render.y);
}