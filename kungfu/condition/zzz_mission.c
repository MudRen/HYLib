// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "��Ķ���̫��,����ȡ���ˡ�\n" NOR);
         //     me->delete_temp("assigned_by");
        	 me->delete_temp("zzz_job_target");
           //              me->delete_temp("gb_job_pot");
             //            me->delete_temp("gb_job_exp");
               // me->add("gb_job",-1);
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("zzz_mission", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
