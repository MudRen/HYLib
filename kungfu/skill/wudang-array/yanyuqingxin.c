#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = ({
HIR"�����������$N�ֳ�$w��ǰ����һ���裬����������$n��"NOR,
HIB"�������죭��$N������ס$w����һ�����磬��ס$nȫ�����䶯�����ã�"NOR,
HIY"���ܹ��ݣ���$N��ǰһ�ݣ����˰벽��ͻȻһ����������������$w��$n���˹�ȥ��"NOR,
HIG"������ǣ����$Nͻ���������̽���$w��������ִ�$n������Ҫ����"NOR});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���������ģ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
	if(me->query_skill_mapped("array") != "wudang-array") 
		return notify_fail("��Ķ���û��������������\n");
	if(me->query_skill("wudang-array",1)<sizeof(obs)*20)
		return notify_fail("����󷨲�����\n");
	if(sizeof(obs) >=4 )
		return notify_fail("��������ĸ��ˣ���\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
	if(!obs[i]->query_skill("wudang-array",1)) return notify_fail("����������˲�������������\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "sword") return notify_fail("��Ķ���������û���ý�����\n");
	if(obs[i]->query_skill_mapped("array") != "wudang-array") return notify_fail("��Ķ���������û�������������󷨣�\n");
	}	
	message_vision(HIG+"ֻ��$N������ˣ��������ų����������󷨣���ͼ��[��������]������$n����\n"NOR,me,target);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = style[i];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", extra);
        obs[i]->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	obs[i]->kill_ob(target);	
	obs[i]->add_temp("apply/attack", -extra);
	obs[i]->add_temp("apply/damage", -extra);
	obs[i]->start_busy(2);
	}
	return 1;
}
