// heal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("ս�����˹����ˣ�������\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���������\n");
    if( (int)me->query("neili") < 50 ) 
   return notify_fail("�������������\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
   return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    write( HIW "����ȥһ���ɱ�⣬ȫ����ɣ�������������Ȼ�������\n" NOR);
    message("vision",
   HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
   environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
    me->add("neili", -50);
    me->set("jiali", 0);

    return 1;
}

