#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

string *parry_msg = ({
        "$n����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"NOR"֮����һ��������$N�ȿ���\n",
        "$n��������黮����������������������"+(order[random(13)])+"�����硹"NOR"֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ��"+(order[random(13)])+"��������"NOR"֮����$NһʱãȻ��֪���ԡ�\n", 
        });

        
string *unarmed_parry_msg = ({
        "$n����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"NOR"֮����һ��������$N�ȿ���\n",
        "$n��������黮����������������������"+(order[random(13)])+"����ǡ�"NOR"֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ��"+(order[random(13)])+"��������"NOR"֮����$NһʱãȻ��֪���ԡ�\n", 
        });
        

mapping *action = ({
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"�����̡�"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               210,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"����ǡ�"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                200,
                "damage":               210,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"��������"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                200,
                "damage":               210,
                "damage_type":  "����"
        ]),        
        
        ([      "action":               "$N��ָ���������󼲷����������̣�����"+(order[random(13)])+"������"NOR"֮����Ϯ��$n��$l",
                "dodge":                180,
                "parry":                20,
                "damage":               270,
                "damage_type":          "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               "$N�������ã�"+(order[random(13)])+"����ǡ�"NOR"��������Χ����ĵ�¡¡����ʮ�����Χ��$n",
                "dodge":                140,
                "parry":                90,
                "damage":               220,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������������ֺ���������"+(order[random(13)])+"�����̡�"NOR"֮�����ޱ�˿�꣬����Ʈ��$n��$l",
                "dodge":                120,
                "parry":                120,
                "damage":               290,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ֱ�ģ��������������ɢ��������������"+(order[random(13)])+"�����̡�"NOR"֮���У�����$n��$l",
                "dodge":                160,
                "parry":                20,
                "damage":               210,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"�����硹"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               210,
                "damage_type":  "����"
        ]),
});        


int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }



int valid_learn(object me)
{
        if (me->query_skill("hand", 1) < 100)
                return notify_fail("��Ļ����ַ�ˮƽ������������������˵�ɣ�\n");

        if (me->query_skill("hamagong", 1) < me->query_skill("xiyu-tiezheng", 1))
                return notify_fail("��ĸ�󡹦ˮƽ���ޣ��޷����������������������\n");

        return 1;
}

int practice_skill(object me)
{
        object ob;



        if ((int)me->query("jing") < 80)
                return notify_fail("��ľ��񲻹��ã�û����ϰ�ˡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("������ʵ����̫ƣ���ˡ�\n");

        me->receive_damage("jing", 55);
        me->receive_damage("qi", 50);

        return 1;
}

void do_effect(object me)
{
        object *obs;
        int lvl;
        int i;
        int damage;

        lvl = me->query_skill("xiyu-tiezheng", 1) / 2 +
              me->query_skill("xiyu-tiezheng", 1);

        if (environment(me)->query("no_fight")
           || lvl < 150)
                return;

        lvl = lvl / 5 + me->query_skill("force");
        lvl /= 2;

        // special effort
        obs = all_inventory(environment(me));
        for (i = 0; i < sizeof(obs); i++)
        {
                if (! obs[i]->is_character() || obs[i] == me || ! living(obs[i]))
                        continue;

                if (me->query_skill("xiyu-tiezheng") * 2 / 3 <
                    obs[i]->query_skill("xiyu-tiezheng"))
                        continue;

                if (lvl + random(lvl) < obs[i]->query_skill("force"))
                {
                        tell_object(obs[i], HIM "���������в���΢΢һ�����������������а���֮����\n" NOR);
                        continue;
                }

                damage = me->query("max_neili") - obs[i]->query("max_neili");
                if (damage < 500)
                {
                        tell_object(obs[i], HIB "���Ȼ����һ�����ܣ���æ����һ�����������ѹ�����\n" NOR);
                        continue;
                }

                damage /= 10;
                //me->want_kill(obs[i]);
                //me->fight_ob(obs[i]);
                //obs[i]->kill_ob(me);
                //obs[i]->receive_damage("jing", damage, me);
                //obs[i]->receive_wound("jing", damage / 3, me);
                tell_object(obs[i], HIB "�������������Ǻ������������ɵ��ĸ����ꡭ��\n" NOR);
        }
}

string perform_action_file(string action)
{
        return __DIR__"xiyu-tiezheng/" + action; 
}


mapping query_action(object me, object weapon)
{
	int i, level;
if (( (int)me->query_skill("hand", 1) >= 120 ) 
        &&	( (int)me->query_skill("xiyu-tiezheng", 1) >= 120 )
	&&      ( (int)me->query("neili") >= 500 )
      && random(8)==0 ) {
		return ([
		"action": HIG"$N����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"HIG"֮����һ����������$n��"NOR,
	                "parry":(int)me->query_skill("parry",1)/3,
	       	       "damage":(int)me->query_skill("music",1)*2,
                 "dodge":(int)me->query_skill("dodge")/10+(int)me->query_skill("leg")/15,
		             "force": (int)me->query_skill("music")+(int)me->query_skill("leg"),
		"damage_type": "����"
  ]);
	}
return action[random(sizeof(action))];
} 
   
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	        string name;
        name = xue_name[random(sizeof(xue_name))];
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xiyu-tiezhang",1);
        level2= (int) me->query_skill("xiyu-tiezhang",1);

if (random(7)==0 && level>=200 && me->query_skill_mapped("force") == "hamagong")
{

        if (!victim->is_busy())
        victim->start_busy(2);
        //me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("xiyu-tiezhang", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("xiyu-tiezhang", 1) / 5 + damage_bonus / 5);
                return HIY "ֻ��һ�����Ǻ���������$N" BLU "��������$n" HIY "��" + name + "��"
                       NOR + BLU "��ʱ��������������ȫ�������Ҵܲ�ֹ��\n" NOR;
}

}