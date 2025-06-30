NAME=inception
LOGIN=mery
DATA_PATH=/home/$(LOGIN)/data

all: build up

build:
	mkdir -p $(DATA_PATH)/mariadb $(DATA_PATH)/wordpress
	docker compose -f docker-compose.yml build

up:
	docker compose -f docker-compose.yml up -d

down:
	docker compose -f docker-compose.yml down

clean: down
	mkdir -p $(DATA_PATH)/mariadb $(DATA_PATH)/wordpress
	sudo chown -R $(LOGIN):$(LOGIN) $(DATA_PATH)
	rm -rf $(DATA_PATH)/mariadb/* $(DATA_PATH)/wordpress/*

fclean: clean
	@if [ -n "$$(docker volume ls -q)" ]; then \
		docker volume rm $$(docker volume ls -q); \
	else \
		echo "No volumes to remove."; \
	fi

re: fclean all
