run postgres (and persist data)

    mkdir psqldata
	docker run --rm   --name pg-docker -e POSTGRES_PASSWORD=docker -d -p 5432:5432 -v `pwd`/psqldata:/var/lib/postgresql/data  postgres:alpine

connect to it; NB the hostname `docker@docker.for.mac.localhost` trick
from inside another docker container (on mac)

    docker run -it --rm jbergknoff/postgresql-client postgresql://postgres:docker@docker.for.mac.localhost:5432
