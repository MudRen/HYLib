// breakup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int breaking(object me);
int halt_breaking(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int exercise_cost;
        object where;
        int maxneili;

        seteuid(getuid());
        where = environment(me);
        
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (me->query("breakup"))
                return notify_fail("���Ѿ���ͨ���ζ������ˣ��ƺ�û�б�Ҫ����һ�Ρ�\n");

        if (! where->query("no_fight"))
                return notify_fail("�������ͨ�ζ���������̫��ȫ�ɣ�\n");

        if (! where->query("sleep_room"))
                return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");

        if ( where->query("pingan"))
                return notify_fail("����ط�������\n");

        if ( where->query("biwu"))
                return notify_fail("����ط�������\n");

        if ( where->query("citybiwu"))
                return notify_fail("����ط�������\n");

        if (me->query_temp("biguan"))
                return notify_fail("�����ڴ�ͨ�ζ�������\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (me->query("potential") < 500)
                return notify_fail("���Ǳ�ܲ�����û���չ������Դ�ͨ�ζ�������\n");

        if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
                return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");

        if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
                return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");

        if ((int)me->query("neili") < 4000)
                return notify_fail("������������в��㣬����Ŀǰ������"
                                   "��ͨ�ζ�������\n");

        if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
                return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
        if (me->query_condition("bg_busy"))
                return notify_fail("��ձչ��أ���Ϣ����������!\n");


        if ((int)me->query_skill("force", 1) < 250)
                return notify_fail("������Լ����ڹ�������ޣ�������"
                                   "Ҫ�ȶ������ڹ����С�\n");


        message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
        me->set("startroom", base_name(where));
        me->set("doing", "breakup");
        me->set_temp("biguan", 1);
        me->apply_condition("bg_busy",100);
        me->start_busy(10);
                   
        CHANNEL_D->do_channel(this_object(), "rumor",
                              sprintf("%s%s(%s)��ʼ�չ����У���ͼ��ͨ�ζ�������",
                              "",me->name(1), me->query("id")));
        if (call_out("breaking", 10, me) && !me->query("breakup"))
                call_out("breaking", 10, me);
        return 1;
}

int continue_breaking(object me)
{
        me->start_busy(60);
        
        tell_object(me, HIR "\n������չ������Դ�ͨ�ζ�����...\n" NOR);
        return 1;
}

private void stop_breaking(object me)
{
        if (! interactive(me))
        {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
        }
}

int breaking(object me)
{
        string msg;

if (!me)  return notify_fail("���Ѿ������ˣ�\n");

if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s(%s)�չؽ������ƺ�û��̫��Ľ�չ��",
                                      me->name(1), me->query("id")));
                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
	if( (int)me->query("learned_points") < 1 )
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s(%s)�չؽ������ƺ�û��̫��Ľ�չ��",
                                      me->name(1), me->query("id")));
                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
        if (me->query("potential") <= me->query("learned_points"))
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s(%s)�չؽ������ƺ�û��̫��Ľ�չ��",
                                      me->name(1), me->query("id")));
                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }

        me->add("potential",-1);

        if (random(10))
        { 
              call_out("breaking", 10, me);
              return 1;
        }       
        if (random(4000) < me->query("con") && !me->query("breakup"))
        {
                message_vision(HIW "ֻ��$N" HIW "ͷ�ϰ������ڡ�����"
                               "��ͬ���������У������Ѿ����������۶���"
                               "������Ԫ��������á����˽���Ľ�Ҫ��ͷ��\n" NOR, me);
                tell_object(me, HIR "����������ڵ���ԴԴ����������"
                            "������Ѩ�����������ѵ�����������������\n" NOR);
                message_vision(HIC "ͻȻ$N" HIC "���һ����һ����������"
                               "��Ȼɢ�����������ܿ�����ʱ������ȡ�\n" NOR, me);
                tell_object(me, HIG "���ʱ���û���һ�����ɣ�һ������֮����Ȼ"
                            "��������һƬ����������û��˿�����ͣ���̩֮����\n" NOR);
                me->set_temp("biguan", 0);
                me->set("breakup", 1);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s(%s)�����չؿ��ޣ����ڴ�ͨ"
                                              "���ζ����������ӵ������ϵ���ѧ���硣",
                                      me->name(1), me->query("id")));
                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 500000);
            me->add("max_jing",1000);
            me->add("eff_jing",1000);
            me->add("max_jingli",100);
            me->add("eff_jingli",100);
   	    me->set_skill("biguan",200);
//                CHAR_D->setup_char(me);
                stop_breaking(me);
                return 0;
        }

        switch (random(5))
        {
        case 0:
                msg = "��ĬĬ��ת������������Щ�о���\n";
                me->start_busy(5);
                break;

        case 1:
                msg = "�㽫�����˳�������Ϲ��������衢͸ʮ����¥���鲼��������Ȼ���ջص��\n";
                me->start_busy(5);
                break;

        case 2:
                msg = "�㽫�����˾���Ѩ������֫���࣬Ȼ���ֻ��յ��\n";
                me->start_busy(5);
                break;

        case 3:
                msg = "���ڵ����в��ϻ���������ֻ���û������ȡ�\n";
                me->start_busy(5);
                break;

        default:
                msg = "�㻺���������ɣ���������ˮ¶����Ϊ���á�\n";
                me->start_busy(5);
                break;
        }

        tell_object(me, msg);
        call_out("breaking", 5, me);
        return 1;
}

int halt_breaking(object me)
{
//        CLOSE_D->user_opened(me);
        tell_object(me, "����ֹ�˱չء�\n");
        message_vision(HIY "$N" HIY "����̾��һ�����������������ۡ�\n\n" NOR, me);
                        me->set_temp("biguan", 0);
//        me->add("potential", me->query("potential")/ 2);
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name(1) +
                              "�չ���;ͻȻ������");
        return 1;
}

private void user_quit(object me)
{
        if (! me || interactive(me))
                return;
      
        me->force_me("quit");
}

int help(object me)
{
        write(@HELP
ָ���ʽ : biguan

�չ������Դ�ͨ�ζ���������Ҫ�ǳ������������ڹ����ײ���������
���һ�����Ǳ�ܡ�һ����ͨ���ζ���������ͬʱ��չ��������������
���������ޡ�

HELP );
        return 1;
}
