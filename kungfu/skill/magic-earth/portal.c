#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
	string startroom;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷���ʹ�ûس���");
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");
	if((int)me->query("neili")< 300)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("magic-earth",1)< 50)
	return notify_fail("�����ϵħ��̫���ˣ�\n");
        if (me->query("neili") < 400)
        return notify_fail("��ķ������㣡\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if (me->is_busy()) 
        return notify_fail("����æ����!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ�ûس�����\n");

   if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
	return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ�ûس�����\n");

        if( !environment(me)->query("no_fight") )
		return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ�ûس�����\n");
        startroom = me->query("startroom");
        if( !me->query("startroom") )
		return notify_fail("����ȷ����Ҫȥ��Ŀ���!\n");
	me->add("neili",-150);

	message_vision(YEL "\n$N�ڵ��ϻ���һ����â�ǣ������૵���������!!\n" NOR, me);	
	message_vision(YEL "\n$Nվ�ڵĵ��ϳ����˾޴�Ĺ�â����$N��Χ��!\n" NOR, me);
        message_vision(YEL "\n$N�ڹ�â�У���ʧ������!\n" NOR, me);
        me->move(startroom);
	me->start_busy(3);
	return 1;
}
