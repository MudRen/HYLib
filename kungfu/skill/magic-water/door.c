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
        return notify_fail("��������æ���޷�ʹ��ʱ��֮��");
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");
	if((int)me->query("neili")< 300)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("magic-water",1)< 50)
	return notify_fail("���ˮϵħ��̫���ˣ�\n");
        if (me->query("neili") < 400)
        return notify_fail("��ķ������㣡\n");
         if (me->is_fighting()) 
        return notify_fail("���������������!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ��������\n");

   if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
	return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ��ʱ��֮�š�\n");
	me->add("neili",-150);
	me->start_busy(3);
        if( !environment(me)->query("no_fight") )
		return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ��ʱ��֮�š�\n");
        me->set("startroom", base_name(environment(me)));
	me->save();
	message_vision(WHT "\n$N�:�����������Ӱ�������ɣ���������\n" NOR, me);	
	message_vision(WHT "\n$N�Ľ��³�����һ����â�ǡ�!!!\n" NOR, me);
	write(WHT"�����´����߽���ʱ�����������ʱ���ŵĵط���ʼ��\n"NOR);
	message_vision(WHT "\n$N���µ���â��������ʧ��!!!\n" NOR, me);
	return 1;
}
