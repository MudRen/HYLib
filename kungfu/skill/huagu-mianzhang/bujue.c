// mmbj.c ���಻��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
//      int damage;
        string msg;
//      object weapon;
        int cs,skill,i,jl,onl,njl; 
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����಻����ֻ����ս��ʱ�ã�\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ����á����಻������\n");
        if( (skill=(int)me->query_skill("huagu-mianzhang", 1)) < 100 )
                return notify_fail("��Ļ������ƻ���������������ʹ�ã�\n");
	cs = skill / 50;
	if(cs>4)
		cs=4;
        if((int)me->query("neili")<100)
		return notify_fail("�������������㣬�����á����಻������\n");       
	if( (int)me->query_skill("shenlong-xinfa",1) < 100  )
		return notify_fail("��������ķ������������޷�ʩ�á�\n");
        if( me->query_temp("mmbj"))
                return notify_fail("������ʹ�á����಻�����أ�\n");     
        msg = HIY "\n$N��Ȼ��һ������˫��һ������$p������ĳ���\n"NOR; 
	message_vision(msg, me, target);
	target->start_busy(1);
	jl=me->query("jiali");
        me->start_busy(2+random(2));
	me->add("jing",-100);
	me->set_temp("mmbj", 1);
	onl=me->query("neili");
	if(!objectp(target->query_temp("weapon")))
	{
		njl=80;
	}
	else
		njl=100;
	for(i=1;i<=cs;i++)
	{
		if((int)me->query("neili", 1)<i*njl)
			break;
		me->set("jiali",i*njl);
		COMBAT_D->do_attack(me, target,0, 1); 
        }
	if((onl-me->query("neili"))<100)
		me->set("neili",onl-100);
	me->set("jiali",jl);
	me->delete_temp("mmbj", 1);
        return 1;       
}

