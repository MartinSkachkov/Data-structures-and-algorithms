Data Structures

Homework 5

**Mostafa S. Ibrahim ![](Aspose.Words.11d40658-2d74-4eef-b85e-048fd3fcea80.001.jpeg)**

*Teaching, Training and Coaching since more than a decade!* 

*Artificial Intelligence & Computer Vision Researcher* 

*PhD* from Simon Fraser University - Canada *Bachelor / Msc* from Cairo University - Egypt Ex-(Software Engineer / ICPC World Finalist) 

Problem #1: Symmetric [Tree](https://leetcode.com/problems/symmetric-tree/)![](Aspose.Words.11d40658-2d74-4eef-b85e-048fd3fcea80.002.png)

- A tree is symmetric if it mirror around its center
- Observe 3rd level ![](Aspose.Words.11d40658-2d74-4eef-b85e-048fd3fcea80.003.jpeg)
- 5 6 7 8 
- Then 
- 8 7 6 5 
- A tree is mirror if root->left & root->right are mirror
- Given a tree, develop 2 methods
- 1) Based on recursion to compare subtrees together
  - bool is\_mirror(BinaryTree\* first, BinaryTree\* second)
- 2) Based on parenthesize a tree then compare the left & right branches directly
- What is your time complexity?


Problem #2: Flip [Equivalent](https://leetcode.com/problems/flip-equivalent-binary-trees/) Binary Trees

- bool is\_flip\_equiv(BinaryTree\* other)
- Given a tree, can we make some swappings to some left/right children to convert it to another tree?

Img [src](https://leetcode.com/problems/flip-equivalent-binary-trees/)![](Aspose.Words.11d40658-2d74-4eef-b85e-048fd3fcea80.004.jpeg)

Problem #3: Print all duplicate subtrees ![](Aspose.Words.11d40658-2d74-4eef-b85e-048fd3fcea80.005.jpeg)

- Given a binary tree, print all duplicate subtrees of 2+ nodes. 
- Duplicates = Same structure & values
- There are 3 sub-trees
- Root 2, Root 6, Root 8
- Output parentheses
- (2(3()())())
- (6(7()())(8()(9()())))
- (8()(9()()))

**“Acquire knowledge and impart it to the people.” “Seek knowledge from the Cradle to the Grave.”**
