In the third and sixth line of the code snippet, the 'currPathSteps' parameter is reset to 1. This is because we're starting a new zigzag path from the current node in the opposite direction of the previous step.

If 'leftDir' is true, then the previous step was a left move, so the new path will start with a right move from the current node. Therefore, we reset 'currPathSteps' to 1 before calling 'solve' on the right child node.

If 'leftDir' is false, then the previous step was a right move, so the new path will start with a left move from the current node. Therefore, we reset 'currPathSteps' to 1 before calling 'solve' on the left child node.

By resetting 'currPathSteps' to 1, we ensure that we only count the steps taken in the current zigzag path and not any steps from the previous path. This allows us to correctly calculate the length of the zigzag path from the current node.
