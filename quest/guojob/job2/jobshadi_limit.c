#include <ansi.h>

#include <login.h>

int update_condition(object me, int duration)
{
        object room;
        object ob;
          object obb;
        object* inv;
        int i;
                
        ob=this_player();
        room = environment(ob);     

        if (me->query_temp("where")) {
        if (me->query_temp("where")!=environment(me)) {
                message_vision(HIY"һ���α��ܹ�����$N˵���������سǣ���ȴ�����й䣬��ȥ��������ˣ�\n"NOR,me);
                me->apply_condition("job_failed",8);
                me->set_temp("job_failed",1);
                return 0;
        }
        }

        message_vision(HIY"$N��վ�ڳ�ǽ������ע���ų���"HIR"�ɹű�"HIY"��һ��һ����\n"NOR,ob);
        me->apply_condition("jobshadi_limit", duration - 1);

        if(duration<1)
        {
                message_vision(CYN"\nһ���س��α��ܹ���˵�����ɹ�������ʱ�������ˣ�$N���Ի�ȥ�����ˣ�\n"NOR,ob);
                ob->set_temp("job_over",1);
                ob->delete_temp("start_job");
                inv=all_inventory(room);
                for (i = 0; i < sizeof(inv); i++) {
                     obb=inv[i];
                        if (obb->is_character()) {
                        if (obb->query("ygjg")==ob) destruct(obb);
                    }
                        continue;
                }
                return 0;
        }
        return 1;
}

