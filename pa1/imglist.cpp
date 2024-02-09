/**
 *  @file        imglist.cpp
 *  @description Contains partial implementation of ImgList class
 *               for CPSC 221 PA1
 *               Function bodies to be completed by student
 * 
 *  THIS FILE WILL BE SUBMITTED
 */

#include "imglist.h"

#include <math.h> // provides fmax, fmin, and fabs functions

/*********************
* CONSTRUCTORS, ETC. *
*********************/

/**
 * Default constructor. Makes an empty list
 */
ImgList::ImgList() {
    // set appropriate values for all member attributes here
    northwest = NULL;
    southeast = NULL;
	
}

/**
 * Creates a list from image data
 * @pre img has dimensions of at least 1x1
 */
ImgList::ImgList(PNG& img) {
    // build the linked node structure and set the member attributes appropriately
    
    signed int dimensionX = img.width();
    signed int dimensionY = img.height();
    ImgNode* northOfPrev = NULL;
    ImgNode* northOfCurr = NULL;
    ImgNode* curr = NULL;
    ImgNode* west_new = NULL;
    ImgNode* PrevStart = NULL;
//mangement of 1 node

    if (dimensionX == 1 || dimensionY ==1)
    {
        northwest = new ImgNode();
        southeast = northwest;
    }

    northwest = new ImgNode();
    northOfPrev = northwest;
    PrevStart = new ImgNode();


    for (int y = 0; y < dimensionY; y++)
    {

        if (y == 0) {
            west_new = northOfPrev;
            ImgNode* east = PrevStart;
            west_new->colour = (*img.getPixel(0,0));
            east->colour = (*img.getPixel(dimensionX -1, 0));
        for (int x = 1; x < dimensionX -1; x++)
        {
            curr = new ImgNode();
            curr->colour = (*img.getPixel(x,y));

            curr->west = west_new;
            curr->east = east;
            west_new = curr;
            

        }
        } else{
            west_new = new ImgNode();
            west_new->colour = (*img.getPixel(0,y));
            west_new->north = northOfPrev;
            northOfPrev->south = west_new;
            ImgNode* east = new ImgNode();
            east->colour = (*img.getPixel(dimensionX -1, y));
            east->north = PrevStart;
            PrevStart->south = east;
            northOfCurr = northOfPrev->east;

            for (int x = 0; x < dimensionX -1; x++)
            {
                curr = new ImgNode();
                curr->colour =  (*img.getPixel(x,y));
                curr->west = west_new;
                curr->east = east;
                east->west = curr;
                curr->north = northOfCurr;
                northOfCurr->south = curr;

                west_new = west_new->east;
                northOfCurr = northOfCurr->east;
            }

            northOfPrev = northOfPrev->south;
            PrevStart = PrevStart->south;
            
        }
        
    }
    southeast = PrevStart;
}

/************
* ACCESSORS *
************/

/**
 * Returns the horizontal dimension of this list (counted in nodes)
 * Note that every row will contain the same number of nodes, whether or not
 *   the list has been carved.
 * We expect your solution to take linear time in the number of nodes in the
 *   x dimension.
 */
unsigned int ImgList::GetDimensionX() const {
    // replace the following line with your implementation
    return -1;
}

/**
 * Returns the vertical dimension of the list (counted in nodes)
 * It is useful to know/assume that the grid will never have nodes removed
 *   from the first or last columns. The returned value will thus correspond
 *   to the height of the PNG image from which this list was constructed.
 * We expect your solution to take linear time in the number of nodes in the
 *   y dimension.
 */
unsigned int ImgList::GetDimensionY() const {
    // replace the following line with your implementation
    return -1;
}

/**
 * Returns the horizontal dimension of the list (counted in original pixels, pre-carving)
 * The returned value will thus correspond to the width of the PNG image from
 *   which this list was constructed.
 * We expect your solution to take linear time in the number of nodes in the
 *   x dimension.
 */
unsigned int ImgList::GetDimensionFullX() const {
    // replace the following line with your implementation

    return -1;
}

/**
 * Returns a pointer to the node which best satisfies the specified selection criteria.
 * The first and last nodes in the row cannot be returned.
 * @pre rowstart points to a row with at least 3 physical nodes
 * @pre selectionmode is an integer in the range [0,1]
 * @param rowstart - pointer to the first node in a row
 * @param selectionmode - criterion used for choosing the node to return
 *          0: minimum "brightness" across row, not including extreme left or right nodes
 *          1: node with minimum total of "colour difference" with its left neighbour and with its right neighbour.
 *        In the (likely) case of multiple candidates that best match the criterion,
 *        the left-most node satisfying the criterion (excluding the row's starting node)
 *        will be returned.
 * A note about "brightness" and "colour difference":
 * For PA1, "brightness" will be the sum over the RGB colour channels, multiplied by alpha.
 * "colour difference" between two pixels can be determined
 * using the "distanceTo" function found in RGBAPixel.h.
 */
ImgNode* ImgList::SelectNode(ImgNode* rowstart, int selectionmode) {
    // add your implementation below
    if (selectionmode){
        //colour deference

    } else {
        //brightness

    }
  
    return NULL;
}

