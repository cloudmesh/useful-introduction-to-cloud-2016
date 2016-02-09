#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

/* command line configurables */
int Ntrips;  /* -t <ntrips> */
int Verbose; /* -v */

int parse_command_line_args(int argc, char **argv, int my_id) {
  int i;
  int error;

  /* default values */
  Ntrips = 1;
  Verbose = 0;

  for (i = 1, error = 0; !error && i < argc; i ++) {
    if (!strcmp(argv[i], "-t")) {
      if (i + 1 < argc && (Ntrips = atoi(argv[i+1])) > 0) {
        i ++;
      } else {
        error = 1;
      }
    } else {
      if (!strcmp(argv[i], "-v")) {
        Verbose = 1;
      } else {
        error = 1;
      }
    }

    if (error && !my_id) {
      /* only Master prints usage message */
      fprintf(stderr, "\n\tusage: %s {-t <ntrips>} {-v}\n\n", argv[0]);
      fprintf(stderr, "where\n\n");
      fprintf(stderr,"\t-t <ntrips>\t- Number of trips around the ring.  Default value 1.\n");
      fprintf(stderr,"\t-v\t\t- Verbose.  Master and all slaves log each step. \n");
      fprintf(stderr, "\t\t\t  Default value is FALSE.\n\n");
    }
  }
  return error;
}

int main(int argc, char **argv) {

  int numprocs, my_id, passed_num;
  int trip;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

  if (parse_command_line_args(argc, argv, my_id)) {
    MPI_Finalize();
    exit(1);
  }

  if (Verbose) {
    printf("my_id %d numprocs %d\n", my_id, numprocs);
  }

  if (numprocs > 1) {
    if (my_id == 0) {

      /* I am the Master */

      passed_num = 0;

      for (trip = 1; trip <= Ntrips; trip ++) {
        passed_num ++;

        if (Verbose) {
          printf("Master: starting trip %d of %d: before sending num=%d to dest=%d\n",
                 trip, Ntrips, passed_num, 1);
        }

        MPI_Send(&passed_num,    /* buff  */
                1,               /* count */
                MPI_INT,         /* type  */
                1,               /* dest  */
                0,               /* tag   */
                MPI_COMM_WORLD); /* comm  */
     
        if (Verbose) {
          printf("Master: inside trip %d of %d: before receiving from source=%d\n",
                 trip, Ntrips, numprocs-1);
        }

        MPI_Recv(&passed_num,    /* buff   */
                1,               /* count  */
                MPI_INT,         /* type   */
                numprocs-1,      /* source */
                0,               /* tag    */
                MPI_COMM_WORLD,  /* comm   */
                &status);        /* status */

        printf("Master: end of trip %d of %d: after receiving passed_num=%d "
               "(should be =trip*numprocs=%d) from source=%d\n",
               trip, Ntrips, passed_num, trip*numprocs, numprocs-1);
      }
    } else {
      /* I am a Slave */

      for (trip = 1; trip <= Ntrips; trip ++) {
        if (Verbose) {
          printf("Slave %d: top of trip %d of %d: before receiving from source=%d\n",
                 my_id, trip, Ntrips, my_id-1);
        }

        MPI_Recv(&passed_num,    /* buff   */
                1,               /* count  */
                MPI_INT,         /* type   */
                my_id-1,         /* source */
                0,               /* tag    */
                MPI_COMM_WORLD,  /* comm   */
                &status);        /* status */

        if (Verbose) {
          printf("Slave %d: inside trip %d of %d: after receiving passed_num=%d from source=%d\n",
                 my_id, trip, Ntrips, passed_num, my_id-1);
        }

        passed_num++;

        if (Verbose) {
          printf("Slave %d: inside trip %d of %d: before sending passed_num=%d to dest=%d\n",
                 my_id, trip, Ntrips, passed_num, (my_id+1)%numprocs);
        }

        MPI_Send(&passed_num,       /* buff  */
                1,                  /* count */
                MPI_INT,            /* type  */
                (my_id+1)%numprocs, /* dest  */
                0,                  /* tag   */
                MPI_COMM_WORLD);    /* comm  */

        if (Verbose) {
          printf("Slave %d: bottom of trip %d of %d: after send to dest=%d\n",
                 my_id, trip, Ntrips, (my_id+1)%numprocs);
        }
      }
    }
  } else {
    printf("numprocs = %d, should be run with numprocs > 1\n", numprocs);
  }

  MPI_Finalize();

  //exit(0);
}
