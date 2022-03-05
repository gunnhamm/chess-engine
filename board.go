package board
import "fmt"

const empty = 0
const pawn = 2
const rook = 3
const knight = 4
const bishop = 5
const queen = 6
const king = 7



type board [12][12] int
type move struct {
	startX int
	startY int

	endX int
	endY int

}

func generateMoves(board) []move {
	
}