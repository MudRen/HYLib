// chixin-jian.c �����鳤��
// Made by deaner
// Modified by Venus Oct.1997

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int yunwu(object me, object victim, object weapon, int damage);

mapping *action = ({
   (["skill_name" : "��Ͷ���չ����",
     "action" : "$Nʹһʽ"+HIC"����Ͷ���չ���ա�"NOR+"����¶΢Ц������$wһ��������"
                "����������$n��$l",
     "dodge"  : 10,
     "force"  : 250,
     "damage" : 310,
     "lvl"    : 0,
     "damage_type":  "����"]),
   (["skill_name" : "ͻ�����������",
     "action" : "$Nʹһʽ"+HIC"��ͻ�������������"NOR+"���������������ж��䣬����$w"
                "��һ�����벻���ķ�λбб����$n��$l",
     "dodge"  : 20,
     "force"  : 170,
     "damage" : 335,
     "lvl"    : 10,
     "damage_type":  "����"]),
   (["skill_name" : "����ĺĺƵ˼��",
     "action" : "$Nʹһʽ"+HIC"������ĺĺƵ˼�䡻"NOR+"���������ߣ����׸���Ƭ�̣���"
                "������$w��Ȼ���ϣ�����$n��$l",
     "dodge"  : 20,
     "force"  : 175,
     "damage" : 320,
     "lvl"    : 20,
     "damage_type":  "����"]),
   (["skill_name" : "ǧ��濾�ֻ�ǿ�",
     "action" : "$Nʹһʽ"+HIC"��ǧ��濾�ֻ�ǿա�"NOR+"������һ�Σ����Ӷ��ϣ�����$w"
                "����һ������׼$n��$l��������",
     "dodge"  : 40,
     "force"  : 190,
     "damage" : 325,
     "lvl"    : 30,
     "damage_type":  "����"]),
   (["skill_name" : "�������������",
     "action" : "$Nʹһʽ"+HIC"��������������须"NOR+"��һ����������$n����Ӱ���棬"
                "����$w���Ȼ��������$n��$l��ȥ",
     "dodge"  : 60,
     "force"  : 100,
     "damage" : 325,
     "lvl"    : 40,
     "damage_type":  "����"]),
   (["skill_name" : "ȴ���칫������",
     "action" : "$Nʹһʽ"+HIC"��ȴ���칫��������"NOR+"��һ����������$w����б����"
                "��ֱָ$n��$l",
     "dodge"  : 50,
     "force"  : 130,
     "damage" : 30,
     "lvl"    : 50,
     "damage_type":  "����"]),
   (["skill_name" : "�����޶���˼��",
     "action" : "$Nʹһʽ"+HIC"�������޶���˼�ࡻ"NOR+"��΢΢һ��ת������$wȴ����"
                "���´���������$n��$l",
     "dodge"  : 40,
     "force"  : 150,
     "damage" : 30,
     "lvl"    : 60,
     "damage_type":  "����"]),
   (["skill_name" : "�˺������޾���",
     "action" : "$Nʹһʽ"+HIC"���˺������޾��ڡ�"NOR+"����ɫ΢�䣬���ж�Ȼ���������"
                "�ȣ�����$w��ƥ��������$n��$l",
     "dodge"  : 30,
     "force"  : 180,
     "damage" : 340,
     "lvl"    : 70,
     "damage_type":  "����"]),
   (["skill_name" : "��Ȼ����������",
     "action" : "$Nʹһʽ"+HIC"����Ȼ���������桻"NOR+"���������ף�����̾�˿���������"
                "Ө����������������$w�й�ֱ����Ѹ���ޱȵ���$n��$l��ȥ",
     "dodge"  : 20,
     "force"  : 200,
     "damage" : 335,
     "lvl"    : 80,
     "damage_type":  "����"]),
   (["skill_name" : "Ը�˳��ÿ��ź�",
     "action" : "$Nʹһʽ"+HIC"��Ը�˳��ÿ��źޡ�"NOR+"�������Ծ������$w�ڰ�������£�"
                "����һ����ɫ��������$n��$l",
     "dodge"  : 30,
     "force"  : 220,
     "damage" : 345,
     "lvl"    : 90,
     "damage_type":  "����"]),
   (["skill_name" : "����δ���ɰ�ͷ",
     "action" : "$Nʹһʽ"+HIC"������δ���ɰ�ͷ��"NOR+"������ಽ������$w���ּ���������"
                "��ৡ���һ����$n��$l��ȥ",
     "dodge"  : 65,
     "force"  : 240,
     "damage" : 350,
     "lvl"    : 100,
     "damage_type":  "����"]),
   (["skill_name" : "����������ǰԵ",
     "action" : "$Nʹһʽ"+HIC"������������ǰԵ��"NOR+"����ؼ���һ�����ֳ�ǰ����������"
                "$w��Ϊ�⻡��$n��$l��ȥ",
     "dodge"  : 40,
     "force"  : 260,
     "damage" : 350,
     "lvl"    : 110,
     "damage_type":  "����"]),
   (["skill_name" : "���鲻�Ƽ��Ƹ�",
     "action" : "$Nʹһʽ"+HIC"�����鲻�Ƽ��Ƹ֡�"NOR+"������Ծ�𣬲�����Ӱ������ȴ�ִ�"
                "����д��£�˫������$w�����Ʊ��˵ش���$n��$l",
     "dodge"  : 60,
     "force"  : 280,
     "damage" : 365,
     "lvl"    : 120,
     "damage_type":  "����"]),
   (["skill_name" : "�����칫������",
     "action" : "$Nʹһʽ"+HIC"�������칫�����ۡ�"NOR+"������$w���͡���һ��б������գ�"
                "�漴���¡��ৡ����£�����һ�����֣���$n��$l��ȥ",
     "dodge"  : 45,
     "force"  : 300,
     "damage" : 360,
     "lvl"    : 130,
     "damage_type":  "����"]),
   (["skill_name" : "�ճ��˻�����ʱ",
     "action" : "$Nʹһʽ"+HIC"���ճ��˻�����ʱ��"NOR+"������΢̧������$w���·�����"
                "����һ�ɾ��練��$n��$l",
     "dodge"  : 50,
     "force"  : 310,
     "damage" : 370,
     "lvl"    : 140,
     "damage_type":  "����"]),
   (["skill_name" : "��������鳤��",
     "action" : "$N�㾡ȫ�����"+HIC"����������鳤����"NOR+"����ɫʮ�ּ�������������"
                "����������$w���費ͣ��ȫ�������������˵Ľ����У�$n���ɺ�Ȼ��ֻ��$N"
                "����΢�䣬�����������ѱ���$n��$l",
     "dodge"  : 70,
     "damage" : 380,
     "force"  : 320,
     "lvl"    : 150,
     "damage_type":  "����"])
});

