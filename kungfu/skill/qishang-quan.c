// qishang-quan.c -����ȭ
// pal 1997.05.26
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N������ɽ��һʽ"+(order[random(13)])+"���������"NOR"��˫ȭ���ƶ���������$n��$l",
	"force" : 180,
	"dodge" : 50,
        "parry" : 20,
        "damage": 260,

	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�������أ�����������һʽ"+(order[random(13)])+"��ľ�ѳ��ۡ�"NOR"��������$n�Ƴ�",
	"force" : 200,
	"dodge" : 50,
        "parry" : 20,
        "damage": 200,
	"lvl" : 10,
	"skill_name" : "ľ�ѳ���",
        "damage_type" : "����"
]),
([	"action" : "$N�������飬����������ޣ�һʽ"+(order[random(13)])+"��ˮ�����¡�"NOR"����$n�޿ɶ���",
	"force" : 230,
	"dodge" : 55,
        "parry" : 20,
        "damage": 200,
	"lvl" : 20,
	"skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ��һʽ"+(order[random(13)])+"���𺣵�ɽ��"NOR"��˫ȭ���ջ��£��Ʋ��ɵ�",
	"force" : 270,
	"dodge" : 55,
        "parry" : 20,
        "damage": 200,
	"lvl" : 30,
	"skill_name" : "�𺣵�ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����һʽ"+(order[random(13)])+"���������"NOR"����ȭ���¶��ϣ�����$n",
	"force" : 320,
	"dodge" : 50,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��һʽ"+(order[random(13)])+"������Ҳҡ�"NOR"������$n����ǰ���",
	"force" : 380,
	"dodge" : 55,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "����Ҳ�",
        "damage_type" : "����"
]),
([	"action" : "$N���λ�λ������ȭ����һʽ"+(order[random(13)])+"���������ա�"NOR"������˷�����ȭӰ",
	"force" : 450,
	"dodge" : 55,
	"damage": 55,
        "parry" : 20,
        "damage": 250,
	"lvl" : 54,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ"+(order[random(13)])+"�����߽��ˡ�"NOR"����Ȼ����$n��ǰ��",
	"force" : 530,
	"dodge" : 50,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "���߽���",
        "damage_type" : "����"
]),
([      "action" : "$N�ڳ��б��ߣ����ּȿ��Һݣ��������죬һȭ��׼��$n���ϵ�$lֱ������",
        "force" : 190,
        "dodge" : 55,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������֮��������һ������$n�ֱۣ��������һȭ���ѽ��ʵʵ����$n$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 20,
        "damage": 260,

        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N��$n����˵������Ȼ��ȭ��ȥ��ֻ�����һ�����죬��һ�������Ǵ���$n$l��",
        "force" : 260,
        "dodge" : 50,
        "parry" : 20,
        "damage": 250,

        "lvl" : 15,
        "damage_type" : "����"
]),
([      "action" : "$Nȭ����磬���������ȭ��������$n���ϣ���ȴ�Ʋ���ʹ�������������壬��˿����",
        "force" : 210,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ���࣬һ��ߺ�ȣ�����ƾ�մ��˸��������������У�һȭֱ������$n��$l֮��",
        "force" : 400,
        "dodge" : 15,
        "parry" : 20,
        "damage": 350,

        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N���˼�������������һ�����ֱ۹Ǹ�����죬��������һ����һȭ����$n$l",
        "force" : 300,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,

        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$Nһȭ�����������ֱۣ��ַ�ȭ������һ����������ת��������ǰ��ͦȭ�ͻ�",
        "force" : 270,
        "dodge" : 55,
        "parry" : 20,
        "damage": 300,
        "lvl" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ��һ�ȭ����п�ɽ������һ���������ڣ�ֱ����$n��$n�ؿ�һ����ֻ��������Ż",
        "force" : 350,
        "dodge" : 15,
"parry" : 20,
    "damage": 350,

        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N���һ����˫ȭ�������������δ��ȭ�ϰ�������ŭ�����࣬��Х���Ϯ��$n",
        "force" : 400,
        "dodge" : 55,
"parry" : 20,
    "damage": 380,

        "lvl" : 85,
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ΢�أ�����Ʈ������ƮƮ������ȭ��ȴ�ǰ����ϢҲ�ޣ�$n��ز��΢����壬ȭ��������Ϯ�����",
        "force" : 300,
        "dodge" : 50,
"parry" : 20,
    "damage": 380,

        "lvl" : 75,
        "damage_type" : "����"
]),
});