/**
 * Renders this list's pixel data to a PNG, with or without filling gaps caused by carving.
 * @pre fillmode is an integer in the range of [0,2]
 * @param fillgaps - whether or not to fill gaps caused by carving
 *          false: render one pixel per node, ignores fillmode
 *          true: render the full width of the original image,
 *                filling in missing nodes using fillmode
 * @param fillmode - specifies how to fill gaps
 *          0: solid, uses the same colour as the node at the left of the gap
 *          1: solid, using the averaged values (all channels) of the nodes at the left and right of the gap
 *          2: linear gradient between the colour (all channels) of the nodes at the left and right of the gap
 *             e.g. a gap of width 1 will be coloured with 1/2 of the difference between the left and right nodes
 *             a gap of width 2 will be coloured with 1/3 and 2/3 of the difference
 *             a gap of width 3 will be coloured with 1/4, 2/4, 3/4 of the difference, etc.
 *             Like fillmode 1, use the smaller difference interval for hue,
 *             and the smaller-valued average for diametric hues
 */
PNG ImgList::Render(bool fillgaps, int fillmode) const {
    // Add/complete your implementation below
  
    PNG outpng; //this will be returned later. Might be a good idea to resize it at some point.
  
    return outpng;
}

/************
* MODIFIERS *
************/

/**
 * Removes exactly one node from each row in this list, according to specified criteria.
 * The first and last nodes in any row cannot be carved.
 * @pre this list has at least 3 nodes in each row
 * @pre selectionmode is an integer in the range [0,1]
 * @param selectionmode - see the documentation for the SelectNode function.
 * @param this list has had one node removed from each row. Neighbours of the created
 *       gaps are linked appropriately, and their skip values are updated to reflect
 *       the size of the gap.
 */
void ImgList::Carve(int selectionmode) {
    // add your implementation here
    ImgNode* startOfRow = northwest;

    if (!startOfRow)
        {
            return;
            
        }

    while (1)
    {
        
        
        ImgNode* nodeDelete = SelectNode(startOfRow, selectionmode);

        nodeDelete->east->west = nodeDelete->west;
        nodeDelete->west->east = nodeDelete->east;
        nodeDelete->west->skipright = nodeDelete->west->skipright + nodeDelete->skipright + 1;
        nodeDelete->east->skipleft = nodeDelete->east->skipleft + nodeDelete->skipleft + 1;

        if(nodeDelete->north){
            nodeDelete->north->south = nodeDelete->south;

            nodeDelete->north->skipdown = nodeDelete->north->skipdown + nodeDelete->skipdown + 1;

        }

        if(nodeDelete->south){

            nodeDelete->south->north = nodeDelete->north;

            nodeDelete->south->skipup = nodeDelete->south->skipup + nodeDelete->skipup + 1;

        }

        delete nodeDelete;
        nodeDelete = NULL;

        if(!startOfRow->south){
            return;
        }

        startOfRow = startOfRow->south;
    }
    

	
}

// note that a node on the boundary will never be selected for removal
/**
 * Removes "rounds" number of nodes (up to a maximum of node width - 2) from each row,
 * based on specific selection criteria.
 * Note that this should remove one node from every row, repeated "rounds" times,
 * and NOT remove "rounds" nodes from one row before processing the next row.
 * @pre selectionmode is an integer in the range [0,1]
 * @param rounds - number of nodes to remove from each row
 *        If rounds exceeds node width - 2, then remove only node width - 2 nodes from each row.
 *        i.e. Ensure that the final list has at least two nodes in each row.
 * @post this list has had "rounds" nodes removed from each row. Neighbours of the created
 *       gaps are linked appropriately, and their skip values are updated to reflect
 *       the size of the gap.
 */
void ImgList::Carve(unsigned int rounds, int selectionmode) {
    // add your implementation here
    int x_removal = GetDimensionX() - 2;
    ImgNode* startOfRow = northwest;

    if (rounds <= x_removal)
    {
        x_removal = rounds;
        
    }  

    for(int x = 1; x <= x_removal; x++)
    {
        Carve(selectionmode);  
    
    }


}


/*
 * Helper function deallocates all heap memory associated with this list,
 * puts this list into an "empty" state. Don't forget to set your member attributes!
 * @post this list has no currently allocated nor leaking heap memory,
 *       member attributes have values consistent with an empty list.
 */
void ImgList::Clear() {
    ImgNode* curr;
    ImgNode* startCurr;

    startCurr = northwest;
    curr = startCurr;

    while(startCurr){
        while (curr)
        {
            ImgNode* prev = curr;
            curr = curr->east;
            delete prev;
            prev = NULL;
        }
        startCurr = startCurr->south;
        
        
    }

    startCurr = NULL;
    curr = NULL;
    
	
}

/**
 * Helper function copies the contents of otherlist and sets this list's attributes appropriately
 * @pre this list is empty
 * @param otherlist - list whose contents will be copied
 * @post this list has contents copied from by physically separate from otherlist
 */
void ImgList::Copy(const ImgList& otherlist) {
    // add your implementation here
	
}

/*************************************************************************************************
* IF YOU DEFINED YOUR OWN PRIVATE FUNCTIONS IN imglist-private.h, YOU MAY ADD YOUR IMPLEMENTATIONS BELOW *
*************************************************************************************************/

