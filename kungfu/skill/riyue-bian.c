// riyue-bian.c ���±޷�
// modified by Venus Oct.1997

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N����$w�ӳ���$w�Ƶ��漱��ȴ�Ǿ��޾��磬��$n$l���Ӷ���������Ѳ�����",
        "dodge":  5,
        "damage": 260,
        "force" : 160,
        "lvl" : 33,
        "damage_type":  "����"
]),
([      "action": "$N����һ����$wֱ��������ײ��$n���ţ��鶯���ͣ�����һ��������צ��ī������",
        "dodge": 10,
        "damage":  295,
        "force" : 320,
        "lvl" : 63,
        "damage_type":  "����"
]),
([      "action": "$N$w������ת������ԲȦ���Ӱ������$nͷ�����£������������ɣ��ھ������ۺ��ޱ�",
        "dodge":  15,
        "damage": 220,
        "force" : 480,
        "lvl" : 93,
        "damage_type":  "����"
]),
([      "action": "$N���˸վ���$w����������ֱ����ɽ����һ�㣬��������˷���ȥ����ʱ�ȵ�$n��������",
        "dodge":  15,
        "damage": 240,
        "force" : 520,
        "lvl" : 124,
        "damage_type":  "����",
]),
([      "action": "$N����һ����$w��$n�ؿڵ㵽������һ����ֱ�ı��У��糤ì����˰������̶�������������֮��",
        "dodge":  15,
        "damage": 260,
        "force" : 400,
        "lvl" : 185,
        "damage_type":  "����",
]),
([      "action": "$N�����ھ������߶����ڹ�ʩչ�������쾡�£�$w��Х��������$n���ŵ�ȥ������δ����$w����Ю��������$nһ������",
        "dodge":  15,
        "damage": 240,
        "force" : 540,
        "lvl" : 205,
        "damage_type":  "����",
]),
([      "action": "$N����$w�������裬���������Ҳ�����Ӱ�ݺᣬ�����ƻã�������о�ʽ��ÿһʽ�ж�������ʮ�б仯����ʮ��ɱ��",
        "dodge":  15,
        "damage": 270,
        "force" : 600,
        "lvl" :  205,
        "damage_type":  "����",
]),
([      "action":      "$N����������һ��"+(order[random(13)])+"����ʯʽ��"NOR"������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
        "dodge":       10,
        "damage":      200,
        "force" : 300,
        "lvl" :        0,
        "skill_name" : "��ʯʽ",
        "damage_type": "����"
]),
([      "action":      "$N����һת��һ��"+(order[random(13)])+"���ϴ�ʽ��"NOR"������$w��������ڿ�һ���͵���$n��ͷ����",
        "dodge":       20,
        "damage":      200,
        "force" : 300,
        "lvl" :        60,
        "skill_name" : "�ϴ�ʽ",
        "damage_type": "����"
]),
([      "action":      "$N������ң�һ��"+(order[random(13)])+"������ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "dodge":       40,
        "damage":      300,
        "force" : 300,
        "lvl" :        90,
        "skill_name" : "����ʽ",
        "damage_type": "����"
]),
([	"action":"$N������ң�һ��"+(order[random(13)])+"���ֺ�ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":       50,
	"damage":      400,
	"force" : 300,
	"lvl" :        100,
	"skill_name" : "�ֺ�ʽ",
	"damage_type": "����"
]),
([	"action":"$N������ң�һ��"+(order[random(13)])+"���ѿ�ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":       60,
	"damage":      500,
	"force" : 300,
	"lvl" :        110,
	"skill_name" : "�ѿ�ʽ",
	"damage_type": "����"
]),
([	"action":"$N������ң�һ��"+(order[random(13)])+"��������ա�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":       60,
	"damage":      600,
	"force" : 300,
	"lvl" :        120,
	"skill_name":  "�������",
	"damage_type": "����"
]),
([	"action":"$N������ң�һ��"+(order[random(13)])+"����շ�ħ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":       70,
	"damage":      700,
	"force" : 300,
	"lvl" :        130,
	"skill_name" : "��շ�ħ",
	"damage_type": "����"
]),
([	"action":"$N������ң�һ��"+(order[random(13)])+"�����ޱߡ�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":       100,
	"damage":      800,
	"force" : 300,
	"lvl" :        200,
	"skill_name" : "���ޱ�",
	"damage_type": "����"
]),
([     "action": "$N����������һʽ"+(order[random(13)])+"�������ɴ̡�"NOR"��������̧��$w�������裬���������Ҳ���ǰ�����ƣ�����մճ��ɢ",
       "dodge": 15,
       "damage": 270,
       "force" : 300,
       "lvl" : 0,
       "skill_name" : "�����ɴ�",
       "damage_type":  "����"
]),
([     "action": "$Nһʽ"+(order[random(13)])+"��Ŀ�����̡�"NOR"������$w�ж��ñ�ֱ�������ڡ�������$n���̶�������Ю��������$nһ������",
       "dodge": 10,
       "damage": 260,
       "force": 200,
       "lvl" : 30,
       "skill_name" : "Ŀ������",
       "damage_type":  "����"
]),
([     "action": "$N�ھ���������$w����ת������ԲȦ��һʽ"+(order[random(13)])+"��������̡�"NOR"��Ծ��Ӱ������$n$l����",
       "dodge":  20,
       "damage": 250,
       "force":  300,
       "lvl" : 60,
       "skill_name" : "�������",
       "damage_type":  "����"
]),
([     "action": "$N����������һʽ"+(order[random(13)])+"����¥�Ǵ̡�"NOR"��$w��$n��ǰ��Ȧ�¹���������ת��������������ʽ����Ȼ��$n$l����������",
       "dodge": 20,
       "damage": 380,
       "force": 200,
       "lvl" : 90,
       "skill_name" : "��¥�Ǵ�",
       "damage_type":  "����"
]),
([     "action": "$Nһ���ߺȣ�����������һʽ"+(order[random(13)])+"�������Ӵ̡�"NOR"��$w����ת������Ӱ�ݺᣬֱ����Բ��Բ����ֱ�������ƻã�����$n",
       "dodge": 25,
       "damage": 350,
       "force": 300,
       "lvl" : 120,
       "skill_name" : "�����Ӵ�",
       "damage_type":  "����"
]),
([     "action": "$N���ذα�������׹�⣬һʽ"+(order[random(13)])+"�������̡ܴ�"NOR"�������鶯���ͣ���ʵ����������������˷���$n��ѹ��ȥ",
       "dodge": 25,
       "damage": 320,
       "force": 350,
       "lvl" : 150,
       "skill_name" : "�����ܴ�",
       "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry");
 }

