// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

        if ((!target)||target->query("id")==me->query("id"))
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if( (int)me->query_skill("linji-zhuang",1) < 20 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("max_neili") < 350 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("neili") < 50)
                return notify_fail("�������������\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 6 )
                return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

        message_combatd(
                HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
                "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
                me, target );

    target->receive_curing("qi", 200 + (int)me->query_skill("force")/2 );
    target->add("qi", 200 + (int)me->query_skill("force")/2 );
    target->receive_curing("jing", 100 + (int)me->query_skill("force")/2 );
    target->add("jing", 100 + (int)me->query_skill("force")/2 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( userp(target) && (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi") ) target->set("qi", (int)target->query("max_qi"));
if (target->is_fighting())
me->add("neili", -100);
else    me->add("neili", -50);
me->start_busy(3);
    return 1;
}

