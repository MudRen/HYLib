#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        int i;

        if(!me->is_fighting() )
                return notify_fail("����ֻ���ڶ�ս����ʹ�á�\n");

        if( (int)me->query_skill("linji-zhuang",1) < 150 )
                return notify_fail("����ټ�ʮ��ׯ�������ʹ����������\n");  

        if( (int)me->query_skill("huifeng-jian",1) < 150 )
                return notify_fail("��Ļط�������������ʹ����������\n");  

        if( me->query_temp("huifeng/jue"))
                return notify_fail("���Ѿ���ʹ���ˡ�\n");

        if( (int)me->query("jing", 1) < 100 )
                return notify_fail("�����ھ�������\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������������\n");

        msg = HIW"$N����һ������������Ҿ�����ʹ������������\n"NOR;
        msg+= HIW"$N��Ȼ���ƴ�����\n"NOR;
        me->add("neili", -400);
        me->add("jing", -50);
        me->start_busy(1+random(2));
        i = me->query_skill("linji-zhuang",1) + me->query_skill("huifeng-jian");
        i = i/10;
        me->add_temp("apply/parry", i);
        me->add_temp("apply/sword", i);
        me->add_temp("apply/dodge", i);
        me->set_temp("huifeng/jue", 1);
               msg+= HIY"$N���𽣡�����������ϣ�����������\n"NOR;
               me->add_temp("apply/attack",(i*4));
               me->add_temp("apply/damage",(i*2));
               me->add_temp("apply/defence", (i*3));
               me->add_temp("apply/armor", (i*2));
        message_vision(msg, me);
        call_out("remove_effect", (int)me->query_skill("linji-zhuang",1)/4, me, i);
        return 1;
}

void remove_effect(object me, int i)
{
if (!me) return;
        me->delete_temp("huifeng/jue");
        me->add_temp("apply/parry", -i);
        me->add_temp("apply/sword", -i);
        me->add_temp("apply/dodge", -i);
               me->add_temp("apply/attack",-(i*4));
               me->add_temp("apply/damage",-(i*2));
               me->add_temp("apply/defence", -(i*3));
               me->add_temp("apply/armor", -(i*2));
        message_vision(HIW"$N������ʹ��ϣ��ָ���ƽ���Ĺ�����\n"NOR, me);
}

