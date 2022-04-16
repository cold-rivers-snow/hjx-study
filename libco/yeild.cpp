#include <iostream>
#include </root/workspace/libco/co_routine.h>
using namespace std;

void* A(void* arg) {
   cout << 1 << " ";
   cout << 2 << " ";
   co_yield_ct();  // 切出到主协程
   cout << 3 << " ";
   return NULL;
}

void* B(void* arg) {
   cout << "x" << " ";
   co_yield_ct();  // 切出到主协程
   cout << "y" << " ";
   cout << "z" << " ";
   return NULL;
}

int main(void) {

  stCoRoutine_t *accept_co = NULL;
  co_create( &accept_co,NULL,A,0 );
  co_resume( accept_co ); // 启动协程 A
  stCoRoutine_t* accept_co1 = NULL;
  co_create(&accept_co1, NULL, B, 0);
  co_resume(accept_co1);  // 启动协程 B
//   co_resume(accept_co);  // 从协程 A 切出处继续执行
//   co_resume(accept_co1);  // 从协程 B 切出处继续执行
  
  co_eventloop(co_get_epoll_ct(), NULL, NULL);
}

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <queue>
// #include </root/workspace/libco/co_routine.h>
// using namespace std;
// struct stTask_t
// {
// 	int id;
// };
// struct stEnv_t
// {
// 	stCoCond_t* cond;
// 	queue<stTask_t*> task_queue;
// };
// void* Producer(void* args)
// {
// 	co_enable_hook_sys();
// 	stEnv_t* env=  (stEnv_t*)args;
// 	int id = 0;
// 	while (true)
// 	{
// 		stTask_t* task = (stTask_t*)calloc(1, sizeof(stTask_t));
// 		task->id = id++;
// 		env->task_queue.push(task);
// 		printf("%s:%d produce task %d\n", __func__, __LINE__, task->id);
// 		co_cond_signal(env->cond);
// 		poll(NULL, 0, 1000);
// 	}
// 	return NULL;
// }
// void* Consumer(void* args)
// {
// 	co_enable_hook_sys();
// 	stEnv_t* env = (stEnv_t*)args;
// 	while (true)
// 	{
// 		if (env->task_queue.empty())
// 		{
// 			co_cond_timedwait(env->cond, -1);
// 			continue;
// 		}
// 		stTask_t* task = env->task_queue.front();
// 		env->task_queue.pop();
// 		printf("%s:%d consume task %d\n", __func__, __LINE__, task->id);
// 		free(task);
// 	}
// 	return NULL;
// }
// int main()
// {
// 	stEnv_t* env = new stEnv_t;
// 	env->cond = co_cond_alloc();

// 	stCoRoutine_t* consumer_routine;
// 	co_create(&consumer_routine, NULL, Consumer, env);
// 	co_resume(consumer_routine);

// 	stCoRoutine_t* producer_routine;
// 	co_create(&producer_routine, NULL, Producer, env);
// 	co_resume(producer_routine);
	
// 	co_eventloop(co_get_epoll_ct(), NULL, NULL);
// 	return 0;
// }