// jixue.c  Ѫ���� [��Ѫ��]
// coded by emnil@sj	2/5/2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit F_SSERVER;

void jixue(object me,object target,int times,int now);
 
int perform(object me, object target)
{
	object ob,weapon;
	string msg;
	int lvl,times,extra;
extra = me->query_skill("xue-dao",1);
    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"װ��������ʹ�á���Ѫ�񵶡���\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("xue-dao", 1) < 100 )
        return notify_fail(WHT"��Ѫ������������죬ʹ��������Ѫ�񵶡���\n"NOR);
    if ((int)me->query_skill("longxiang", 1) < 60 )
        return notify_fail(RED"�������������򲻹���ʹ��������Ѫ�񵶡���\n"NOR);
    if ((int)me->query("max_neili") < 600)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("neili") < 600)
    {
        return notify_fail(HIC"����������������û�ܽ�����Ѫ�񵶡�ʹ�꣡\n"NOR);
    }
    
	if( !me->is_fighting() )
		return notify_fail("����Ѫ�񵶡�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
 
	if((int)me->query_skill("xue-dao",1) < 120)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ�á���Ѫ�񵶡�! \n");

	if(me->query_temp("xs/jixue"))
		return notify_fail("������ʹ�á���Ѫ�񵶡�! \n");

	if((int)me->query_skill("longxiang",1) < 120)
		return notify_fail("��������������Ϊ������ Ŀǰ����ʹ�á���Ѫ�񵶡�! \n");

	if( me->query_skill_mapped("force") != "longxiang")
		return notify_fail("��������ʹ�õ��ڹ�ͬ���������������ִ�������ʹ������Ѫ�񵶡��ľ�����\n");

        if (me->query_skill("yujiamu-quan",1) < 120)
                return notify_fail("�����ڵĽ�����ĸȭ���㡣\n");
        if (me->query_skill("dashou-yin",1) < 120)
                return notify_fail("���������ڴ���ӡ���㡣\n");
        if (me->query_skill("xiangmo-chu",1) < 120)
                return notify_fail("�����ڵĽ�ս�ħ�Ʋ��㡣\n");
        if (me->query_skill("mingwang-jian",1) < 120)
                return notify_fail("�����ڵĲ������������㡣\n");
        if (me->query_skill("shenkong-xing",1) < 120)
                return notify_fail("�����ڵ�����в��㡣\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ������\n");
	if((int)me->query("neili")<500)
		return notify_fail("�������������\n"); 

	ob = me->select_opponent();
	lvl = me->query_skill("xue-dao",1);
	me->set_temp("xs/jixue",1);
	times = me->query("env/jixue");
	if(times < 1) times = 1;
	if(times > lvl/40) times = lvl/40;
	if(times > 7) times = 7;
if (extra> 200) extra=200;

    me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", extra*3);
msg = YEL "$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ��
��ס��Ӱ��$n��ͷ���䣬\n"NOR;
if (!target->is_busy()) target->start_busy(3);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -extra*3);
	
	msg = HIR"\n$N��ɫ��Ȼһ�䣬���������дʣ�ͬʱ��ת���У���֪��Ҫ��ʲô��\n\n"NOR;
	message_vision(msg, me);
	me->add("neili", -100);
me->start_busy(2);
//	me->start_perform(10,"��Ѫ��");

	call_out("jixue",0,me,ob,times,0);

	return 1;
}

void jixue(object me,object target,int times,int now)
{
	string msg,weaname;
	object weapon;
	int lvl,force,damage,attack,qi;

	if( !objectp(me) ) return;
	if( !objectp(target) || !me->is_fighting(target) || (now >= times) || (me->query("neili")<200) || 
	  (!objectp(weapon = me->query_temp("weapon"))) || ((string)weapon->query("skill_type")!="blade") ) {
		me->set_temp("xs/jixue",0);
                me->start_busy(1);
		if(living(me))
			message_vision(HIC"\n$N�����ջ��ھ�������Ҳ�ƺ�����Ѫɫ��\n"NOR, me);
		return;
	}

	weapon = me->query_temp("weapon");
	weaname = weapon->query("name");
	lvl = me->query_skill("xue-dao",1);
	force = me->query_skill("longxiang",1);

	now++;
	if(now <= 1)
		msg = HIR"\n$N��Хһ�����Ա����Կ��ֱۣ���ʱһ���Ѫ�ɽ���"NOR+weaname+HIR"֮�ϣ�"NOR+weaname+HIR"��������һ��Ѫɫ��";
	else
	if(now <= 3)
		msg = HIR"\n$N��Хһ�����Ա����Կ����ţ���ʱһǻ��Ѫ�ɽ���"+weaname+HIR"֮�ϣ�"NOR+weaname+HIR"����һ��Ѫɫ��";
	else
		msg = RED"\n$N��Хһ������ͷ�����Լ�һ������ʱһ����Ѫ�ɽ���"+weaname+RED"֮�ϣ�"NOR+weaname+RED"�������ͨ�죡����";
	
	attack = 7-now;
	damage = 8-now;
	if(me->query_temp("xs/longxiang")) {
		damage--;
		if(damage<2) damage=2;
		msg += "$N���������ھ����ڱ���֮�ϣ�";
	}
	msg += "\n"NOR;
	message_vision(msg, me);
	if(wizardp(me) ) tell_object(me,sprintf("damage:%d , attack:%d , qi:%d \n",force/damage,lvl/attack,-50*now));

	me->add_temp("apply/damage", 1000);
	me->add_temp("apply/attack", 100);
if (!target->is_busy()) target->start_busy(3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	me->add_temp("apply/damage", -1000);
	me->add_temp("apply/attack", -100);

	if(me->query("qi") < (60*now)) 
		qi = me->query("qi")-10;
	else
		qi = 60*now;
	if(qi<0) qi = 0;

	me->receive_damage("qi", qi/2);
	me->receive_wound("qi", qi/3);

	me->add("neili", -30*now);
	if(me->query("neili") < 0)	me->set("neili",0);

	call_out("jixue",2+random(3),me,target,times,now);
}
