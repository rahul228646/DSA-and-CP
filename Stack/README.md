# Notes

## Monotoni Stack
    The word "monotonic" means a list or a function is either always increasing, or always decreasing. In that case, a "monotonic stack" or a "monotonic deque" is a stack or a deque that has this property.

    Monotonic stack is like a regular stack with one key distinction in the push operation: Before we push a new element onto the stack, we first check if adding it breaks the monotonic condition. If it does, then we pop the top element off the stack until pushing the new element no longer breaks the monotonic condition.


