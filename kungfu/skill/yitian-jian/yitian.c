// yitian.c ���콣��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        int extra,i,time;
        string msg;
        i = me->query_skill("yitian-jian", 1) + me->query_skill("sword", 1) + me->query_skill("linji-zhuang", 1);
        time = 5;
         if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("�����콣����ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����콣���������ý�����ʹ�ã�\n");
        if (me->query_skill_mapped("sword") != "yitian-jian")
                return notify_fail("��û�м������콣������ôʹ�á����콣��������\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("����ڹ���Ϊ������\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("yitian-jian",1) < 120 )
                return notify_fail("������콣���������ң��޷�ʹ�á����콣������\n");

        msg =HIY "$N" HIY "��Хһ����\n" HIR "�������𡢱����������������£�Ī�Ҳ��ӡ����첻����˭������? \n"
             HIR "��ʱ���Ʊ�ɫ��" HIR "$N" HIR "����������콣��........ \n" NOR;

        message_vision(msg, me);
        if (random(3)==0) target->start_busy(3);
        me->add_temp("apply/attack", i);
//        me->add_temp("apply/damage", i/2);
        me->add_temp("apply/damage", i);
//        for(i=1;i<=(int)time;i++)
        {
        msg =  HIC "-----���Ƽ���!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);

        msg =  BLU "-----�Ǻ�����!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);

        msg =  HIY "-----���첻��!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);

        msg =  HIR "-----˭������!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);

        msg =  HIM "-----��������!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -i);
//        me->add_temp("apply/damage", -i/2);
        me->add_temp("apply/damage", -i);
        me->add("neili",-200);
        msg =HIY "$N�������콣��������Ȼ�ӿ죡\n" NOR;
        message_vision(msg, me);
        me->start_busy(2+random(1));
        return 1;
}