int valid_learn(object me)
{
    object weapon;

    if( (int)me->query("max_neili") < 500 )
       return notify_fail("����������㣬û�а취�����±޷�, ����Щ���������ɡ�\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
       return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");
       if(!me->query("family") || me->query("family/family_name")!="������" )
               return notify_fail("�㲻�����ֵ��ӣ�������������±޷���\n");

         if((int)me->query_skill("shaolin-shenfa",1) <=120)
      		return notify_fail("�������������㣬�����������±޷���\n");

         if((int)me->query_skill("yizhi-chan",1) <=120)
      		return notify_fail("���һָ�����㣬�����������±޷���\n");

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

mapping query_action(object me)
{
        int i,j, level;
     
        level   = (int) me->query_skill("riyue-bian",1);
        if (random(level) > 270 && me->query("neili") > 800 ){
        me->add("neili", -50);
        return ([
        "action":HIW"$N����������$w"NOR+HIW"�Ӷ�ʱ������Ϣ���������տ�����������������¶��ǣ�$n�����������������״����һ��Ϯ�����Ⱦ��ް������"NOR,
        "force" : 520+(level/5)+random(level/2),
        "dodge" : 0,
        "parry" : 0,
        "damage" : 550+random(level/3),
        "damage_type":"����",
        ]);
}
        if (random(me->query_str()) >= 35 && me->query_skill("riyue-bian",1) > 120 &&
             me->query_skill("parry",1) > 120 &&
             me->query("neili") > 1000 && random(me->query("jiali")) >= 20 &&
             me->query("jing")>300) {
                me->add("jing",-8);           
                me->add("neili", -30);
                return ([
                "action": HIR "$N����һ�������������$w������º�$n����һ��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��"NOR,
                "force": 600,
                "dodge": 25,
                "damage" : 600,
                "damage_type": "����"]);
        }
           if (random(me->query_str()) >= 39 && me->query_skill("riyue-bian",1)> 150 &&
                me->query_skill("parry",1) > 150 && random(me->query("jiali")) >= 20 &&
                me->query("neili") > 1500 &&
                me->query("jing")>500) {
                me->add("jing",-10);            
                me->add("neili", -50);
                return ([
                "action": HIR "$N������$w������Ȧ������$nԽתԽ����ԽתԽ�죬$p��ʱ�����������׵���ת�˼����ۿ���Ҫˤ����"NOR,
                "force": 520,
                "dodge": 35,
                "damage" : 580,
                "damage_type": "ˤ��"]);
        }
      
          if (me->query_temp("riyue"))
                {                
                    return ([  
                    "action" : HIR+action[j]["action"]+NOR,
                    "force" : (me->query("gender")=="����"?action[j]["force"]:action[j]["force"]/2)+me->query_str()*5,
                    "dodge":(me->query("gender")=="����"?action[j]["dodge"]:action[j]["force"]+10)+random(15),
                    "lvl" : action[j]["lvl"],
                    "weapon" : action[j]["weapon"],
                    "damage_type" : action[j]["damage_type"],
                    ]);
               }        


       level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("����������������±޷���\n");
    me->receive_damage("qi", 5);
    me->receive_damage("jing", 10);
    return 1;
}


string perform_action_file(string action)
{
       return __DIR__"riyue-bian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("riyue-bian",1)) > 130 ) 
{
	  victim->receive_wound("qi", (damage_bonus-60)/2);
        return HIY "$n���޷�ɨ�У�һ���ʹ��\n" NOR;
}
}
