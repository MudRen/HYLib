// perform.c

//inherit F_CLEAN_UP;
inherit F_SSERVER;
int main(object me, string arg)
{
object target;
	object weapon;
	string martial, skill;
	mapping prepare;
	
	seteuid(getuid());

	if( !target ) target = offensive_target(me);

        if (me->is_fighting())
{
	if( !target)
		return notify_fail("���ڲ���ʹ�����������\n");
if (me->is_fighting(target) )
{
	if( environment(target)!=environment(me))
		return notify_fail("��Ҫ��˭ʹ�����������\n");
}
}
	if( userp(me) && me->query_temp("combat_yield") )
	return notify_fail("�㲻�Ǵ򲻻�����?\n");
if (userp(me) && !me->query_skill_mapped("force"))
return notify_fail("��û���ڹ�����ʹ���а�!\n");
if (target && me)
{
if(!target->query_condition("killer") && environment(me)->query("no_fight"))
		return notify_fail("���ﲻ����򶷣�\n");
}
	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
	if (userp(me) && me->is_busy())
		return notify_fail("( ����һ��������û����ɣ������ù���)\n");

  if (me->is_perform()) return notify_fail("������ʹ��"+me->query_perform()+"��\n");

	if( !arg ) return notify_fail("��Ҫ���⹦��ʲô��\n");

        if( me->query_condition("no_perform") )
		return notify_fail("( ����Ϣ���ȣ���ʱ����ʩ���⹦��)\n");

	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else {
			prepare = me->query_skill_prepare();
			if (sizeof(prepare)) martial = keys(prepare)[0];
			else
			martial = "unarmed";
		}
	}

	notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
if( environment(me)->query("magicroom") && martial != "spells"
&& me->is_fighting() && userp(me))
{
if ( me->query("neili") < me->query("max_neili")/3)
me->add("neili",-me->query("neili")/4);
else me->add("neili",-me->query("max_neili")/4);
tell_object(me,"һ�������������������Ҫ�õľ�ѧ�����þ�ȫ������ʹ�����õľ���������\n");
tell_object(me,"����������磬ֻ��ʹ��ħ��������\n");
}
	if( stringp(skill = me->query_skill_mapped(martial))
	&& SKILL_D(skill)->perform_action(me, arg) ) {
		if( random(120) < (int)me->query_skill(skill) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	if (sizeof(prepare) > 1) {
		martial = keys(prepare)[1];
		if( stringp(skill = me->query_skill_mapped(martial))
		&& SKILL_D(skill)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(skill, 1) )
				me->improve_skill(skill, 1, 1);
			return 1;
		}
	}
	if( stringp(skill = me->query_skill_mapped("parry"))
	&& SKILL_D(skill)->perform_action(me, arg) ) {
		if( random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	if( stringp(skill = me->query_skill_mapped("dodge"))
	&& SKILL_D(skill)->perform_action(me, arg) ) {
		if( random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	return 0;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

yong parry.yi

or
yong chan

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
