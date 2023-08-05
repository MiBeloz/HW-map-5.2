FROM ubuntu:20.04
	LABEL maintainer="mihabeloz@gmail.com"
	RUN apt update -y && apt upgrade -y
	RUN apt install -y g++ clang nano
	WORKDIR /root/hw-map-5.2/
	COPY main.cpp .
	RUN g++ main.cpp -o main_gpp
	CMD ["./main_gpp"]
	RUN clang++ main.cpp -o main_clang
	CMD ["./main_clang"]
