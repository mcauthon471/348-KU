# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY exercise1.c .
# Compile the C program
RUN gcc -o exercise1 exercise1.c
# Set the command to run when the container starts
CMD ["./exercise1"]