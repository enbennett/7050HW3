#include "cs4050.h"
#include "Bellman-Ford.h"
#include "Util.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

void ShortestPaths(
	Vertex * V, int countV, 
	Edge * E, int countE, 
	int t,
	float d[],
	int successor[])
{ 
	// For each vertices initialize d to infinity (in this case INT_MAX)
	for(int i = 0; i < countV; i++)
	{
		d[i] = FLT_MAX;
		successor[i] = -1;
	}
	// Initialize terminal d to 0
	d[t] = 0;

	// Create boolean so we can check whether or not any value of d[] has been changed
	bool update = true;

	// For V-1 vertices
	for(int i = 0; i < countV-1; i++)
	{
		// begin with boolean set to false
		update = false;

		//printf("\nOuter for loop at vertice %d\n", V[i].number);

		// for all vertices
		for(int i = 0; i < countV; i++)
		{	
			//printf("\nInner for loop at vertice %d\n", V[i].number);

			PAdjacency temp = V[i].list; // create temp adjacency to go through edges of each vertice
			while(temp != NULL) // scroll through all of the connecting nodes in adjacency list
			{
				int v = (temp->pEdge->from)-1; // set from vertice
				int w = (temp->pEdge->to)-1; // set to vertice

				//printf("\n On edge from %d to %d with weight %f\n", temp->pEdge->from, temp->pEdge->to, temp->pEdge->weight);
				//printf("\nValue of d[v] is %f and d[w] is %f and successor[v] is %d and successor[w] is %d", d[v], d[w], successor[v], successor[w]);
				
				// compare current d[from] to d[to] + weight of edge
				if(d[v] > (d[w] + (temp->pEdge->weight)))
				{
					//printf("\n inside of if statement (difference is %f) \n", d[v]- (d[w]+ (temp->pEdge->weight)));

					d[v] = (d[w]+ (temp->pEdge->weight)); // if to + weight is less, set d[v] to new value
					successor[v] = w; // successor becomes to vertice
					update = true; // set update to true for boolean check
				}
				temp = temp->next; // go to next edge in vertex
			}
		}
		if(update == false) // if no d[] are changed end loops and return
		{
			return;
		}
	}

	/*
	// Test to check different values
	printf("\nNumbers \n");
	for(int i = 0; i < countV; i++)
	{
		printf(" %i ", V[i].number);
		PAdjacency temp = V[i].list;
        while(temp != NULL) // scroll through all of the connecting nodes in adjacency list
        {
			printf("\nEdge \n");
			printf("From: %i ", temp->pEdge->from);
			printf("To: %i ", temp->pEdge->to);
            temp = temp->next;

        }
		printf("\n");
	}
	*/

}
