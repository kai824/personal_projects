// ans.cpp 8 Mar 18, 20:41:15 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
#ifndef _OMP_H
#define _OMP_H 1

#ifndef _LIBGOMP_OMP_LOCK_DEFINED
#define _LIBGOMP_OMP_LOCK_DEFINED 1
/* These two structures get edited by the libgomp build process to 
   reflect the shape of the two types.  Their internals are private
   to the library.  */

typedef struct
{
  unsigned char _x[@OMP_LOCK_SIZE@] 
    __attribute__((__aligned__(@OMP_LOCK_ALIGN@)));
} omp_lock_t;

typedef struct
{
  unsigned char _x[@OMP_NEST_LOCK_SIZE@] 
    __attribute__((__aligned__(@OMP_NEST_LOCK_ALIGN@)));
} omp_nest_lock_t;
#endif

typedef enum omp_sched_t
{
  omp_sched_static = 1,
  omp_sched_dynamic = 2,
  omp_sched_guided = 3,
  omp_sched_auto = 4
} omp_sched_t;

typedef enum omp_proc_bind_t
{
  omp_proc_bind_false = 0,
  omp_proc_bind_true = 1,
  omp_proc_bind_master = 2,
  omp_proc_bind_close = 3,
  omp_proc_bind_spread = 4
} omp_proc_bind_t;

typedef enum omp_lock_hint_t
{
  omp_lock_hint_none = 0,
  omp_lock_hint_uncontended = 1,
  omp_lock_hint_contended = 2,
  omp_lock_hint_nonspeculative = 4,
  omp_lock_hint_speculative = 8,
} omp_lock_hint_t;

