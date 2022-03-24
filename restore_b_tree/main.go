package main

import (
	"fmt"
)

type Node struct {
	Left *Node
	Right *Node
	Val int
}

func restore(first, mid []int) *Node {	
	if len(first) == 0 || len(mid) == 0 {
		return nil
	}


	head := &Node{
		Val: first[0],
	}
	headPos := 0
	for i:=0; i<len(mid); i++ {
		if head.Val == mid[i] {
			headPos = i
			break
		}
	}

	mLeftNodes := mid[:headPos]
	var mRightNodes []int
	if headPos < len(mid)-1 {
		mRightNodes = mid[headPos+1:]
	}

	var fRightNodes []int
	fLeftNodes := first[1:headPos+1]
	if headPos+1 < len(first) {
		fRightNodes = first[headPos+1:]
	}

	head.Left = restore(fLeftNodes, mLeftNodes)
	head.Right = restore(fRightNodes, mRightNodes)

	return head
}

func midIter(head *Node) {
	if head.Left != nil {
		midIter(head.Left)
	}

	fmt.Println(head.Val)

	if head.Right != nil {
		midIter(head.Right)
	}
}


func main()  {
	first := []int{1,2,4,7,3,5,6,8}
	mid := []int{4,7,2,1,5,3,8,6}

	head := restore(first, mid)

	midIter(head)
}