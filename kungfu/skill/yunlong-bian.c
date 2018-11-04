// yunlong-bian.c �����޷�

#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([ "action": "$N����һ�ݣ�Ծ�ڰ�գ�һʽ"+(order[random(13)])+"���ʷ����ࡹ"NOR"������$w�������£������鶯֮��������$n$l",
   "dodge": 5,
   "damage":230,
   "force": 200,
   "lvl" : 5,
   "skill_name" : "�ʷ�����",
   "damage_type":  "����"
]),
([ "action": "$N���绬��������$wһ����һʽ"+(order[random(13)])+"�����չ�᡹"NOR"��Ѹ���ޱȵطִ��������࣬$n��ʱ����֧穣������ֽ�",
   "dodge": 5,
   "damage":250,
   "force": 250,
   "lvl" : 25,
   "skill_name" : "���չ��",
   "damage_type":  "����"
]),
([ "action": "$N������ע��$w�����ʹ��һʽ"+(order[random(13)])+"������Ϸ�"NOR"��$w��ز���裬ֱ�������ƿ�һ�����$n",
   "dodge": 10,
   "damage":280,
   "force": 300,
   "lvl" : 45,
   "skill_name" : "����Ϸ��",
   "damage_type":  "����"
]),
([ "action": "$Nһ����Х������$wһ��"+(order[random(13)])+"�����ɷ��衹"NOR"�����������Ӱ����ǵص���$n�������Ƶ�����֮��",
   "dodge": -10,
   "damage":310,
   "force": 350,
   "lvl" : 65,
   "skill_name" : "���ɷ���",
   "damage_type":  "����"
]),
([ "action": "$N��¶΢Ц��ǰһ��������$w�������ʹ��һʽ"+(order[random(13)])+"��������项"NOR"������ƽ������������˿������",
   "dodge": 1,
   "damage":330,
   "force": 300,
   "lvl" : 85,
   "skill_name" : "�������",
   "damage_type":  "����"
]),
([	"action":		"$N����һ�һ��"+(order[random(13)])+"������ٵء�"NOR"������$w���ñ�ֱ����׼$n��ͷ����",
	"force":		300,
	"dodge":		10,
	"damage":		320,
	"lvl" : 0,
	"skill_name" : "����ٵ�",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ��"+(order[random(13)])+"�������ĺ���"NOR"������$w��������ڿ�һ���͵ػ���$n̫��Ѩ",
	"force":		350,
	"dodge":		10,
	"damage":		340,
	"lvl" : 10,
	"skill_name" : "�����ĺ�",
	"damage_type":	"����"
]),
([	"action":		"$N৵�һ�����ޣ�һ��"+(order[random(13)])+"��������ˮ��"NOR"������$w���ñ�ֱ������$n˫��",
	"force":		300,
	"dodge":		30,
	"damage":		360,
	"lvl" : 20,
	"skill_name" : "������ˮ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ��"+(order[random(13)])+"�����Ƽ��ա�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"force":		300,
	"dodge":		40,
	"damage":		380,
	"lvl" : 30,
	"skill_name" : "���Ƽ���",
	"damage_type":	"����"
]),
([	"action":		"$N��������һ��"+(order[random(13)])+"����ɽ��ʯ��"NOR"������$w��һ��ͭ����ֱ����$n",
	"force":		350,
	"dodge":		50,
	"damage":		300,
	"lvl" : 40,
	"skill_name" : "��ɽ��ʯ",
	"damage_type":	"����"
]),
([	"action":		"$N����һ�ӣ�һ��"+(order[random(13)])+"�����Χ����"NOR"������$wֱ����$n����",
	"force":		300,
	"dodge":		20,
	"damage":		220,
	"lvl" : 50,
	"skill_name" : "���Χ��",
	"damage_type":	"����"
]),
([	"action":		"$N�߸�Ծ��һ��"+(order[random(13)])+"����Į���̡�"NOR"������$w��ֱ��$n��ͷ����",
	"force":		350,
	"dodge":		50,
	"damage":		340,
	"lvl" : 60,
	"skill_name" : "��Į����",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("��������񹦻��̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

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
	level   = (int) me->query_skill("yunlong-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weap,weap1;
        weap = victim->query_temp("weapon");
		weap1 = me->query_temp("weapon");
if (!weap) return;
                if( (me->query_skill("yunlong-bian") > 160) && (me->query("neili") > 100)
                         && (victim->query_temp("weapon")) 
                         && random(10)>4)
                  {
						 message_vision(HIY "ֻ��$N���ٻ���" + weap1->name() + "��ת����������СȦ�ӣ�������֮����ס�Է���" + weap->name() +"��\n" NOR, me );	
                         victim->start_busy(3);
						 if (random(me->query_str()) > victim->query_str()/2 )
                        {     	
				        message_vision(HIY "$N�����ֱ�����һק��" + weap->name()
                                + "ȴ�޷���"+weap1->name()+"�Ĳ������ѿ����鼱֮��ֻ�÷��������еı��С�\n" NOR, victim );
                        weap->move(environment(me));
						victim->reset_action();

						} else {
						message_vision(HIY "$N�����ɾ���" + weap->name()
                                + "˳�ŷ��������ת���£��⿪��"+weap1->name()+"�Ĳ��ơ�\n" NOR, victim );
                        victim->add("neili",-50);
						}
						me->add("neili", -50);
                 }
				       return 1;

      
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N���־۳ɻ�צ״! ����Ѫ��ץ��һ��ץס$n��"+ xue_name[random(sizeof(xue_name))] +NOR;

           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           return j;
}      

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������޷���\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-bian/" + action;
}