#ifdef __cplusplus
extern "C" {
# define __GOMP_NOTHROW throw ()
#else
# define __GOMP_NOTHROW __attribute__((__nothrow__))
#endif

extern void omp_set_num_threads (int) __GOMP_NOTHROW;
extern int omp_get_num_threads (void) __GOMP_NOTHROW;
extern int omp_get_max_threads (void) __GOMP_NOTHROW;
extern int omp_get_thread_num (void) __GOMP_NOTHROW;
extern int omp_get_num_procs (void) __GOMP_NOTHROW;

extern int omp_in_parallel (void) __GOMP_NOTHROW;

extern void omp_set_dynamic (int) __GOMP_NOTHROW;
extern int omp_get_dynamic (void) __GOMP_NOTHROW;

extern void omp_set_nested (int) __GOMP_NOTHROW;
extern int omp_get_nested (void) __GOMP_NOTHROW;

extern void omp_init_lock (omp_lock_t *) __GOMP_NOTHROW;
extern void omp_init_lock_with_hint (omp_lock_t *, omp_lock_hint_t)
  __GOMP_NOTHROW;
extern void omp_destroy_lock (omp_lock_t *) __GOMP_NOTHROW;
extern void omp_set_lock (omp_lock_t *) __GOMP_NOTHROW;
extern void omp_unset_lock (omp_lock_t *) __GOMP_NOTHROW;
extern int omp_test_lock (omp_lock_t *) __GOMP_NOTHROW;

extern void omp_init_nest_lock (omp_nest_lock_t *) __GOMP_NOTHROW;
extern void omp_init_nest_lock_with_hint (omp_nest_lock_t *, omp_lock_hint_t)
  __GOMP_NOTHROW;
extern void omp_destroy_nest_lock (omp_nest_lock_t *) __GOMP_NOTHROW;
extern void omp_set_nest_lock (omp_nest_lock_t *) __GOMP_NOTHROW;
extern void omp_unset_nest_lock (omp_nest_lock_t *) __GOMP_NOTHROW;
extern int omp_test_nest_lock (omp_nest_lock_t *) __GOMP_NOTHROW;

extern double omp_get_wtime (void) __GOMP_NOTHROW;
extern double omp_get_wtick (void) __GOMP_NOTHROW;

extern void omp_set_schedule (omp_sched_t, int) __GOMP_NOTHROW;
extern void omp_get_schedule (omp_sched_t *, int *) __GOMP_NOTHROW;
extern int omp_get_thread_limit (void) __GOMP_NOTHROW;
extern void omp_set_max_active_levels (int) __GOMP_NOTHROW;
extern int omp_get_max_active_levels (void) __GOMP_NOTHROW;
extern int omp_get_level (void) __GOMP_NOTHROW;
extern int omp_get_ancestor_thread_num (int) __GOMP_NOTHROW;
extern int omp_get_team_size (int) __GOMP_NOTHROW;
extern int omp_get_active_level (void) __GOMP_NOTHROW;

extern int omp_in_final (void) __GOMP_NOTHROW;

extern int omp_get_cancellation (void) __GOMP_NOTHROW;
extern omp_proc_bind_t omp_get_proc_bind (void) __GOMP_NOTHROW;
extern int omp_get_num_places (void) __GOMP_NOTHROW;
extern int omp_get_place_num_procs (int) __GOMP_NOTHROW;
extern void omp_get_place_proc_ids (int, int *) __GOMP_NOTHROW;
extern int omp_get_place_num (void) __GOMP_NOTHROW;
extern int omp_get_partition_num_places (void) __GOMP_NOTHROW;
extern void omp_get_partition_place_nums (int *) __GOMP_NOTHROW;

extern void omp_set_default_device (int) __GOMP_NOTHROW;
extern int omp_get_default_device (void) __GOMP_NOTHROW;
extern int omp_get_num_devices (void) __GOMP_NOTHROW;
extern int omp_get_num_teams (void) __GOMP_NOTHROW;
extern int omp_get_team_num (void) __GOMP_NOTHROW;

extern int omp_is_initial_device (void) __GOMP_NOTHROW;
extern int omp_get_initial_device (void) __GOMP_NOTHROW;
extern int omp_get_max_task_priority (void) __GOMP_NOTHROW;

extern void *omp_target_alloc (__SIZE_TYPE__, int) __GOMP_NOTHROW;
extern void omp_target_free (void *, int) __GOMP_NOTHROW;
extern int omp_target_is_present (void *, int) __GOMP_NOTHROW;
extern int omp_target_memcpy (void *, void *, __SIZE_TYPE__, __SIZE_TYPE__,
			      __SIZE_TYPE__, int, int) __GOMP_NOTHROW;
extern int omp_target_memcpy_rect (void *, void *, __SIZE_TYPE__, int,
				   const __SIZE_TYPE__ *,
				   const __SIZE_TYPE__ *,
				   const __SIZE_TYPE__ *,
				   const __SIZE_TYPE__ *,
				   const __SIZE_TYPE__ *, int, int)
  __GOMP_NOTHROW;
extern int omp_target_associate_ptr (void *, void *, __SIZE_TYPE__,
				     __SIZE_TYPE__, int) __GOMP_NOTHROW;
extern int omp_target_disassociate_ptr (void *, int) __GOMP_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif /* _OMP_H */
using namespace std;
#pragma optimise
typedef long long ll;
ll n,arr2[16],ans[16],id;
inline ll process(ll x) {
    return 64-__builtin_clzll(x)-1;
}
inline ll long_computation(ll start){
    ll arr[2],sum=start;
    arr[0]=start;
    bool bit=1;
    for(int x=1;x<n;x++){
        arr[bit] = ((arr[!bit]% 1000000007) * (arr[!bit]% 1000000007)) % 1000000007; 
        arr[bit] = ((arr[bit]% 1000000007) * ((long long)process(arr[bit]))) % 1000000007;
        arr[bit] = (arr[bit]% 1000000007) * ((((arr[!bit]% 1000000007) + (arr[bit]% 1000000007)) * ((arr[bit]% 1000000007) + (arr[!bit]% 1000000007)))% 1000000007); 
        arr[bit] %= 1000000007;
        sum += arr[bit];
        bit=!bit;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr2[x];
        //cout<<long_computation(arr[x]);
    }
    #pragma omp parallel for default(none) num_threads(16) private(id)
    {
        id = omp_get_thread_num();
        ans[id]=long_computation(arr2[id]);
    }
    for(int x=0;x<16;x++){
        cout<<ans[x];
        if(x+1<16)cout<<' ';
    }
    return 0;
}