int valid_enable(string usage){return usage=="sword" || usage=="parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 900)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ��\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("chixin-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");
        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ�����鳤����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("chixin-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ĳ����鳤����\n");

        return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
        if(level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
       int i, level;
        string *msg1,*msg2;
        msg1 = ({
		HIW"$N����$w"+HIW"�������裬��������������ʵʵ�����˶�Ŀ���仯�Ź�֮����$n�������º�Ȼ��"NOR,
		HIW"$N����$w"+HIW"ԽʹԽ�죬һ�ס��ٱ�ǧ�ú�ɽ����ʮ��ʽ�������ƾ���ӿ��$n���ɵ�ĿΪ֮ѣ��"NOR,
		HIW"����$N����$w"+HIW"���б�ã�������ȣ��廨���ţ�������$n������ǰ����һƬ���������ȥ��"NOR,
        });
        msg2 = ({
		HIR"����һ�����Ѫ��$w"+HIR"�½��˳�����$n��Ų��Ծ�������мܣ�ʼ���Ѳ���$N�Ľ������֣���Ѫ���������ܽ�����һ����Ȧ��$N���Ѵ̳�һ����"NOR,
		HIY"$Nһ����ռ�Ȼ����������������һ��$w"+HIY"�������ߣ�������������$n�Ĺ����д�����ȥ��ֻ�Ƶ�$n�������ˣ�"NOR,
		HIY"$n����һ������֮�£��������ˣ�$N����$w"+HIY"������������������������������䣬�仯�켫��"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"����"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"����"]);
        }

    level   = (int) me->query_skill("chixin-jian",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    if( (int)me->query("qi") < 50)
        return notify_fail("�������Ŀǰû�а취��ϰ�����鳤����\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("chixin-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");
    if( (int)me->query("neili") < 60)
        return notify_fail("��������������޷���ϰ�����鳤����\n");
        
    me->receive_damage("qi", 40);
    me->add("neili", -55);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"chixin-jian/" + action;
}


int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n����$n�˿���һ��Ѫ����ӿȪ�����������ԭ��$p�н�������δ��������Ѫ�Ƶô��˿��м���������ȹ��죬�ֿɲ���\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+20);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("chixin-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$Nʩչ����������,$n����һ��,������$l�������Ѫ��!!\n";
        }
 
 
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "chixin-jian"
        && j > random(victim->query_skill("dodge",1))){
          switch(random(3)){
            case 0 :
               msg = HIW"$Nʩչ�����Ž�·�����������ճ��棡\n"NOR;
               msg+= HIW"$n�������ˣ�ȫ���мܣ��������У�\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N���²������Ų�����һ���Ӵ̳��ü�����\n"NOR;
               msg+= HIW"$n�����ֲ������һ�����飬��һ����ʵ������ͣ�¹��ƣ������Ż���\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N��۵糸������$n���ܣ�������������ֱ�����㲻��صķ���һ�㣡\n"NOR;
               msg+= HIW"$n����$Nת��תȥ����Ū���ۻ����ң�ҡҡ��׹��\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}