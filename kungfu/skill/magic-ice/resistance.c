#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷��ٻ���������");
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");
	if((int)me->query("neili")< 300)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("magic-ice",1)< 250)
	return notify_fail("�����ϵħ��̫���ˣ�\n");
        if ((int)me->query("magicgift")==3)
        return notify_fail("���Ѿ�ʹ�����������ˣ�\n");
	me->add("neili",-250);
	me->start_busy(2);
        me->set("magicgift",3);
	message_vision(HIC "\n$N����� [���������������������׵ľ��飡��������!] !!\n" NOR, me);	
	message_vision(HIC "\n$N����Χ���������ε���֮����!\n" NOR, me);
	return 1;
}
