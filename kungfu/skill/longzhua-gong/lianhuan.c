//Cracked by Kafei
// lianhuan.c ��צ��������ʽ
/// maco
/*
    ����ͻȻ����һ����������ϣ�˫�����������꣬������ʽ������׽Ӱʽ����������ʽ��������ɪʽ����������ʽ����������ʽ����������ʽ��������ȱʽ������ʽ�������������������޼������У���ʽ��Ϊ������׽Ӱ�����ٹ�ɪ���������顢������ȱ���������У����к󷢶�������
    ������ɮ���ʽ��������צ�����಻����������һ���еİ˸��仯һ�㣬����ޱȣ�
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int claw, lv, i, hit;
	string weapon, lzg_msg;

	if( !target ) target = offensive_target(me);
	

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��צ����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("lzg_effect") )
                return notify_fail("��ղ��Ѿ�ʹ������צ������������һʱ��������������\n");

	if ( me->query_temp("weapon") )
                return notify_fail("��צ����������������ַ���ʩչ��\n");
	if( me->query_skill_prepared("hand") == "qianye-shou" )
                return notify_fail("���޷���ʹ������ǧҶ��ʱͬʱʩչ��צ������������\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("������ʹ���ڹ����ǻ�Ԫһ�������޷�ʩչ��צ������������\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 100 )
		return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչ��צ������������\n");

	if( me->query_skill("claw",1) < 140 )
		return notify_fail("���צ����Ϊ���ޣ��޷�ʩչ��צ������������\n");

	if( me->query_skill("longzhua-gong",1) < 140 )
		return notify_fail("�����צ������δ�����޷�ʩչ��צ������������\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�������������ʹ����צ������������\n");

	if( me->query("jing") <= 200 )
		return notify_fail("��ľ�������ʹ����צ������������\n");

	claw = me->query_skill("claw");
	lv = (int)me->query_skill("longzhua-gong",1);
	hit = (lv/100)*2;
	if(hit > 8) hit = 8;
	if(hit <4) hit = 4;
	
	me->add_temp("apply/attack", lv/10);

	lzg_msg = HIY"\n$NͻȻ����һ����������ϣ�˫�����������꣬";
	
	if(hit >= 4)lzg_msg += "������ʽ������׽Ӱʽ����������ʽ��������ɪʽ��";
	if(hit >= 6)lzg_msg += "��������ʽ����������ʽ��";
	if(hit >= 8)lzg_msg += "��������ʽ��������ȱʽ��";
	
	lzg_msg += "��"+chinese_number(hit)+"ʽ����������������\n"NOR;

	message_vision(lzg_msg, me, target);
	me->set_temp("lzg_times",hit);
	me->set_temp("lzg_effect",1);
	me->add_temp("lzg_lianhuan", 3);
        for( i=0; i < hit; i++ )
        {
		me->add_temp("lzg_lianhuan", 1);
                COMBAT_D->do_attack(me, target, weapon);
        }


        message_vision(HIY"\n��"+chinese_number(hit)+"ʽ��������צ�����಻����������һ���е�"+chinese_number(hit)+"���仯һ�㣬����ޱȣ�\n"NOR, me);

	me->add("neili", -hit*20+20);
	me->add("jing", -hit*5);
	me->start_busy(1+random(2));
	me->delete_temp("lzg_lianhuan");
	me->delete_temp("lzg_times");
	me->add_temp("apply/attack", -lv/10);
        call_out("remove_effect", hit*2, me);
	return 1;
}


void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("lzg_effect");
        tell_object(me, YEL"\n��΢һ��Ϣ��ƽ����ʩչ��צ����ĵ����ڵ�������\n"NOR); 
}
