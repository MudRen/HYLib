// wudang-mianzhang.c �䵱����
// By lius 99/8

#include <ansi.h>
inherit SKILL;
string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;
	sz = sizeof(enemy);
//if (!environment(me)) return 0;
//if (!environment(sz)) return 0;
//if (environment(me)!= environment(sz)) return 0;

	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
#include "/kungfu/skill/eff_msg.h";
int taiji(object me, object victim);

mapping *action = ({
([	"action":"$Nһ�����ݲ����ѵ�$n�Ҽ�֮�࣬����һ��[����]������Ҹ��ȥ��",
	"force" : 160,
	"dodge" : 10,
	"parry" : 110,
	"lvl" : 0,
	"skill_name" : "����",
	"damage_type":"����"
]),
([	"action":"$N����һ����һ��[ӡ��]���Ʒ��Ȼ��ֱ��$nǰ��",
	"force" : 180,
	"dodge" : 50,
	"parry" : 110,
	"lvl" : 20,
	"skill_name" : "ӡ��",
	"damage_type":"����"
]),
([	"action":"$N��̤���֣�˫��΢�Σ�˫����ƮƮ�أ�[��������]���Ļ�������",
	"force" : 200,
	"dodge" : 15,
	"parry" : 110,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N����б�������ƴ�������г��������ϻ���һʽ[�����н�]ֱ��$n����ؽڡ�",
	"force" : 210,
	"dodge" : 5,
	"parry" : 115,
	"lvl" : 40,
	"skill_name" : "�����н�",
	"damage_type":"����"
]),
([	"action":"$N������ָ�ɹ���һ�¹�ס$n�������ţ������´����������Ƴɵ����϶��»��䣬
ȴ��һ��[���۶���]����",
	"force" : 230,
	"dodge" : 0,
	"parry" : 115,
	"lvl" : 60,
	"skill_name" : "���۶���",
	"damage_type":"����"
]),
([	"action":"$Nʹ��[���Ƽ���]��˫����������ԲȦ����ȥ$n�ľ��������ƴ���Ȧͻ������Է�ǰ�أ�
����ȴ��Ʈ�İ���Է�����ҪѨ��",
	"force" : 270,
		  "dodge" : 55,
		  "parry" : 150,
	"lvl" : 80,
	"skill_name" : "���Ƽ���",
	"damage_type":"����"
]),
([	"action":"$Nһʽ�����ҷ�Դ����˫��������ϣ���$n����������һ�ԣ�ͻȻŤ�����磬˫�����У�
��������ǧ����ַ�����$n˶��������еķ��˳�ȥ��",
	"force" : 290,
	"dodge" : 0,
	"parry" : 110,
	"lvl" : 100,
	"skill_name" : "���ҷ�Դ",
	"damage_type":"����"
]),
([	"action":"$N����Ծ���������ӣ�����ȴ������Ϣ���������ƣ���һʽ[���ϸ��]��$n���������棬
Ǳ��������ӿ������",
	"force" : 300,
		  "dodge" : 15,
		  "parry" : 110,
	"lvl" : 110,
	"skill_name" : "���ϸ��",
	"damage_type":"����"
]),
([	"action":"$Nһʽ��ħ�����ǡ���˫�ŵ���Ծ��$nͷ��������һ�ϣ�˳���°�������Է�ͷ���ٻ�Ѩ��",
	"force" : 320,
	"dodge" : 5,
	"parry" : 115,
	"lvl" : 120,
	"skill_name" : "ħ������",
	"damage_type":"����"
]),
([	"action":"$N����ɢ�ң�����[���岻��]��ȴ�������ǣ���һ������һ�ƣ����в���$n����Ҫ����",
	"force" : 340,
	"dodge" : 15,
	"parry" : 110,
	"lvl" : 130,
	"skill_name" : "���岻��",
	"damage_type":"����"
]),
([	"action":"$Nһ��[��������]�����ֻ����ͻ�$n�Ҽգ����ֳ�ָ��������硰ȱ��Ѩ����",
	"force" : 360,
	"dodge" : 10,
	"parry" : 115,
	"lvl" : 140,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$Nһ��[��������]�����ֻ����ͻ�$n��գ����ֳ�ָ�������Ҽ硰ȱ��Ѩ����",
	"force" : 380,
	"dodge" : 15,
	"parry" : 115,
	"lvl" : 145,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N�ҽ��߳�����Ž��Ƶ���һ�ε���$n�����ƮƮ��һʽ[����Ұ��]�����ư�
������������ҪѨ��",
	"force" : 400,
	"dodge" : 10,
	"parry" : 110,
	"lvl" : 150,
	"skill_name" : "����Ұ��",
	"damage_type":"����"
]),
([	"action":"$Nʹ��[��Ʈѩ��]��˫�Ʒ��裬������Ʈѩ������಻��������",
	"force" : 420,
	"dodge" : 0,
	"parry" : 115,
	"lvl" : 160,
	"skill_name" : "��Ʈѩ��",
	"damage_type":"����"
]),
([	"action":"$NͻȻ�����ֱַ�ʹ��[��������]��������ʽ�����籩�������Ϯ��$n,
�Ƶ�֮�ͣ��ַ�֮�죬�����ͬС�ɡ�",
	"force" : 450,
	"dodge" : 10,
	"parry" : 110,
	"lvl" : 170,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$NͻȻһ�����Ƴ�̬�������������У���֮�����������[һ��Ǭ��]���ھ�
���£��ͻ�$n��$l����һ���������࣬���ʤ����",
	"force" : 480,
	"dodge" : 10,
	"parry" : 110,
	"lvl" : 180,
	"skill_name" : "һ��Ǭ��",
	"damage_type":"����"
]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry" ||  usage=="unarmed"; }

int valid_learn(object me)
{
    mapping fam  = me->query("family");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����Ʊ�����֡�\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 80)
        return notify_fail("��ı����ڹ���򲻹����޷�ѧϰ���ơ�\n");
    if ((int)me->query("max_neili") < 450)
        return notify_fail("�������̫�����޷���ϰ���ơ�\n");
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
    int i, j, level;
    object target; 
    level = (int) me->query_skill("wudang-mianzhang",1);

    if (random(me->query_con()) > 30 && random(4) == 3 &&
        level > 120 && me->query("neili") > 500){   
           me->add("neili", -50);    
              return ([
                "action": YEL"$NͻȻ��ȭΪ�ƣ��䲻�ݷ��ز���$n�ķ��ߣ�������Ϣ�ĳ�һ�ƣ�
�������ᣬȴ�ǰ������̣��˵ķ�ͬС�ɣ���"NOR,
                "damage" : 500,
                "force" : 500,
                "dodge" : 10,
                "damage_type" : "����",                           
                ]); 
        }         
     for(i = sizeof(action); i > 0; i--) {
         if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
            target = offensive_target(me);            {                
                    return ([  
                    "action" : action[j]["action"],
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "lvl" : action[j]["lvl"],
                    "damage_type" : action[j]["damage_type"],
                    ]);
               }
            return action[j];
            }
         }
}

int practice_skill(object me)
{
    int lvl = me->query_skill("wudang-mianzhang", 1);
    //int i = sizeof(action);
    //while (i--) if (lvl == action[i]["lvl"]) return 0;
    if ((int)me->query("jing") < 40)
        return notify_fail("�㾫��̫��޷���ϰ���ơ�\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("����������������ơ�\n");
    me->receive_damage("jing", 30);
    me->add("neili", -10);
    return 1;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        wp1 = ob->query_temp("weapon");
        
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("wudang-mianzhang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N �籧̫����һ���ۻ��ޱȵ����������һ����������\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"������ ��̫���񹦽������� �������Լ����� ��\n"NOR;
//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}    
      if(me->query_temp("fanzhen")){
      	 me->delete_temp("fanzhen");
         return 1;
         }
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "wudang-mianzhang"
         && me->query_skill("taiji-shengong", 1) > 80
         && neili > 100 
         && skill > 50 
         && living(me)
         && random(5) >= 2)
         {         
         if(random(5) < 2 ) me->set_temp("fanzhen", 1);   
         if(wp1) msg = "$N˫�ֲ��в��ܣ�ֻ�ǽ�����$n��"+wp1->name()+"��һ�У�һ����";
         else msg = "$N����������˫�ַ��裬�����಻��������";
         if(neili >= neili1 + damage){
              msg += "���$Nһ��$n���������ϣ���ͻ���ྡྷ��$n����������������\n",              
              ob->receive_damage("qi", damage/2+ob->query("jiali"), me);
              ob->receive_wound("qi", ob->query("jiali"), me);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/2+random(neili1/2)+random(damage)){
            msg += "���$n������������޲����������������֮����\n", 
              j = -8000;
              }
           else if(neili > neili1/2+damage){
              msg += "���$n��������$Nʹ���ྡྷ��ѧж����һ���֣�\n", 
              j = -(damage/3+random(damage));               
              }
           else{
              msg += "���$n��������$Nʹ���ྡྷ��ѧж����һС�룡\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}

string perform_action_file(string action)
{
    return __DIR__"wudang-mianzhang/" + action;
}

