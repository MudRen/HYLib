#include <ansi.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
	object weapon, weapon1, target;
	int skill, skill1;
	string msg;

	if (!arg) return notify_fail("�����˭һ��˫����赣�\n");
	if (!objectp(target = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if (target==me) return notify_fail("���Լ���赣�\n"); 
	if ( !me->is_fighting() )
		return notify_fail("˫�����ֻ����ս����ʹ�á�\n");
	if ( !target->is_fighting() )
		return notify_fail("˫�����ֻ����ս���еĻ��һ��ʹ�á�\n");
	if (me->is_fighting(target))
		return notify_fail("�����ں�"+target->name()+"����ء�\n");

	weapon = me->query_temp("weapon");  
	weapon1 = target->query_temp("weapon");  

	if(!weapon || weapon->query("skill_type") != "blade"
		|| me->query_skill_mapped("blade") != "hujia-daofa"
		|| me->query_skill_mapped("parry") != "hujia-daofa")
		return notify_fail("�������޷�ʹ�á�˫����赡���\n");

	if(!weapon1 || weapon1->query("skill_type") != "blade"
		|| target->query_skill_mapped("blade") != "hujia-daofa"
		|| target->query_skill_mapped("parry") != "hujia-daofa")
		return notify_fail(target->name()+"�����޷�ʹ�á�˫����赡���\n");

	skill = me->query_skill("hujia-daofa", 1);
	skill1 = target->query_skill("hujia-daofa", 1);

	if(skill < 100 )
        return notify_fail("��ĺ��ҵ����ȼ�����������ʹ�á�˫����赡���\n");
    
//    if (me->query_skill_mapped("force") != "hujia-daofa")
//		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
	if(me->query("neili") < 500 )
		return notify_fail("����������̫��������ʹ�á�˫����赡���\n");
	if(target->query("neili") < 500 )
		return notify_fail("�Է���������̫��������ʹ�á�˫����赡���\n");
    if(me->query("neili") < 1000 )
		return notify_fail("���������Ϊ̫��������ʹ�á�˫����赡���\n");
    if(target->query("neili") < 1000 )
		return notify_fail("�Է���������Ϊ̫��������ʹ�á�˫����赡���\n");

	if(me->query_temp("shuangdao_hebi")) 
		return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");

	if(me->query_temp("��Ӱ")) 
		return notify_fail("������ʹ�����λ�Ӱ��������ʹ�á�˫����赡���\n");

	if (me->query_temp("hebi_target")){
		if (me->query_temp("hebi_target")==target)
			return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
		else
			tell_object(me->query_temp("hebi_target"), YEL+me->name()+"�������������˫������ˡ�\n"NOR); 
	}
	if (target->query_temp("hebi_target") ==me){
		message_vision(MAG"\n$N������"+weapon->name()+MAG+"һ�ڣ�����$n��"+weapon1->name()+MAG+"�ϣ�˫����ӣ���ʱ��â���䣬������أ�\n"NOR, me, target);
		me->set_temp("hebi_target", target);
		me->set_temp("shuangdao_hebi", 1); 
		target->set_temp("shuangdao_hebi", 1); 
		me->add("neili", -300);
		target->add("neili", -300);
		me->add("jing", -50);
		target->add("jing", -50);
		me->add_temp("apply/attack", skill);
		me->add_temp("apply/dodge", skill);
		target->add_temp("apply/attack", skill1);
		target->add_temp("apply/dodge", skill1);
		call_out("check_fight", 1, me, skill, (skill+skill1)/20);
		call_out("check_fight", 1, target, skill1, (skill+skill1)/20);
		return 1;
	}
	message_vision(HIC"\n$N������"+weapon->name()+HIC"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR, me, target);
	tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ͱڣ���Ҳ��"+me->name()+"��һ�� perform hebi <playername> �����\n"NOR);
	me->set_temp("hebi_target", target);
	return 1;
}

void remove_effect(object me, int skill)
{
	if(me->query_temp("shuangdao_hebi")){
		me->add_temp("apply/attack", -skill);
		me->add_temp("apply/dodge", -skill);
		me->delete_temp("shuangdao_hebi");
		me->delete_temp("hebi_target");
		message_vision(HIR"$N˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR, me);
	}
}

void check_fight(object me, int skill, int count)
{
	object weapon;
	object target;

	if (!me) return;
	if (count < 1 || !me->is_fighting()) {
		remove_effect(me, skill);
		return;
	}
	target = me->query_temp("hebi_target");
	if (!target || !target->is_fighting()) {
		remove_effect(me, skill);
		return;
	}
	if (target->query_temp("hebi_target") != me) {
		remove_effect(me, skill);
		return;
	}
	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "blade") {
		remove_effect(me, skill);
		return;
	}
	if (me->query_skill_mapped("blade") != "hujia-daofa"
		|| me->query_skill_mapped("parry") != "hujia-daofa") {
		remove_effect(me, skill);
		return;
	}
	if(environment(me) != environment(target)) {
		remove_effect(me, skill);
		return;
	}
    call_out("check_fight", 1, me, skill, count-1);
}
