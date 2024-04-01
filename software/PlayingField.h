#ifndef Playing_Field_H
#define Playing_Field_H

#include <map>
#include <vector>

#include "Block.h"
#include "Vector2D.h"
#include "optional.hpp"
#include "TetrisProperties.h"

/**
 * @brief Class representing the playing field with blocks in Tetris.
 * 
 * The PlayingField class manages the state of the playing field in Tetris, including the positions
 * of blocks and operations such as checking if a position is empty, inserting blocks, clearing lines,
 * and managing floating blocks.
 */
class PlayingField {
public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the playing field with empty positions.
     */
    PlayingField();        
  
    /**
     * @brief Checks if a given position on the playing field is empty.
     * 
     * @param position The position to check.
     * @return True if the position is empty, false otherwise.
     */
    bool isEmpty(Vector2D position) const;

    /**
     * @brief Checks if a list of positions on the playing field are all empty.
     * 
     * @param positions The list of positions to check.
     * @return True if all positions are empty, false otherwise.
     */
    bool isEmptyPositions(std::vector<Vector2D> positions);

    /**
     * @brief Checks if all positions below a list of positions on the playing field are empty.
     * 
     * @param positions The list of positions to check.
     * @return True if all positions below are empty, false otherwise.
     */
    bool isEmptyPositionsBelow(std::vector<Vector2D> positions);

    /**
     * @brief Inserts blocks into the playing field.
     * 
     * @param blocks The list of blocks to insert.
     */
    void insertBlocks(std::vector<Block> blocks);

    /**
     * @brief Clears a single x-axis line on the playing field.
     * 
     * @param line The line number to clear.
     */
    void clearLine(int line);

    /**
     * @brief Clears multiple lines on the playing field.
     * 
     * @param lines The list of line numbers to clear.
     */
    void clearLines(std::vector<int> lines);

    /**
     * @brief Drops floating blocks on the playing field.
     * 
     * Used when we clear a line, because then the above lines will levitate.
     */
    void dropFloatingBlocks();

    /**
     * @brief Swaps the positions of two x-axis lines on the playing field.
     * 
     * @param i The line number of the first line.
     * @param j The line number of the second line.
     */
    void swapTwoLines(int i, int j);

    /**
     * @brief Retrieves the block at a given position on the playing field.
     * 
     * @param position The position of the block.
     * @return The block at the specified position.
     */
    Block getFromPosition(Vector2D position) const;

    /**
     * @brief Retrieves all positions with blocks on the playing field.
     * 
     * @return A vector containing all positions with blocks.
     */
    std::vector<Vector2D> getAllPositions() const;

    /**
     * @brief Checks if a given x-axis line on the playing field is empty.
     * 
     * @param lineNo The line number to check.
     * @return True if the line is empty, false otherwise.
     */
    bool lineIsEmpty(int lineNo);

private:
    std::map < Vector2D, tl::optional<Block> > fields;
};

#endif