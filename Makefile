CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Mandatory part
CLIENT = client
SERVER = server

MAN_DIR = ./mandatory
MAN_INC = ./include/minitalk.h

SRC_CLIENT = $(MAN_DIR)/client.c
SRC_SERVER = $(MAN_DIR)/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Bonus part
CLIENT_BON = client_bonus
SERVER_BON = server_bonus

BON_DIR = ./bonus
BON_INC = ./include/minitalk_bonus.h

SRC_CLIENT_BON = $(BON_DIR)/client_bonus.c
SRC_SERVER_BON = $(BON_DIR)/server_bonus.c

OBJ_CLIENT_BON = $(SRC_CLIENT_BON:.c=.o)
OBJ_SERVER_BON = $(SRC_SERVER_BON:.c=.o)

LIBFT_DIR = ./libft_utils
LIBFT = $(LIBFT_DIR)/libft.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(MAN_INC)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(CLIENT_BON) $(SERVER_BON)

$(CLIENT_BON): $(OBJ_CLIENT_BON) $(LIBFT) $(BON_INC)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BON) $(LIBFT) -o $(CLIENT_BON)

$(SERVER_BON): $(OBJ_SERVER_BON) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BON) $(LIBFT) -o $(SERVER_BON)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BON) $(OBJ_SERVER_BON)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BON) $(SERVER_BON)

re: fclean all