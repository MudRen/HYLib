#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"��ҪΪ˭ʹ���ƶ�����\n"NOR);

       if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷�ʹ�ã�\n");
		
	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

	
	if((int)me->query_skill("magic-light",1)< 350)
	return notify_fail("��Ĺ���ħ��̫���ˣ�\n");

	if((int)target->query("qi") > (int)target->query("max_qi")-50)
	return notify_fail("Ŀ�����ڲ���Ҫʹ���ƶ�����\n");

	msg = HIY "$N"HIY"��������������������.$N"HIY"�����ϲ���һ��ө��.\n"NOR;
        msg += HIY"$N"HIY"� ��֮�񰡣����������������ҵ����ɣ���\n"NOR;
	msg += HIY "$N�쿪˫�ۣ���ʥ�Ĺ���֮��ע��$n�����ڡ�\n";
	msg += HIG "����֮��ʹ$nȫ����һɨ����!\��\n";
	me->add("neili",-500);
	me->start_busy(2);
	if((int)target->query("qi") < (int)target->query("max_qi")+(int)target->query("max_qi")/8)
        {
	msg += HIG "����֮��ʹ$n���ϵ�������һ��!\��\n";
        target->add("qi",target->query("eff_qi")/10);
        target->add("eff_qi",target->query("eff_qi")/10);
if (target->query("qi") > target->query("max_qi")+1800)
target->set("qi",target->query("max_qi")+1800);
if (target->query("eff_qi") > target->query("max_qi"))
target->set("eff_qi",target->query("max_qi"));
        }
	if((int)target->query("jing") < (int)target->query("max_jing")+(int)target->query("max_jing")/8)
        {
	msg += HIG "����֮��ʹ$n�ľ���һ��!\��\n";
        target->add("jing",target->query("eff_jing")/10);
        target->add("eff_jing",target->query("eff_jing")/10);
if (target->query("jing") > target->query("max_jing")+1800)
target->set("jing",target->query("max_jing")+1800);
if (target->query("eff_jing") > target->query("max_jing"))
target->set("eff_jing",target->query("max_jing"));
        }

		if (target->query_condition("scorpion_poison"))
        target->apply_condition("scorpion_poison", 0);
		if (target->query_condition("qx_snake_poison"))
	target->apply_condition("qx_snake_poison", 0);
		if (target->query_condition("ss_poison"))
        target->apply_condition("ss_poison", 0);
		if (target->query_condition("tmzhuihun_poison"))
	target->apply_condition("tmzhuihun_poison", 0);
		if (target->query_condition("tmpili_poison"))
        target->apply_condition("tmpili_poison", 0);
		if (target->query_condition("zm_poison"))
        target->apply_condition("zm_poison", 0);
		if (target->query_condition("drunk"))
			target->apply_condition("drunk",0);
		if (target->query_condition("flower_poison"))
			target->apply_condition("flower_poison",0);
		if (target->query_condition("ice_poison"))
			target->apply_condition("ice_poison",0);
		if (target->query_condition("iceshock"))
			target->apply_condition("iceshock",0);
		if (target->query_condition("rose_poison"))
			target->apply_condition("rose_poison",0);
		if (target->query_condition("sanxiao_poison"))
			target->apply_condition("sanxiao_poison",0);
		if (target->query_condition("scorpion_poison"))
			target->apply_condition("scorpion_poison",0);
		if (target->query_condition("slumber_drug"))
			target->apply_condition("slumber_drug",0);
		if (target->query_condition("snake_poison"))
			target->apply_condition("snake_poison",0);
		if (target->query_condition("ss_poison"))
			target->apply_condition("ss_poison",0);
		if (target->query_condition("xx_poison"))
			target->apply_condition("xx_poison",0);
		if (target->query_condition("zhua_poison"))
			target->apply_condition("zhua_poison",0);
        if (target->query_condition("snake_poison"))
        {          target->clear_condition("snake_poison");}
        if (target->query_condition("wugong_poison"))
        {          target->clear_condition("wugong_poison");}
        if (target->query_condition("zhizhu_poison"))
        {          target->clear_condition("zhizhu_poison");}
        if (target->query_condition("xiezi_poison"))
        {          target->clear_condition("xiezi_poison");}
        if (target->query_condition("chanchu_poison"))
        {          target->clear_condition("chanchu_poison");}
        if (target->query_condition("qishang_poison"))
        {          target->clear_condition("qishang_poison");}
        if (target->query_condition("jy-poison"))
        {          target->clear_condition("jy-poison");}
        if (target->query_condition("xx_poison"))
        {          target->clear_condition("xx_poison");}
        if (target->query_condition("cold_poison"))
        {          target->clear_condition("cold_poison");}
        if (target->query_condition("flower_poison"))
        {          target->clear_condition("flower_poison");}
        if (target->query_condition("chilian_poison"))
        {          target->clear_condition("chilian_poison");}
        if (target->query_condition("yufeng_poison"))
        {          target->clear_condition("yufeng_poison");}
        if (target->query_condition("anqi_poison"))
        {          target->clear_condition("anqi_poison");}
       if (target->query_condition("yf_poison"))
        {          target->clear_condition("yf_poison");}
       if (target->query_condition("nx_poison"))
        {          target->clear_condition("nx_poison");}
       if (target->query_condition("x2_poison"))
        {          target->clear_condition("x2_poison");}
       if (target->query_condition("sanpoison"))
        {          target->clear_condition("sanpoison");}
       if (target->query_condition("insect_poison"))
        {          target->clear_condition("insect_poison");}
		message_combatd(msg, me, target);
	return 1;
}
