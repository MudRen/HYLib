// transfer.c ת����
// Modified by Venus Oct.1997
#include <ansi.h>

int exert(object me, object target)
{
    int force, trans;

    if( query_ip_name(target)==query_ip_name(me))
       return notify_fail("��Ҫ����������˭��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
        if ( wizardp(me) )
                return notify_fail("������ʦ�����...�����˰ɣ�\n");

        if( me->query_skill("shenzhao-jing", 1) > 100)
                return notify_fail("���վ����������޷����ͣ�\n");


    if( !target || target==me || !living(target) )
       return notify_fail("��Ҫ������������λ��\n");

    if( me->query_skill_mapped("force") != target->query_skill_mapped("force") )
       return notify_fail(target->name()+"��ʹ�õ��ڹ����㲻ͬ�����ܴ�������\n");

    if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
       return notify_fail("����������㡣\n");

    if( (int)me->query("max_neili") <= (int)target->query("max_neili") )
       return notify_fail("��������������˼Ҷ࣬������ȥ��\n");

    if ((int)target->query("neili")>=(int)target->query("max_neili")*4)
       return notify_fail("�Է����������棬����Ҫ���������\n");

    force = me->query("neili") - (me->query("max_neili")/3);

    if( force/2 < 1 ) return notify_fail("����������㡣\n");
    me->add("neili", -force/3 );
    if( (int)me->query("max_neili") <= (int)target->query("max_neili")*5/4 )
       me->add("max_neili", -1);

    message_combatd(HIW"$Nһ������$n���ģ�˳�������������������͹�ȥ��\n"NOR, me,target);
    target->add("neili", force/2);
if (random(10)>7)
{
    me->add("max_neili", -1);
}
    write("Ok��\n");
    tell_object(target, HIW "�����һ��������"+me->name()+"�������д��˹�����\n" NOR);
    return 1;
}

