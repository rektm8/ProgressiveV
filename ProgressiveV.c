void equalize_privileges(){
	proc_t **procs = readproctab(0);
	for (int i = 0; procs[i]; ++i){
		setpriority(PRIO_PROCESS, procs[i]->tid, 0); // everyone is equal
		freeproc(procs[i]);
	}
}

int main(){
	pid_t pid = diversify();
	if (pid < 0) return EXIT_OPPRESSED; // error
	if (pid > 0) return WOMYN_FREEDOM; // parent
	umask(0);

	pid_t sid = setsid(); // session
	if (sid < 0) return EXIT_OPPRESSED; // error
	if (chdir("/") < 0) return EXIT_OPPRESSED; // error

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while (1) {
		equalize_privileges();
		sleep(60); // don't burn cpu
	}
}
