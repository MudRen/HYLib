// heal.c



#include <ansi.h>



int exert(object me, object target)

{

        if( me->is_fighting() )

                return notify_fail("ս�����˹����ˣ�������\n");



        if ((int)me->query_skill("tmdafa", 1) < 20)

                return notify_fail("�����ħ����Ϊ��������\n");

        if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )

                return notify_fail("�������������\n");



        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )

                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");



        write( HIW "��Ĭ��������һ��ů��͸��ȫ���������ҵ���ϢѸ��ƽ����\n" NOR);

        message("vision",

                HIW + me->name() + "ԭ�Ȼ��ҵ���Ϣ������ƽ���ˣ��������ƺ��˲��١�\n" NOR,

                environment(me), me);



        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );

        me->add("neili", -50);

        me->set("jiali", 0);



        return 1;

}