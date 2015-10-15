
  int fd, cpt_lines1, cpt_lines2 ;
  char *buffer ;

  trash_can = malloc(BUFSIZE*sizeof(char)) ;
  buffer = malloc(BUFSIZE*sizeof(char)) ;
  
  cpt_lines2 = (cpt_lines1 = 0) ;
  
  assert ((fd = open(path, O_RDONLY))!= (-1)) ;

  while (read(fd, trash_can, SSIZE_MAX)!=0)
    ++cpt_lines1 ;

  free(trash_can) ;
  
  lseek(fd, 0, SEEK_SET) ;

  while(cpt_lines2 != (cpt_lines1 - nline))
    {
      read(fd, trash_can, SSIZE_MAX) ;

      ++cpt_lines2 ;
    }

  while(read(fd, buffer, SSIZE_MAX) != 0) ;

  printf("%s\n", (char*)buffer) ;

  free(buffer) ;
  
  return EXIT_SUCCESS ;
}
