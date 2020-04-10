
msb:     file format elf32-i386


Disassembly of section .init:

000003bc <_init>:
_init():
 3bc:	53                   	push   %ebx
 3bd:	83 ec 08             	sub    $0x8,%esp
 3c0:	e8 bb 00 00 00       	call   480 <__x86.get_pc_thunk.bx>
 3c5:	81 c3 0b 1c 00 00    	add    $0x1c0b,%ebx
 3cb:	8b 83 24 00 00 00    	mov    0x24(%ebx),%eax
 3d1:	85 c0                	test   %eax,%eax
 3d3:	74 05                	je     3da <_init+0x1e>
 3d5:	e8 5e 00 00 00       	call   438 <__gmon_start__@plt>
 3da:	83 c4 08             	add    $0x8,%esp
 3dd:	5b                   	pop    %ebx
 3de:	c3                   	ret    

Disassembly of section .plt:

000003e0 <.plt>:
 3e0:	ff b3 04 00 00 00    	pushl  0x4(%ebx)
 3e6:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
 3ec:	00 00                	add    %al,(%eax)
	...

000003f0 <printf@plt>:
 3f0:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
 3f6:	68 00 00 00 00       	push   $0x0
 3fb:	e9 e0 ff ff ff       	jmp    3e0 <.plt>

00000400 <__libc_start_main@plt>:
 400:	ff a3 10 00 00 00    	jmp    *0x10(%ebx)
 406:	68 08 00 00 00       	push   $0x8
 40b:	e9 d0 ff ff ff       	jmp    3e0 <.plt>

00000410 <putchar@plt>:
 410:	ff a3 14 00 00 00    	jmp    *0x14(%ebx)
 416:	68 10 00 00 00       	push   $0x10
 41b:	e9 c0 ff ff ff       	jmp    3e0 <.plt>

00000420 <atoi@plt>:
 420:	ff a3 18 00 00 00    	jmp    *0x18(%ebx)
 426:	68 18 00 00 00       	push   $0x18
 42b:	e9 b0 ff ff ff       	jmp    3e0 <.plt>

Disassembly of section .plt.got:

00000430 <__cxa_finalize@plt>:
 430:	ff a3 20 00 00 00    	jmp    *0x20(%ebx)
 436:	66 90                	xchg   %ax,%ax

00000438 <__gmon_start__@plt>:
 438:	ff a3 24 00 00 00    	jmp    *0x24(%ebx)
 43e:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000440 <_start>:
_start():
 440:	31 ed                	xor    %ebp,%ebp
 442:	5e                   	pop    %esi
 443:	89 e1                	mov    %esp,%ecx
 445:	83 e4 f0             	and    $0xfffffff0,%esp
 448:	50                   	push   %eax
 449:	54                   	push   %esp
 44a:	52                   	push   %edx
 44b:	e8 22 00 00 00       	call   472 <_start+0x32>
 450:	81 c3 80 1b 00 00    	add    $0x1b80,%ebx
 456:	8d 83 30 e8 ff ff    	lea    -0x17d0(%ebx),%eax
 45c:	50                   	push   %eax
 45d:	8d 83 d0 e7 ff ff    	lea    -0x1830(%ebx),%eax
 463:	50                   	push   %eax
 464:	51                   	push   %ecx
 465:	56                   	push   %esi
 466:	ff b3 28 00 00 00    	pushl  0x28(%ebx)
 46c:	e8 8f ff ff ff       	call   400 <__libc_start_main@plt>
 471:	f4                   	hlt    
 472:	8b 1c 24             	mov    (%esp),%ebx
 475:	c3                   	ret    
 476:	66 90                	xchg   %ax,%ax
 478:	66 90                	xchg   %ax,%ax
 47a:	66 90                	xchg   %ax,%ax
 47c:	66 90                	xchg   %ax,%ax
 47e:	66 90                	xchg   %ax,%ax

00000480 <__x86.get_pc_thunk.bx>:
__x86.get_pc_thunk.bx():
 480:	8b 1c 24             	mov    (%esp),%ebx
 483:	c3                   	ret    
 484:	66 90                	xchg   %ax,%ax
 486:	66 90                	xchg   %ax,%ax
 488:	66 90                	xchg   %ax,%ax
 48a:	66 90                	xchg   %ax,%ax
 48c:	66 90                	xchg   %ax,%ax
 48e:	66 90                	xchg   %ax,%ax

