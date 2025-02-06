#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
// 自动包含vulkan头文件

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class HelloTriangleApplication
{
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    // uint32_t即为unsigned int
    const uint32_t WIDTH = 800, HEIGHT = 600;
    GLFWwindow *window;
    VkInstance instance;
    const char **glfwExtensions;
    uint32_t glfwExtensionCount = 0, extensionCount = 0;

    void initWindow()
    {
        glfwInit();                                                           // 初始化glfw
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);                         // 不创建OpenGL上下文
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);                           // 不可更改窗口大小
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); // 创建窗口
    }

    void initVulkan() { createInstance(); }

    void mainLoop()
    {
        while (!(glfwWindowShouldClose(window))) // 保持窗口打开
            glfwPollEvents();
    }

    void cleanup()
    {
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window); // 销毁窗口
        glfwTerminate();           // 终止glfw
    }

    void createInstance()
    {
        VkApplicationInfo appInfo{};                           // 存储应用程序信息
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;    // 指定结构体类型为应用程序信息结构体
        appInfo.pApplicationName = "Hello Triangle";           // 应用名
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0); // 应用版本
        appInfo.pEngineName = "No Engine";                     // 使用引擎名称
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);      // 引擎版本
        appInfo.apiVersion = VK_API_VERSION_1_0;               // Vulkan api版本

        VkInstanceCreateInfo createInfo{};                                       // 存储创建实例的所需参数
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;               // 指定结构体类型
        createInfo.pApplicationInfo = &appInfo;                                  // 指向appInfo的指针
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount); // 获取GLFW所需Vulkan扩展名称数组
        createInfo.enabledExtensionCount = glfwExtensionCount;                   // 设置需要启用Vulkan扩展数量
        createInfo.ppEnabledExtensionNames = glfwExtensions;                     // 指向需要启用的Vulkan扩展名称数组
        createInfo.enabledLayerCount = 0;                                        // 设置需要启用Vulkan层数量(这里不需要)

        VkResult result = vkCreateInstance(&createInfo, nullptr, &instance); // 创建实例
        if (result != VK_SUCCESS)
            throw std::runtime_error("Failed to create instance!");

        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);           // 获取所有可用的Vulkan实例扩展数量, 并将其存储在extensionCount中
        std::vector<VkExtensionProperties> extensions(extensionCount);                       // 创建大小为extensionCount的VkExtensionProperties数组, 用于存储所有可用的Vulkan实例扩展信息
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()); // 将所有可用扩展详细信息填充的extensions向量
        std::cout << "available extensions:\n";
        for (const auto &extension : extensions) // 遍历向量, 输出所有可用的扩展名称
            std::cout << '\t' << extension.extensionName << '\n';
    }
};

int main()
{
    HelloTriangleApplication app;

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
