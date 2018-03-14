	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register; it is caller saved.
 */
	.globl thread_switch
thread_switch:
	
	pushal 				//stores every register
	
	movl current_thread, %eax	//hold current thread in temp register
	movl %esp, (%eax)		//set sp field in current thread

	movl next_thread, %eax		//hold next thread in temp register
	movl (%eax), %esp		//set sp field in current thread

	movl %eax, current_thread	//next thread = current thread

	movl $0x0, next_thread		//reset next_thread to 0

	popal				//restore every register

	
	ret				/* pop return address from stack */
