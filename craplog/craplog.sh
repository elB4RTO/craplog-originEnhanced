#!/bin/bash

printf "\n\
  CCCC  RRRR   AAAAA  PPPP   L      OOOOO  GGGGG\n\
 C      R   R  A   A  P   P  L      O   O  G    \n\
 C      RRRR   AAAAA  PPPP   L      O   O  G  GG\n\
 C      R  R   A   A  P      L      O   O  G   G\n\
  CCCC  R   R  A   A  P      LLLLL  OOOOO  GGGGG\n\n"


printf "Hello\n\n"
sleep 1

FallbackPATH="$(pwd)"

cd "$(dirname $(realpath $0))"

while [ -e ./CLEAN.txt ] || [ -e ./IPS ] || [ -e ./REQUESTS ] || [ -e ./RESULTS ] || [ -e ./USER-AGENTS ] || [ -e ./IPS.tmp ] || [ -e ./REQUESTS.tmp ] || [ -e ./RESULTS.tmp ] || [ -e ./USER-AGENTS.tmp ]
do
	printf "Let me check one thing ..."
	sleep 1
	printf "\nThere are conflict files in this folder"
	printf "\nDo you want me to delete 'em? Y/N\n: "
	read question
	case $question in
		'y' | 'Y')
			if [ -e ./CLEAN.txt ]
				then
					rm ./CLEAN.txt
				fi
			if [ -e ./IPS ]
				then
					rm ./IPS
				fi
			if [ -e ./REQUESTS ]
				then
					rm ./REQUESTS
				fi
			if [ -e ./RESULTS ]
				then
					rm ./RESULTS
				fi
			if [ -e ./USER-AGENTS ]
				then
					rm ./USER-AGENTS
				fi
			if [ -e ./IPS.tmp ]
				then
					rm ./IPS.tmp
				fi
			if [ -e ./REQUESTS.tmp ]
				then
					rm ./REQUESTS.tmp
				fi
			if [ -e ./RESULTS.tmp ]
				then
					rm ./RESULTS.tmp
				fi
			if [ -e ./USER-AGENTS.tmp ]
				then
					rm ./USER-AGENTS.tmp
				fi
			printf "\nI've deleted files, let's start\n\n"
			sleep 2
			;;
		*)
			printf "\nOh, ok. Bye\n"
			exit
			;;
		esac
done

printf "Ready to go?\n: "
read question
	case $question in
		*)
			if [ -e ./IPS ]
				then
					mv ./IPS ./IPS.tmp
				else
					touch ./IPS.tmp
				fi
			if [ -e ./REQUESTS ]
				then
					mv ./REQUESTS ./REQUESTS.tmp
				else
					touch ./REQUESTS.tmp
				fi
			if [ -e ./RESULTS ]
				then
					mv ./RESULTS ./RESULTS.tmp
				else
					touch ./RESULTS.tmp
				fi
			if [ -e ./USER-AGENTS ]
				then
					mv ./USER-AGENTS ./USER-AGENTS.tmp
				else
					touch ./USER-AGENTS.tmp
				fi
			printf "3\n"
			sleep 1
			printf "2\n"
			sleep 1
			printf "1\n"
			sleep 1
			printf "START\n...\n"
		;;
	esac 
./crapp
printf "DONE!"
sleep 1

printf "\n\nJust let me tidy up my workplace ..."
sleep 1
rm ./*.tmp
cd "$FallbackPATH"
printf "Ok, done"
sleep 1
printf "\nSee you the next time :D"
printf "\nBye\n\n"
