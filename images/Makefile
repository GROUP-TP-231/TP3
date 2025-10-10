
CC = gcc               
CFLAGS = -Wall -Wextra 

# liste des fichiers source
SRC = main.c gris.c size.c cut.c negatif.c foncer.c mediane.c

# nom de l'exécutable
EXEC = ppmviewer

# règle principale : compile tout
all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)

# commande pour nettoyer les fichiers temporaires
clean:
	rm -f $(EXEC)
