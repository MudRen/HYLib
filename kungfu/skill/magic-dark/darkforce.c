#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object dark,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷�ʹ�û�������");
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");
	if((int)me->query("neili")< 500)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("magic-dark",1)< 300)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");
        if ((int)me->query("magicgift")==5)
        return notify_fail("���Ѿ�ʹ�û��������ˣ�\n");
	me->add("neili",-350);
	me->start_busy(2);
        me->set("magicgift",5);
	message_vision(BLK "\n$N����� ͳ���Ľ�ĺڰ�֮��! ���������е������������Ҹ�ǿ��ħ���ɣ����� \n" NOR, me);	
	message_vision(BLK "\n$N����� ���ҵ������ҵ������ϣ�һ���������֮�̰ɣ���\n" NOR, me);	
	message_vision(BLK "\n$N����Χ�γ���һ�����εĺڰ�����!\n" NOR, me);
	return 1;
}
