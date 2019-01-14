#include "VulkanQueue.h"
#include "VulkanDevice.h"

VulkanQueue::VulkanQueue(std::shared_ptr<VulkanDevice> device, uint32 familyIndex)
    : m_Queue(VK_NULL_HANDLE)
    , m_FamilyIndex(familyIndex)
    , m_QueueIndex(0)
    , m_Device(device)
{
    vkGetDeviceQueue(m_Device->GetInstanceHandle(), m_FamilyIndex, 0, &m_Queue);
}

VulkanQueue::~VulkanQueue()
{
    
}