// heal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("ս�����˹����ˣ�������\n");

    if ((int)me->query_skill("jiuyin-zhengong", 1) < 20)
   return notify_fail("��ľ����湦��Ϊ��������\n");
    if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50)
   return notify_fail("�������������\n");

    if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
   return notify_fail("�㲢δ���ˣ�\n");
   
    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
   return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

    write( HIB "��ȫ����ɣ����վ����ͽ�ƪ��ʼ�˹����ˡ�\n" NOR);
    message("vision",
   HIB + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
   environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/4 );
    me->add("neili", -50);

    return 1;
}

