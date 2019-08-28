#include "framequeue.h"

FrameQueue::FrameQueue(const unsigned int& _maxSize)
    : frames(), maxSize(_maxSize), mutex(), waitCondition()
{

}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      实现清空队列
 */
void FrameQueue::makeEmpty()
{
    QMutexLocker locker(&this->mutex);
    while (!this->frames.empty())
    {
        AVFrame* tempFrame = this->frames.front();
        this->frames.pop();
        av_frame_free(&tempFrame);
    }
    cout << "make the frames empty successfully" << endl;
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      析构队列中所有剩余的frames, 注意通过手动调用 makeEmpty 实现
 */
FrameQueue::~FrameQueue()
{

}

/**
 * @author       ParanoidRoot
 * @method       FrameQueue::getSize()
 * @param        void
 * @return       队列的大小
 * @description
 */
unsigned int FrameQueue::getSize() const
{
    return this->frames.size();  // 注意只限制使用前面的int大小
}

unsigned int FrameQueue::getMaxSize() const
{
    return maxSize;
}

/**
 * @author       ParanoidRoot
 * @method       FrameQueue::enQueue
 * @param        所要加入的frame
 * @return       是否加入成功
 * @details      ...
 * @bug          不知道要不要使用线成的mutex
 */
bool FrameQueue::enQueue(const AVFrame* _avFrame)
{
    // TODO STUB
    QMutexLocker locker(&this->mutex);  // 上锁, 在 return 的时候被销毁
    AVFrame* pAns = av_frame_alloc();
    if (av_frame_ref(pAns, _avFrame) < 0)
    {
        cout << "enter queue fail" << endl;
        return false;
    }
    // pAns->opaque = (void *)new double(*((double *)pAns->opaque));
    this->frames.push(pAns);
    this->waitCondition.wakeOne();
    return true;
}

/**
 * @author       ParanoidRoot
 * @method       FrameQueue::deQueue
 * @param        void
 * @return       队列首部的frame
 * @details      ...
 * @bug          不知道要不要使用线程锁
 */
AVFrame* FrameQueue::deQueue()
{
    QMutexLocker locker(&this->mutex);
    AVFrame* pAnsFrame = nullptr;
    while (true)
    {
        if (!this->frames.empty())  // 如果当前的队列非空则可以取出一帧
        {
            pAnsFrame = frames.front();
            frames.pop();
            return pAnsFrame;
        }
        else
        {
            this->waitCondition.wait(&mutex);
        }
    }
}