00000490 <deregister_tm_clones>:
deregister_tm_clones():
 490:	e8 e4 00 00 00       	call   579 <__x86.get_pc_thunk.dx>
 495:	81 c2 3b 1b 00 00    	add    $0x1b3b,%edx
 49b:	8d 8a 38 00 00 00    	lea    0x38(%edx),%ecx
 4a1:	8d 82 38 00 00 00    	lea    0x38(%edx),%eax
 4a7:	39 c8                	cmp    %ecx,%eax
 4a9:	74 1d                	je     4c8 <deregister_tm_clones+0x38>
 4ab:	8b 82 1c 00 00 00    	mov    0x1c(%edx),%eax
 4b1:	85 c0                	test   %eax,%eax
 4b3:	74 13                	je     4c8 <deregister_tm_clones+0x38>
 4b5:	55                   	push   %ebp
 4b6:	89 e5                	mov    %esp,%ebp
 4b8:	83 ec 14             	sub    $0x14,%esp
 4bb:	51                   	push   %ecx
 4bc:	ff d0                	call   *%eax
 4be:	83 c4 10             	add    $0x10,%esp
 4c1:	c9                   	leave  
 4c2:	c3                   	ret    
 4c3:	90                   	nop
 4c4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 4c8:	f3 c3                	repz ret 
 4ca:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

000004d0 <register_tm_clones>:
register_tm_clones():
 4d0:	e8 a4 00 00 00       	call   579 <__x86.get_pc_thunk.dx>
 4d5:	81 c2 fb 1a 00 00    	add    $0x1afb,%edx
 4db:	55                   	push   %ebp
 4dc:	8d 8a 38 00 00 00    	lea    0x38(%edx),%ecx
 4e2:	8d 82 38 00 00 00    	lea    0x38(%edx),%eax
 4e8:	29 c8                	sub    %ecx,%eax
 4ea:	89 e5                	mov    %esp,%ebp
 4ec:	53                   	push   %ebx
 4ed:	c1 f8 02             	sar    $0x2,%eax
 4f0:	89 c3                	mov    %eax,%ebx
 4f2:	83 ec 04             	sub    $0x4,%esp
 4f5:	c1 eb 1f             	shr    $0x1f,%ebx
 4f8:	01 d8                	add    %ebx,%eax
 4fa:	d1 f8                	sar    %eax
 4fc:	74 14                	je     512 <register_tm_clones+0x42>
 4fe:	8b 92 2c 00 00 00    	mov    0x2c(%edx),%edx
 504:	85 d2                	test   %edx,%edx
 506:	74 0a                	je     512 <register_tm_clones+0x42>
 508:	83 ec 08             	sub    $0x8,%esp
 50b:	50                   	push   %eax
 50c:	51                   	push   %ecx
 50d:	ff d2                	call   *%edx
 50f:	83 c4 10             	add    $0x10,%esp
 512:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 515:	c9                   	leave  
 516:	c3                   	ret    
 517:	89 f6                	mov    %esi,%esi
 519:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00000520 <__do_global_dtors_aux>:
__do_global_dtors_aux():
 520:	55                   	push   %ebp
 521:	89 e5                	mov    %esp,%ebp
 523:	53                   	push   %ebx
 524:	e8 57 ff ff ff       	call   480 <__x86.get_pc_thunk.bx>
 529:	81 c3 a7 1a 00 00    	add    $0x1aa7,%ebx
 52f:	83 ec 04             	sub    $0x4,%esp
 532:	80 bb 38 00 00 00 00 	cmpb   $0x0,0x38(%ebx)
 539:	75 27                	jne    562 <__do_global_dtors_aux+0x42>
 53b:	8b 83 20 00 00 00    	mov    0x20(%ebx),%eax
 541:	85 c0                	test   %eax,%eax
 543:	74 11                	je     556 <__do_global_dtors_aux+0x36>
 545:	83 ec 0c             	sub    $0xc,%esp
 548:	ff b3 34 00 00 00    	pushl  0x34(%ebx)
 54e:	e8 dd fe ff ff       	call   430 <__cxa_finalize@plt>
 553:	83 c4 10             	add    $0x10,%esp
 556:	e8 35 ff ff ff       	call   490 <deregister_tm_clones>
 55b:	c6 83 38 00 00 00 01 	movb   $0x1,0x38(%ebx)
 562:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 565:	c9                   	leave  
 566:	c3                   	ret    
 567:	89 f6                	mov    %esi,%esi
 569:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00000570 <frame_dummy>:
