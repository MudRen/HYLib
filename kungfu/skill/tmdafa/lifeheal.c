// lifeheal.c



#include <ansi.h>



int exert(object me, object target)

{

        if( !target )

                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");



        if( me->is_fighting() || target->is_fighting())

                return notify_fail("ս�����޷��˹����ˣ�\n");



        if( (int)me->query("max_neili") < 300 )

                return notify_fail("���������Ϊ������\n");



        if( (int)me->query("neili") < 150 )

                return notify_fail("�������������\n");



        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )

                return notify_fail( target->name() +

                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");



        message_vision(

                HIY "$N��������������������$n����������һ�ɰ�����$N��$n��������....\n\n"

                "���˲��ã���������ɢȥ��$n���ƿ������ö��ˡ�\n" NOR,

                me, target );



        target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );

        target->add("qi", 10 + (int)me->query_skill("force")/3 );

        if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));



        me->add("neili", -150);

        me->set("jiali", 0);



        return 1;

}