string  *msg = ({
""+(order[random(13)])+"$Nһȭ������ȭ���о����и������ֲ�ͬ�ľ������ֻ�$n��ȫ��������ʮ����ҪѨ"NOR"",
""+(order[random(13)])+"$N����һ��������˫ȭƽ�죬����������������ȭ���������ֲ�֮ͬ������$n��$l"NOR"",
""+(order[random(13)])+"$NĬ���񹦣�˫ȭ�����޶���ͻȻ�ڿ����г������ֲ�ͬ�ľ�����Ȼ����$n��ǰ��"NOR"",
""+(order[random(13)])+"$N��ȭһ�գ�Ĭ����Ϣ�����ֲ�ͬ�������Ŵ����ȭ���ֵ��ֿ�Ļ���$n��$l"NOR"",
""+(order[random(13)])+"ֻ��$N˫Ŀ��������������Ȼ���͵Ĵ����һ�����������£��������ޱ�֮��������$n��ȫ��"NOR"",
""+(order[random(13)])+"$Nһ����Х��˫Ŀ��죬ȭ·�󿪴��أ�ÿһȭ������������ŭ��ʯ���쾪���Ժ������ڼ������Ĵ�����"NOR"",

});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 80)
		return notify_fail("��ľ����񹦻�򲻹����޷�ѧ����ȭ��\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("����ѹ�ӥצ�����̫ǳ��\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("��ĺ������ƻ��̫ǳ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
        int i, level, neili, force;
        level   = (int) me->query_skill("qishang-quan",1);
        force = me->query_skill("force");
        neili = me->query("neili");
        me->delete_temp("qishang_hit", 1);

        if (level > 100 && force > 150 && neili > 500 
            && me->query("max_neili") > 1000
            && me->query("jiali")
            && random(me->query_str()) > 15
            && random(3)>0
            ){
            me->set_temp("qishang_hit", 1);
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 400+random(350),
                   "damage" : 400+random(350),
                   "dodge" : 50+random(100),
                   "damage_type" : random(2)?"����":"����",
                   ]);
            }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

void skill_improved(object me)
{
   object *ob;
   int i, skill;
   skill = me->query_skill("qishang-quan", 1);
   if(me->query("max_neili") < skill*15 && skill < 200){
    switch(random(5)){
      case 0 : 
              tell_object(me, HIR"���ͷ����ѨͻȻһ����΢��ʹ���Ƿ������ˣ�\n"NOR);
              me->add("max_neili", -random(70));
              break;      
      case 1 : 
              tell_object(me, HIR"����������ѨͻȻ��ʹ�ѵ����Ǹ������ˣ�\n"NOR);
              me->add("combat_exp", -random(5000));
              break;
      case 2 : 
              message_vision(HIR"$N�������ˣ�ͻȻ���Դ󷢡��޷������ˣ�\n"NOR, me);
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
                if(!ob[i]->is_fight(me) ) ob[i]->fight_ob(me);
                }
              break;
      case 3 : 
              tell_object(me, HIR"���ϱ�����ѨͻȻһʱ�����ѵ������������ˣ�\n"NOR);
              me->add("max_qi", -random(70));
              break;
      case 4 : 
              tell_object(me, HIR"��ͻȻ�������������������н�ľˮ�������У��޷������ˣ�\n"NOR);
              me->set_skill("qishang-quan", skill-2);
              break;
      }
//     me->unconcious();
     }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{

if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 6 + victim->query_condition("ice_poison"));

    if( damage_bonus < 60 ) return 0;
if (random(me->query_skill("qishang-quan",1)) > 90
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N��һȭ���У����߽���!\n"NOR,victim);
victim->receive_wound("qi", damage_bonus/2 );
}
    if(random(me->query_skill("qishang-quan", 1)) > 50
       && random(me->query("neili")) > 500
       && random(me->query("combat_exp",1)) > victim->query("combat_exp",1)/3 ){
       if(victim->query("neili")/3 < me->query("neili"))
          victim->apply_condition("qishang_poison", 32+victim->query_condition("qishang_poison"));       
       else me->apply_condition("qishang_poison", 31+victim->query_condition("qishang_poison"));
        }
}    

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 80)
		return notify_fail("��ľ����񹦻�򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("����ѹ�ӥצ�����̫ǳ��\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("��ĺ������ƻ��̫ǳ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N��������� ȫ���������������ֳ�һ����͵ľ���! !" +NOR;
 message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}

          
           return j;
}      