frame_dummy():
 570:	55                   	push   %ebp
 571:	89 e5                	mov    %esp,%ebp
 573:	5d                   	pop    %ebp
 574:	e9 57 ff ff ff       	jmp    4d0 <register_tm_clones>

00000579 <__x86.get_pc_thunk.dx>:
__x86.get_pc_thunk.dx():
 579:	8b 14 24             	mov    (%esp),%edx
 57c:	c3                   	ret    

0000057d <main>:
main():
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:9
int msb(int x);
void print_binary(int n);

//Please do not modify main().
//All your changes should be made within msb()
int main(int argc, char **argv) {
 57d:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 581:	83 e4 f0             	and    $0xfffffff0,%esp
 584:	ff 71 fc             	pushl  -0x4(%ecx)
 587:	55                   	push   %ebp
 588:	89 e5                	mov    %esp,%ebp
 58a:	53                   	push   %ebx
 58b:	51                   	push   %ecx
 58c:	83 ec 10             	sub    $0x10,%esp
 58f:	e8 ec fe ff ff       	call   480 <__x86.get_pc_thunk.bx>
 594:	81 c3 3c 1a 00 00    	add    $0x1a3c,%ebx
 59a:	89 c8                	mov    %ecx,%eax
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:10
	if (argc<2) {
 59c:	83 38 01             	cmpl   $0x1,(%eax)
 59f:	7f 1f                	jg     5c0 <main+0x43>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:11
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
 5a1:	8b 40 04             	mov    0x4(%eax),%eax
 5a4:	8b 00                	mov    (%eax),%eax
 5a6:	83 ec 08             	sub    $0x8,%esp
 5a9:	50                   	push   %eax
 5aa:	8d 83 50 e8 ff ff    	lea    -0x17b0(%ebx),%eax
 5b0:	50                   	push   %eax
 5b1:	e8 3a fe ff ff       	call   3f0 <printf@plt>
 5b6:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:12
		return 1;
 5b9:	b8 01 00 00 00       	mov    $0x1,%eax
 5be:	eb 6d                	jmp    62d <main+0xb0>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:14
	}
	int x=atoi(argv[1]);
 5c0:	8b 40 04             	mov    0x4(%eax),%eax
 5c3:	83 c0 04             	add    $0x4,%eax
 5c6:	8b 00                	mov    (%eax),%eax
 5c8:	83 ec 0c             	sub    $0xc,%esp
 5cb:	50                   	push   %eax
 5cc:	e8 4f fe ff ff       	call   420 <atoi@plt>
 5d1:	83 c4 10             	add    $0x10,%esp
 5d4:	89 45 f4             	mov    %eax,-0xc(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:15
	printf("X= "); 
 5d7:	83 ec 0c             	sub    $0xc,%esp
 5da:	8d 83 7c e8 ff ff    	lea    -0x1784(%ebx),%eax
 5e0:	50                   	push   %eax
 5e1:	e8 0a fe ff ff       	call   3f0 <printf@plt>
 5e6:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:16
	print_binary(x); 
 5e9:	83 ec 0c             	sub    $0xc,%esp
 5ec:	ff 75 f4             	pushl  -0xc(%ebp)
 5ef:	e8 3b 01 00 00       	call   72f <print_binary>
 5f4:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:17
	printf("\n");
 5f7:	83 ec 0c             	sub    $0xc,%esp
 5fa:	6a 0a                	push   $0xa
 5fc:	e8 0f fe ff ff       	call   410 <putchar@plt>
 601:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:18
	printf("The most significant bit of %d is at position %d\n",x,msb(x));
 604:	83 ec 0c             	sub    $0xc,%esp
 607:	ff 75 f4             	pushl  -0xc(%ebp)
 60a:	e8 28 00 00 00       	call   637 <msb>
 60f:	83 c4 10             	add    $0x10,%esp
 612:	83 ec 04             	sub    $0x4,%esp
 615:	50                   	push   %eax
 616:	ff 75 f4             	pushl  -0xc(%ebp)
 619:	8d 83 80 e8 ff ff    	lea    -0x1780(%ebx),%eax
 61f:	50                   	push   %eax
 620:	e8 cb fd ff ff       	call   3f0 <printf@plt>
 625:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:19
	return 0;
 628:	b8 00 00 00 00       	mov    $0x0,%eax
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:20
}
 62d:	8d 65 f8             	lea    -0x8(%ebp),%esp
 630:	59                   	pop    %ecx
 631:	5b                   	pop    %ebx
 632:	5d                   	pop    %ebp
 633:	8d 61 fc             	lea    -0x4(%ecx),%esp
 636:	c3                   	ret    

00000637 <msb>:
msb():
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:22

int msb(int x) {
 637:	55                   	push   %ebp
 638:	89 e5                	mov    %esp,%ebp
 63a:	56                   	push   %esi
 63b:	53                   	push   %ebx
 63c:	83 ec 20             	sub    $0x20,%esp
 63f:	e8 3c fe ff ff       	call   480 <__x86.get_pc_thunk.bx>
 644:	81 c3 8c 19 00 00    	add    $0x198c,%ebx
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:23
	if (x==0) return -1;
 64a:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 64e:	75 0a                	jne    65a <msb+0x23>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:23 (discriminator 1)
 650:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 655:	e9 ce 00 00 00       	jmp    728 <msb+0xf1>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:34
	//                        ^
	//                        |
	//                        ep
	// in which * is a wild card which could be 0 or 1                   
	int w, ep, hw;
	w=31; // Number of bits that might contain most significant 1
 65a:	c7 45 e4 1f 00 00 00 	movl   $0x1f,-0x1c(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:35
	ep=0; // Rightmost bit that might contain most significant 1
 661:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:36
	hw = (w / 2) + 1;
 668:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 66b:	89 c2                	mov    %eax,%edx
 66d:	c1 ea 1f             	shr    $0x1f,%edx
 670:	01 d0                	add    %edx,%eax
 672:	d1 f8                	sar    %eax
 674:	83 c0 01             	add    $0x1,%eax
 677:	89 45 ec             	mov    %eax,-0x14(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:37
	while((w - ep) > 1) { //Narrow down to a single bit
 67a:	e9 97 00 00 00       	jmp    716 <msb+0xdf>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:48
		//If the left half of the range has a one bit, focus on only the left half
		//else focus on only the right half
		//TODO: You have ruled out either the left half of the range or the right half of the range
		//set up ep and w accordingly

		int mid = (w + ep + 1) / 2;
 67f:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 682:	8b 45 e8             	mov    -0x18(%ebp),%eax
 685:	01 d0                	add    %edx,%eax
 687:	83 c0 01             	add    $0x1,%eax
 68a:	89 c2                	mov    %eax,%edx
 68c:	c1 ea 1f             	shr    $0x1f,%edx
 68f:	01 d0                	add    %edx,%eax
 691:	d1 f8                	sar    %eax
 693:	89 45 f0             	mov    %eax,-0x10(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:49
		int mask = (1 << w) - (1 << mid);
 696:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 699:	ba 01 00 00 00       	mov    $0x1,%edx
 69e:	89 c1                	mov    %eax,%ecx
 6a0:	d3 e2                	shl    %cl,%edx
 6a2:	8b 45 f0             	mov    -0x10(%ebp),%eax
 6a5:	be 01 00 00 00       	mov    $0x1,%esi
 6aa:	89 c1                	mov    %eax,%ecx
 6ac:	d3 e6                	shl    %cl,%esi
 6ae:	89 f0                	mov    %esi,%eax
 6b0:	29 c2                	sub    %eax,%edx
 6b2:	89 d0                	mov    %edx,%eax
 6b4:	89 45 f4             	mov    %eax,-0xc(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:51
	
		printf("M= "); print_binary(mask); printf(" hw=%d ep=%d\n",hw,ep);
 6b7:	83 ec 0c             	sub    $0xc,%esp
 6ba:	8d 83 b2 e8 ff ff    	lea    -0x174e(%ebx),%eax
 6c0:	50                   	push   %eax
 6c1:	e8 2a fd ff ff       	call   3f0 <printf@plt>
 6c6:	83 c4 10             	add    $0x10,%esp
 6c9:	83 ec 0c             	sub    $0xc,%esp
 6cc:	ff 75 f4             	pushl  -0xc(%ebp)
 6cf:	e8 5b 00 00 00       	call   72f <print_binary>
 6d4:	83 c4 10             	add    $0x10,%esp
 6d7:	83 ec 04             	sub    $0x4,%esp
 6da:	ff 75 e8             	pushl  -0x18(%ebp)
 6dd:	ff 75 ec             	pushl  -0x14(%ebp)
 6e0:	8d 83 b6 e8 ff ff    	lea    -0x174a(%ebx),%eax
 6e6:	50                   	push   %eax
 6e7:	e8 04 fd ff ff       	call   3f0 <printf@plt>
 6ec:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:52
		hw = hw / 2;
 6ef:	8b 45 ec             	mov    -0x14(%ebp),%eax
 6f2:	89 c2                	mov    %eax,%edx
 6f4:	c1 ea 1f             	shr    $0x1f,%edx
 6f7:	01 d0                	add    %edx,%eax
 6f9:	d1 f8                	sar    %eax
 6fb:	89 45 ec             	mov    %eax,-0x14(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:53
		if((mask & x) > 0)
 6fe:	8b 45 f4             	mov    -0xc(%ebp),%eax
 701:	23 45 08             	and    0x8(%ebp),%eax
 704:	85 c0                	test   %eax,%eax
 706:	7e 08                	jle    710 <msb+0xd9>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:55
		{
			ep = mid;
 708:	8b 45 f0             	mov    -0x10(%ebp),%eax
 70b:	89 45 e8             	mov    %eax,-0x18(%ebp)
 70e:	eb 06                	jmp    716 <msb+0xdf>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:60
		}

		else
		{
			w = mid;
 710:	8b 45 f0             	mov    -0x10(%ebp),%eax
 713:	89 45 e4             	mov    %eax,-0x1c(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:37
	while((w - ep) > 1) { //Narrow down to a single bit
 716:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 719:	2b 45 e8             	sub    -0x18(%ebp),%eax
 71c:	83 f8 01             	cmp    $0x1,%eax
 71f:	0f 8f 5a ff ff ff    	jg     67f <msb+0x48>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:64
		}

	}
	return ep;
 725:	8b 45 e8             	mov    -0x18(%ebp),%eax
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:65
}
 728:	8d 65 f8             	lea    -0x8(%ebp),%esp
 72b:	5b                   	pop    %ebx
 72c:	5e                   	pop    %esi
 72d:	5d                   	pop    %ebp
 72e:	c3                   	ret    

0000072f <print_binary>:
print_binary():
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:67
//Do not modify print_binary
void print_binary(int n) {
 72f:	55                   	push   %ebp
 730:	89 e5                	mov    %esp,%ebp
 732:	53                   	push   %ebx
 733:	83 ec 14             	sub    $0x14,%esp
 736:	e8 45 fd ff ff       	call   480 <__x86.get_pc_thunk.bx>
 73b:	81 c3 95 18 00 00    	add    $0x1895,%ebx
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:69
	int i;
	for(i=31;i>=0;i--) {
 741:	c7 45 f4 1f 00 00 00 	movl   $0x1f,-0xc(%ebp)
 748:	eb 46                	jmp    790 <print_binary+0x61>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:70
		printf("%c",(n&1<<i)?'1':'0');
 74a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 74d:	8b 55 08             	mov    0x8(%ebp),%edx
 750:	89 c1                	mov    %eax,%ecx
 752:	d3 fa                	sar    %cl,%edx
 754:	89 d0                	mov    %edx,%eax
 756:	83 e0 01             	and    $0x1,%eax
 759:	85 c0                	test   %eax,%eax
 75b:	74 07                	je     764 <print_binary+0x35>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:70 (discriminator 1)
 75d:	b8 31 00 00 00       	mov    $0x31,%eax
 762:	eb 05                	jmp    769 <print_binary+0x3a>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:70 (discriminator 2)
 764:	b8 30 00 00 00       	mov    $0x30,%eax
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:70 (discriminator 4)
 769:	83 ec 0c             	sub    $0xc,%esp
 76c:	50                   	push   %eax
 76d:	e8 9e fc ff ff       	call   410 <putchar@plt>
 772:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:71 (discriminator 4)
		if (0==i%4) printf(" ");
 775:	8b 45 f4             	mov    -0xc(%ebp),%eax
 778:	83 e0 03             	and    $0x3,%eax
 77b:	85 c0                	test   %eax,%eax
 77d:	75 0d                	jne    78c <print_binary+0x5d>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:71 (discriminator 1)
 77f:	83 ec 0c             	sub    $0xc,%esp
 782:	6a 20                	push   $0x20
 784:	e8 87 fc ff ff       	call   410 <putchar@plt>
 789:	83 c4 10             	add    $0x10,%esp
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:69 (discriminator 2)
	for(i=31;i>=0;i--) {
 78c:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:69 (discriminator 1)
 790:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 794:	79 b4                	jns    74a <print_binary+0x1b>
/home/jdoe/CS232_new_dir/CS232/lab7/task1/msb.c:73
	}
}
 796:	90                   	nop
 797:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 79a:	c9                   	leave  
 79b:	c3                   	ret    
 79c:	66 90                	xchg   %ax,%ax
 79e:	66 90                	xchg   %ax,%ax

000007a0 <__libc_csu_init>:
__libc_csu_init():
 7a0:	55                   	push   %ebp
 7a1:	57                   	push   %edi
 7a2:	56                   	push   %esi
 7a3:	53                   	push   %ebx
 7a4:	e8 d7 fc ff ff       	call   480 <__x86.get_pc_thunk.bx>
 7a9:	81 c3 27 18 00 00    	add    $0x1827,%ebx
 7af:	83 ec 0c             	sub    $0xc,%esp
 7b2:	8b 6c 24 28          	mov    0x28(%esp),%ebp
 7b6:	8d b3 04 ff ff ff    	lea    -0xfc(%ebx),%esi
 7bc:	e8 fb fb ff ff       	call   3bc <_init>
 7c1:	8d 83 00 ff ff ff    	lea    -0x100(%ebx),%eax
 7c7:	29 c6                	sub    %eax,%esi
 7c9:	c1 fe 02             	sar    $0x2,%esi
 7cc:	85 f6                	test   %esi,%esi
 7ce:	74 25                	je     7f5 <__libc_csu_init+0x55>
 7d0:	31 ff                	xor    %edi,%edi
 7d2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 7d8:	83 ec 04             	sub    $0x4,%esp
 7db:	55                   	push   %ebp
 7dc:	ff 74 24 2c          	pushl  0x2c(%esp)
 7e0:	ff 74 24 2c          	pushl  0x2c(%esp)
 7e4:	ff 94 bb 00 ff ff ff 	call   *-0x100(%ebx,%edi,4)
 7eb:	83 c7 01             	add    $0x1,%edi
 7ee:	83 c4 10             	add    $0x10,%esp
 7f1:	39 fe                	cmp    %edi,%esi
 7f3:	75 e3                	jne    7d8 <__libc_csu_init+0x38>
 7f5:	83 c4 0c             	add    $0xc,%esp
 7f8:	5b                   	pop    %ebx
 7f9:	5e                   	pop    %esi
 7fa:	5f                   	pop    %edi
 7fb:	5d                   	pop    %ebp
 7fc:	c3                   	ret    
 7fd:	8d 76 00             	lea    0x0(%esi),%esi

00000800 <__libc_csu_fini>:
__libc_csu_fini():
 800:	f3 c3                	repz ret 

Disassembly of section .fini:

00000804 <_fini>:
_fini():
 804:	53                   	push   %ebx
 805:	83 ec 08             	sub    $0x8,%esp
 808:	e8 73 fc ff ff       	call   480 <__x86.get_pc_thunk.bx>
 80d:	81 c3 c3 17 00 00    	add    $0x17c3,%ebx
 813:	83 c4 08             	add    $0x8,%esp
 816:	5b                   	pop    %ebx
 817:	c3                   	ret    
