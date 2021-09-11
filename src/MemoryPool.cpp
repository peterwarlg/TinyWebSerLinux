//
// Created by perterwarlg on 2021/6/8.
//
//#include "../include/MemoryBlock.h"
#include "../include/MemoryPool.h"
//#include <stdlib.h>
#include <cassert>
#include <iostream>

//每个链的block个数
#define MAX_BLOCKS_PER_BLOCK 1000

MemoryPool *MemoryPool::memoryPoolInstance = nullptr;

int MemoryPool::AlignBytes(int by) {
    assert(by > 0);
    if (by <= 16) return 16;
    int alignedBy = (by + POOLALIGNMENT - 1) & (~(POOLALIGNMENT - 1));
    return alignedBy;
}

MemoryPool::MemoryPool() : block(nullptr), initialBlocks(MAX_BLOCKS_PER_BLOCK) {
}

void *MemoryPool::Alloc(int bytes) {

    _USED_BLOCKS++;
//    printf("\n%s\n", "********************************");
//    std::cout << "Alloc" << std::endl;
//    printf("%s%lu\n", "Total Used Blocks -> ", _USED_BLOCKS);
//    printf("\n%s\n", "********************************");
    int align = AlignBytes(bytes);
    {
        //分配时加锁
        MutexLockGuard MG(mMutex);
        if (nullptr == this->block) {
//            std::cout << "创建第一个Block" << std::endl;
//            std::cout << "blockSIze: " << MAX_BLOCKS_PER_BLOCK << std::endl;
            block = new(initialBlocks, align)MemoryBlock(initialBlocks, align);
            Block* tmp = block->freeBlock;
            block->freeBlock = block->freeBlock->next;
            return (void *) tmp;
        } else {
            if (this->block->freeBlock == nullptr) {
                MemoryBlock *aNewBlock = new(initialBlocks, align)MemoryBlock(initialBlocks, align);
                MemoryBlock *currentBlock = block;
                while (currentBlock->next != nullptr) {
                    currentBlock = currentBlock->next;
                }
                currentBlock->next = aNewBlock;
                aNewBlock->prev = currentBlock;
                block->freeBlock = aNewBlock->freeBlock->next;
                return (void *) (aNewBlock->freeBlock);
            } else {
                Block* tmp = block->freeBlock;
                block->freeBlock = block->freeBlock->next;
//                std::cout << tmp << std::endl;
                return (void *) (tmp);
            }
        }
    }


}

MemoryPool::~MemoryPool() {
    std::cout << "*****析构：~MemoryPool()*****" << std::endl;
    auto head = block;
    auto tail = block;
    while (head->prev != nullptr) {
        head = head->prev;
    }
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    if (head == tail) {
        delete head;
        block = nullptr;
    } else if (head->next == tail) {
        delete head;
        delete tail;
    } else {
        while (head != tail) {
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        delete head;
    }
}

MemoryPool *MemoryPool::fooGetMemoryPoolInstance() {
    if (memoryPoolInstance == nullptr) {
        memoryPoolInstance = new MemoryPool();
    }
    return memoryPoolInstance;
}