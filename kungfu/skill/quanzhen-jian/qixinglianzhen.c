#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
string *sword = ({
	HIY"$N̤���ţ���ƫ�棬������˼�����һ�������ޱȵġ��ֻ�������������ʵ�������д�ȥ��"NOR,
	HIC"$Nʹһ�С���������������������Ʈ�����н�����ʵʵ�ó����㺮��������С�"NOR,
	HIB"$N����һת����Ȼһʽ���ɨҶ����������콣Ӱ��Ю�ž�����ǰɨȥ��"NOR,
	HIG"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ�����ʹ��������ػ�����С�"NOR,
	HIW"$N�������Ž���������̤��һ�С������롱����б�̡�"NOR,
	HIM"$N��ǰ��ȥһ�󲽣�ʹ����̽�������������н����һ������Ѹ�����׻�����"NOR,
	HIY"$N����һ������һʱ�������仨�������ó���㽣����ƮȻ�̳���"NOR,
	HIR"$N���н�һָ���������࣬һʱ������Į�����������������"NOR,
	RED"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ����ս���һ�С���׹��������������Ϣ�ع�����"NOR,
	YEL"$N���һ����һ�С��׺羭�졹��������㻮��һ����Բ�����¡�"NOR,
	GRN"$N��Ȼ���θ߸�Ծ��ʹ�����˼����ġ������н��ó����컨�꣬Ѹ�����������"NOR
});

string *zhen =  ({
	HIG"������󷨹����ƶ����������಻����˲�佫����Χ�����ġ�"NOR,
	HIC"����������ƺ��ǰ�������������ӣ������ۻ����ң������ʧ��"NOR,
	GRN"ֻ��������󰵺����а���֮�������˲������������ϵ������޷죬����֮������̾Ϊ��ֹ��"NOR,
	HIW"�������Խ��ԽС�����ν������˳�һ��������룬��������Ϣ֮�С�"NOR
});
	string *style = ({
HIR "���������$N̽������$w�������Х������$n��"NOR,
HIB"������Ϫ����$N����$w������Ӱ�ع⣬��$n����Χס��"NOR,
HIY"������Ȼ����$N��ǰһ�ݣ�����$w��һ��״����$n���˹�ȥ��"NOR,
HIG"������λ����$N��������������λ������$wͷβ������ִ�$n������Ҫ����"NOR,
HIM"����Ѫ�ȣ���$N����$wһ�٣���������������$n����ָ��"NOR,
HIW"��Ȼ�޴룭��$N����������Ծ������$w���ƶ�����������$n��ȥ��"NOR,
HIW"��Ȼ�޴룭��$N����������Ծ������$w���ƶ�����������$n��ȥ��"NOR,
HIC"һ����Ե����$N��Ӱ����$n�����ζ�������$w������ɨ��$n�����ţ�"NOR});

	object ob,*obs;
	if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) )
		return notify_fail("ֻ����Ӳſ��Է�����ʽ��\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("��Ҫ����������Ϊ�ڹ������á�\n");
	if(me->query_skill_mapped("array") != "qixing-array") 
		return notify_fail("��Ķ���û���ñ���������\n");
	if(me->query_skill("qixing-array",1)<sizeof(obs)*10)
		return notify_fail("����󷨲�����\n");
	if(sizeof(obs) >=7 )
		return notify_fail("��������߸��ˣ���\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
        if(obs[i]->query("neili") < 300) return notify_fail("�������������������!\n");
	if(!obs[i]->query_skill("quanzhen-jian",1)) return notify_fail("����������˲���ȫ�潣����\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "sword") return notify_fail("��Ķ���������û���ý�����\n");
	if(obs[i]->query_skill_mapped("sword") != "quanzhen-jian") return notify_fail("��Ķ���������û����ȫ�潣����\n");
	}	
        message_vision(HIM"$NͻȻ�����ƶ���������ȫ�������ռλ�ã����ҷֿ������ǰڵġ���������󷨡�\n"NOR, me);
	message_vision(HIY+"\n\n$N�ߺ�һ���������������������ߣ����ǣ����󣭣�����\n"+HIW+"--------------------------------------�������󣡣�\n\n"NOR,me);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = style[i];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", 100);
        obs[i]->add_temp("apply/damage", 2*extra);
	target->start_busy(3);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
if (obs[i]->query("qi") < obs[i]->query("max_qi")*2)
{
message_vision(HIG"$N���˺�����˺ܶ࣡��\n" NOR,obs[i],target);
obs[i]->add("qi", obs[i]->query("max_qi")/2);
if (obs[i]->query("eff_qi") < obs[i]->query("max_qi"))
obs[i]->add("eff_qi", obs[i]->query("max_qi")/2);
}
	obs[i]->fight_ob(target);	
	obs[i]->add_temp("apply/attack", -100);
	obs[i]->add_temp("apply/damage", -2*extra);
        obs[i]->add("neili",-100);
	obs[i]->start_busy(2);
	}
message_vision(" "+ zhen[random(4)]+"\n", me);
if (me->query_skill("qixing-array",1) > 250)
{
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = sword[random(10)];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", 100);
        obs[i]->add_temp("apply/damage", 2*extra);
	target->start_busy(3);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
if (obs[i]->query("qi") < obs[i]->query("max_qi"))
{
message_vision(HIG"$N���˺�����˺ܶ࣡��\n" NOR,obs[i],target);
obs[i]->add("qi", obs[i]->query("max_qi")/2);
if (obs[i]->query("eff_qi") < obs[i]->query("max_qi"))
obs[i]->add("eff_qi", obs[i]->query("max_qi")/2);
}
	obs[i]->fight_ob(target);	
	obs[i]->add_temp("apply/attack", -100);
	obs[i]->add_temp("apply/damage", -2*extra);
        obs[i]->add("neili",-100);
	obs[i]->start_busy(2);
}
}

if (random(2)==1)
message_vision(HIG"\n�����������һ�ݣ�ʹһ�С��ս�ʽ������������һ��������������һ�����˳���������󡹡�\n"NOR, me);
else message_vision(HIG"\n�����������һ�ݣ�ʹһ�С���ɽʽ������ȭ����һȦ������������һ�����˳���������󡹡�\n"NOR, me);
	return 1;
}
