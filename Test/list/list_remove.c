/*
 *   MIT License
 *
 *   Copyright (c) 2017-2018 Sidhin S Thomas
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <stdio.h>
#include <generic/list.h>

int main() {
    gList *list = gListCreate(sizeof(int));
    for (int i = 0; i < 10; ++i) {
        if (gListAddItem(list, &i) == -1) {
            return gErrorCode;
        }
        for (unsigned int j = 0; j <= i; ++j) {
            printf("%d ", *(int *) gListGetItem(list, j));
        }
        printf("\n");
    }
    for ( int i = 9; i >= 0; --i) {

        if (gListRemoveItem(list, i) == -1) {
            return gErrorCode;
        }
        gListIterator iter = gListGetIterator(list);
        while (gListGetIteratorData(iter) != NULL) {
            printf("%d ", *(int *) gListGetIteratorData(iter));
            fflush(stdout);
            gListIterate(iter);
        }
        printf("\n");
    }
    gListIterator iter = gListGetIterator(list);
    while (*iter != NULL) {
        printf("%d ", *(int *) gListGetIteratorData(iter));
    }
    return 0;
}