// pixie-jian.c ��а����
// Jay 4/5/96
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *dodge_msg = ({
"ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
"$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
"$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨣�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
});

string  *msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l"NOR"",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�"NOR"",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l"NOR"",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�����Ϯ��"NOR"",
"$N��һ������һ������һ������һ������$n��������������������һת������$n"NOR"",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n"NOR"",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼"NOR"",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��"NOR"",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��"NOR"",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������"NOR"",
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ"NOR"",
"$N��Ȼ����Ϊ�����ó�����������Ӱ���ٻ���$n������$w�û����������н���$n��$l"NOR"",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪"NOR"",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l"NOR"",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����"NOR"",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��"NOR"",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��"NOR"",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��"NOR"",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"NOR""
});


mapping *action = ({
([  "action":"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
    "force" : 100,
    "dodge" : 40,
    "damage": 240,
    "lvl" : 0,
    "skill_name" : "��Ӱ����",
    "damage_type":  "����"
]),
([  "action":"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",    
    "force" : 120,
    "dodge" : 30,
    "damage": 250,
    "lvl" : 0,
    "skill_name" : "�Լ�С��",
    "damage_type":  "����"
]),
([  "action":"�����$N�����ϣ��ڵ�$n�������Ծ��ԭ��",
    "force" : 125,
    "dodge" : 60,
    "damage": 270,
    "lvl" : 25,
    "skill_name" : "������",
    "damage_type":  "����"
]),
([  "action":"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������",
    "force" : 130,
    "dodge" : 40,
    "damage": 200,
    "lvl" : 5,
    "skill_name" : "�з�һ��",
    "damage_type":  "����"
]),
([  "action":"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ���$n�����",
    "force" : 140,
    "dodge" : 40,
    "damage": 250,
    "lvl" : 10,
    "skill_name" : "�������",
    "damage_type":  "����"
]),
([  "action":"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
    "force" : 160,
    "dodge" : 5,
    "damage": 260,
    "lvl" : 10,
    "skill_name" : "������ǰ",
    "damage_type":  "����"
]),
([  "action":"$N�ȵ������ã������㼴�γ�$w�����ִ̳�������ת����ȥ",
    "force" : 300,
    "dodge" : 30,
    "damage": 250,
    "lvl" : 0,
    "skill_name" : "���ִ̳�",
    "damage_type":  "����"
]),
([  "action":"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
    "force" : 490,
    "dodge" : 80,
    "damage": 270,
    "lvl" : 20,
    "skill_name" : "��ǰһ��",
    "damage_type":  "����"
]),
([  "action":"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ������$wֱָ$n��$l",
    "force" : 480,
    "dodge" : 10,
    "damage": 400,
    "lvl" : 5,
    "skill_name" : "�����",
    "damage_type":  "����"
]),
([  "action":"$N��س嵽$n��ǰ������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
    "force" : 350,
    "dodge" : 4,
    "damage": 450,
    "lvl" : 45,
    "skill_name" : "ֱ������",
    "damage_type":  "����"
]),
([  "action":"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l",
    "force" : 340,
    "dodge" : 20,
    "damage": 375,
    "lvl" : 64,
    "skill_name" : "����Ծ��",
    "damage_type":  "����"
]),
([  "action":"$N��֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
    "force" : 500,
    "dodge" : 60,
    "damage": 500,
    "lvl" : 79,
    "skill_name" : "��֦�Ͱ�",
    "damage_type":  "����"
]),
});


int valid_enable(string usage)
{
    return usage == "sword" || usage == "dodge" || usage == "parry";
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
        level   = (int) me->query_skill("pixie-jian",1);
        force = me->query_skill("force");
        neili = me->query("neili");

        if (level > 120 && force > 180 && neili > 300 
            && me->query("max_neili") > 1200
            && random(me->query_dex()) > 25
            ){
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : force+random(force),
                   "dodge" : 70+random(60),
                   "parry" : 70+random(60),
                   "damage": 180+me->query_temp("cimu")?force+random(force):force,
                   "damage_type" : "����",
                   ]);
            }
           for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
	int level, jiali, time,level2,damage,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "����" + weapon->name();
        else
	        name = "˫��";
if (random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{

	        message_vision(HIW "\n��ʱ��ֻ��$N" HIW "�����Ͱڣ���ʱ����Ϊ������Ӱ��" + name +
        	               HIW "\n�������ǰ�ִӲ�ͬ�ķ�λͬʱ����$n" HIW "��\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}

   weapon = me->query_temp("weapon");
if (!weapon) return;
if (weapon)
{
   if( random(me->query_str()) > victim->query_str()/2){
	victim->receive_wound("qi", me->query_str()+random(100));
	return HIR "ֻ�����͡�һ����һ��Ѫ˿��"+victim->name()+"���̵���״������\n" NOR;
	}
}
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "һ����Ц! ���Ǵ�!! " HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    object ob;

    if ( (string)me->query("gender")=="Ů��" )
        return notify_fail("Ů�Ӳ���ѧ��а����.\n");

   if ( (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�,��������а����.\n");

    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취����а������\n");

    return 1;
//    return notify_fail("��а����ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
}


int practice_skill(object me)
{
    if( (int)me->query("qi") < 50
    ||  (int)me->query("neili") < 55 )
       return notify_fail("�����������������û�а취��ϰ��а������\n");
    if ( (string)me->query("gender")=="Ů��" )
        return notify_fail("Ů�Ӳ���ѧ��а����.\n");

   if ( (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�,��������а����.\n");

    me->receive_damage("qi", 30);
    me->add("neili", -15);
    //write("�㰴����ѧ����һ���а������\n");
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"pixie-jian/" + action;
}

