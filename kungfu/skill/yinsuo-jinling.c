// yinsuo-jinling.c ��������
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":""+(order[random(13)])+"����$w,ͻȻ֮��,˿������,��һ����������$n"NOR"",
        "force" : 90,
        "dodge" : 40,
        "damage": 340,
	"lvl":     0,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$N���ϵ�$w�ܳ�����$n������Ѹ���ޱȵ�һ�㣬"NOR"",
        "force" : 110,
        "dodge" : 30,
        "damage": 350,
        "lvl":    10,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"�����$N�����ϣ�$w�Ƶ�$n����󣬼���$n��$l"NOR"",
        "force" : 140,
        "dodge" : 60,
        "damage": 370,
        "lvl": 20,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������"NOR"",
        "force" : 180,
        "dodge" : 40,
        "damage": 360,
        "lvl": 30,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$N����Ʈ����������ȣ�ת�˼�ת����Ȼ$w����$n��$lѨ��"NOR"",
        "force" : 230,
        "dodge" : 40,
        "damage": 340,
        "lvl":60,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$Nһ����Ц�������Ծ,����$w������Ȱ����$n��$l"NOR"",
        "force" : 290,
        "dodge" : 50,
        "damage": 390,
        "lvl":75,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$N����$nת�˼���Ȧ,����$w�����ͳ�,����$n��$l"NOR"",
        "force" : 360,
        "dodge" : 30,
        "damage": 450,
        "lvl": 90,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ���$Nȴ�ƴ�δ�뿪,��$w�ѵ���$n��ǰ"NOR"",
        "force" : 440,
        "dodge" : 80,
        "damage": 420,
        "lvl":100,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$N����ˣ�$n��׷������ͻȻ������һ̧������$wֱ��$n��$l"NOR"",
        "force" : 530,
        "dodge" : 40,
        "damage": 550,
        "lvl":120,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$n��Ҫ�嵽$N��ǰ��$N����$wֱ��$n�ؿ�̴��Ѩ��$n��æ�мܣ�����$N��$wͻȻת�����$l"NOR"",
        "force" : 630,
        "dodge" : 4,
        "damage": 690,
        "lvl":140,
        "damage_type":  "��Ѩ"
]),
([      "action":""+(order[random(13)])+"$N����$w���裬$n��ǰ�·�ͻȻ�������߰���$wһ�����$n"NOR"",
        "force" : 640,
        "dodge" : 60,
        "damage": 690,
        "lvl":150,
        "damage_type":  "��Ѩ"
]),
});


int valid_enable(string usage) { return (usage == "whip") || (usage == "parry")
; }

//int valid_enable(string usage) 
//{ 
//    return usage == "whip"; 
//}
int valid_learn(object me)
{
        object weapon;
        int t = 1, j;
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������㣬û�а취����������, ����Щ���������ɡ�\n");

        if ((int)me->query_skill("yunv-xinfa", 1) < 50)
                return notify_fail("�����Ů�ľ����̫ǳ��\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("�������һ��������������������塣\n");
		
        return 1;
}

int practice_skill(object me)
{
        object weapon;

if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "whip")
           return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
           return notify_fail("��������������������塣\n");
        me->receive_damage("qi", 30);
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
        level   = (int) me->query_skill("yinsuo-jinling",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
string perform_action_file(string action)
{
//        if ( this_player()->query_skill("yinsuo-jinling", 1) >= 50 )
                return __DIR__"yinsuo-jinling/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{      
	object weap,weap1;      
	weap = victim->query_temp("weapon");      
	weap1 = me->query_temp("weapon");     

	if( (me->query_skill("yinsuo-jinling") > 150) 
		&& (me->query("neili") > 700) 
		&& (victim->query_temp("weapon")) 
		&& random(10) > 6)
		{       
		message_vision(HIW "ֻ��$N����" + weap1->name() + "��ת����������СȦ�ӣ�������֮����ס��$n��" + weap->name() +"��\n" NOR, me, victim  );            
		if (!victim->is_busy()) victim->start_busy(1);             

		if (random(me->query_str() + me->query_dex()) > victim->query_str() + me->query_dex()){
		message_vision(HIY "\n$N�����ֱ�����һק��" + weap->name()  + "ȴ�޷���"+weap1->name()+"�Ĳ������ѿ����鼱֮��ֻ�÷��������е�" + weap->name()  + "��\n" NOR, victim );       
		weap->move(environment(me));       
		victim->reset_action();       
		} 

		else {      
		message_vision(HIY "\n$N�����ɾ���" + weap->name()   + "˳�ŷ��������ת���£��⿪��"+weap1->name()+"�Ĳ��ơ�\n" NOR, victim );      
		if (!victim->is_busy()) victim->start_busy(3);
		victim->add("neili", -50);      
		}      

	me->add("neili", - 20);      
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
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"�������ߣ��ж����������಻����һ��δ�ϣ������� !$n˫��һ����֪���룡\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"Ŀ��һ����һ��������ӳ� !$n һ�����ģ����������˼�ö��\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
